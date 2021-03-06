/*
   +----------------------------------------------------------------------+
   | All rights reserved                                                  |
   |                                                                      |
   | Redistribution and use in source and binary forms, with or without   |
   | modification, are permitted provided that the following conditions   |
   | are met:                                                             |
   |                                                                      |
   | 1. Redistributions of source code must retain the above copyright    |
   |    notice, this list of conditions and the following disclaimer.     |
   | 2. Redistributions in binary form must reproduce the above copyright |
   |    notice, this list of conditions and the following disclaimer in   |
   |    the documentation and/or other materials provided with the        |
   |    distribution.                                                     |
   |                                                                      |
   | THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  |
   | "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT    |
   | LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS    |
   | FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE       |
   | COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  |
   | INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, |
   | BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;     |
   | LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER     |
   | CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   |
   | LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN    | 
   | ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE      |
   | POSSIBILITY OF SUCH DAMAGE.                                          |
   +----------------------------------------------------------------------+
   | Authors: David Soria Parra <dsp@php.net>                             |
   +----------------------------------------------------------------------+
*/

#include "php_ktaglib.h"
#include "ktaglibrary.h"

PHPAPI zend_class_entry * ktaglib_ce_ID3v2_PictureFrame = NULL;

static
ZEND_BEGIN_ARG_INFO_EX(KTaglib_ID3v2_AttachedPictureFrame_savePicture_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

PHP_METHOD(KTaglib_ID3v2_AttachedPictureFrame, getDescription)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	RETURN_STRING((char*) ((TagLib::ID3v2::AttachedPictureFrame *)intern->frame)->description().toCString(), 1);
}

PHP_METHOD(KTaglib_ID3v2_AttachedPictureFrame, getMimeType)
{
	ze_ktaglib_object *intern = NULL;
	
	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	
	RETURN_STRING((char*) ((TagLib::ID3v2::AttachedPictureFrame *)intern->frame)->mimeType().toCString(), 1);
}

PHP_METHOD(KTaglib_ID3v2_AttachedPictureFrame, savePicture)
{
	char * filename = NULL;
	int filename_len = 0;
	php_stream * stream;
	TagLib::ByteVector buf;
	ze_ktaglib_object *intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}
	
	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	stream = php_stream_open_wrapper(filename, "w+", ENFORCE_SAFE_MODE | REPORT_ERRORS, NULL);
	if (!stream) {
		RETURN_FALSE;
	}

	buf = ((TagLib::ID3v2::AttachedPictureFrame *)intern->frame)->picture();

	php_stream_write(stream, (char*) buf.data(), buf.size());
	
	php_stream_close(stream);
	RETURN_TRUE;
}

static zend_function_entry KTaglib_ID3v2_AttachedPictureFrame_methods[] = {
	PHP_ME(KTaglib_ID3v2_AttachedPictureFrame, getMimeType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_AttachedPictureFrame, getDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_AttachedPictureFrame, savePicture, KTaglib_ID3v2_AttachedPictureFrame_savePicture_args, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void ktaglib_init_KTaglib_ID3v2_PictureFrame(void)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "KTaglib_ID3v2_AttachedPictureFrame", KTaglib_ID3v2_AttachedPictureFrame_methods);
	ce.create_object = ktaglib_init_KTaglib_new;
	ktaglib_ce_ID3v2_PictureFrame = zend_register_internal_class_ex(&ce, ktaglib_ce_ID3v2_Frame, NULL TSRMLS_CC);
}
