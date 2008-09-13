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

zend_class_entry * ktaglib_ce_ID3v2_Tag = NULL;

PHP_METHOD(KTaglib_ID3v2_Tag, getFrameList)
{
	ze_ktaglib_object *intern = NULL;
	ze_ktaglib_object *zobject = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	array_init(return_value);

	zval* obj;
	TagLib::ID3v2::FrameListMap map = ((TagLib::ID3v2::Tag *) intern->tag)->frameListMap();
	TagLib::ID3v2::FrameListMap::ConstIterator iter;
	for (iter = map.begin() ; iter != map.end() ; iter++) {
		MAKE_STD_ZVAL(obj);

		char* key = (char*)iter->first.data();
		key[iter->first.size()] = '\0';

		TagLib::ID3v2::Frame* f = (TagLib::ID3v2::Frame*)iter->second.front();
		if (f->frameID() == "APIC") {
			object_init_ex(obj, ktaglib_ce_ID3v2_PictureFrame);
		} else if (f->frameID() == "COMM") {
			object_init_ex(obj, ktaglib_ce_ID3v2_CommentsFrame);
		} else {
			object_init_ex(obj, ktaglib_ce_ID3v2_Frame);
		}
		zobject = (ze_ktaglib_object*) zend_object_store_get_object(obj TSRMLS_CC);
		zobject->frame = (TagLib::ID3v2::Frame*) iter->second.front();
		ktaglib_ref_class(zobject, intern->zo_file);
		add_assoc_zval(return_value, key, obj);
	}
}

PHP_METHOD(KTaglib_ID3v2_Tag, addFrame)
{
	zval* frame;
	ze_ktaglib_object *zobject = NULL;
	ze_ktaglib_object *intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &frame) == FAILURE) {
		return;
	}

	intern	= (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	zobject = (ze_ktaglib_object*) zend_object_store_get_object(frame TSRMLS_CC);

	if (!zobject || !zobject->frame) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "First parameter must be a valid frame object");
		RETURN_FALSE;
	}

	((TagLib::ID3v2::Tag *) intern->tag)->addFrame(zobject->frame);
	ktaglib_ref_class(zobject, intern->zo_file);
}

static zend_function_entry KTaglib_ID3v2_Tag_methods[] = {
	PHP_ME(KTaglib_ID3v2_Tag, addFrame, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_Tag, getFrameList, NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void ktaglib_init_KTaglib_ID3v2_Tag(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "KTaglib_ID3v2_Tag", KTaglib_ID3v2_Tag_methods);
	ce.create_object = ktaglib_init_KTaglib_new;
	ktaglib_ce_ID3v2_Tag = zend_register_internal_class_ex(&ce, ktaglib_ce_Tag, NULL TSRMLS_CC);
}
