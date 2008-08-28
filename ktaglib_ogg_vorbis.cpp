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
   |          Anatoliy Belsky <a@belsky.info>                             |
   +----------------------------------------------------------------------+
*/
#include "php_ktaglib.h"
#include "ktaglibrary.h"

zend_class_entry *ktaglib_ce_Ogg_Vorbis_File = NULL;

static ZEND_BEGIN_ARG_INFO_EX(KTaglib_Ogg_Vorbis_File___construct_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

PHP_METHOD(KTaglib_Ogg_Vorbis_File, __construct)
{
	ze_ktaglib_file_object *intern = NULL;
	const char * filename = NULL;
	int filename_len = 0;
	struct stat sb;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_file_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	if (filename_len == 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Empty string as source");
		RETURN_FALSE;
	}

	if (PG(safe_mode) && (!php_checkuid(filename, NULL, CHECKUID_CHECK_FILE_AND_DIR))) {
		RETURN_FALSE;
	}

	if (VCWD_STAT(filename, &sb) != 0) {
		zend_throw_exception(ktaglib_ce_FileNotFoundException, "File not found", 0 TSRMLS_CC);
		return;
	}

	if (php_check_open_basedir(filename TSRMLS_CC)) {
		RETURN_FALSE;
	}

	/**
	 * TODO pack file initializations in a function
	 */
	try {
		intern->file = new TagLib::Ogg::Vorbis::File(filename);
	} catch(bad_alloc xa) {
		zend_throw_exception(ktaglib_ce_BadAllocException, "Cannot allocate memory", 0 TSRMLS_CC);
		return;
	}

	if (!intern->file->isValid()) {
		zend_throw_exception(ktaglib_ce_FileNotFoundException, "File not found", 0 TSRMLS_CC);
	}
}

PHP_METHOD(KTaglib_Ogg_Vorbis_File, getAudioProperties)
{
	ze_ktaglib_file_object *intern = NULL;
	ze_ktaglib_object *nintern = NULL;

	intern = (ze_ktaglib_file_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->file;

	if (file->audioProperties()) {
		object_init_ex(return_value, ktaglib_ce_Ogg_Vorbis_AudioProperties);
		nintern = (ze_ktaglib_object*) zend_object_store_get_object(return_value TSRMLS_CC);
		ktaglib_ref_class(nintern, intern);
		return;
	}

	RETURN_FALSE;
}

PHP_METHOD(KTaglib_Ogg_Vorbis_File, getTag)
{
	ze_ktaglib_file_object *intern = NULL;
	ze_ktaglib_object *nintern = NULL;

	intern = (ze_ktaglib_file_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->file;

	if (file->audioProperties()) {
		object_init_ex(return_value, ktaglib_ce_Ogg_Tag);
		nintern = (ze_ktaglib_object*) zend_object_store_get_object(return_value TSRMLS_CC);
		ktaglib_ref_class(nintern, intern);
		return;
	}

	RETURN_FALSE;
}

PHP_METHOD(KTaglib_Ogg_Vorbis_File, save)
{
	ze_ktaglib_file_object *intern = NULL;

	intern = (ze_ktaglib_file_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Ogg::Vorbis::File*) intern->file)->save();
}

static zend_function_entry KTaglib_File_Ogg_Vorbis_methods[] = {
	PHP_ME(KTaglib_Ogg_Vorbis_File, __construct, KTaglib_Ogg_Vorbis_File___construct_args, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Vorbis_File, getAudioProperties, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Vorbis_File, getTag, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Vorbis_File, save, NULL, ZEND_ACC_PUBLIC)
    { NULL, NULL, NULL }
};

void ktaglib_init_KTaglib_Ogg_Vorbis_File(TSRMLS_D)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "KTaglib_Ogg_Vorbis_File", KTaglib_File_Ogg_Vorbis_methods);
    ce.create_object = ktaglib_init_KTaglib_File_new;
    ktaglib_ce_Ogg_Vorbis_File = zend_register_internal_class(&ce TSRMLS_CC);
}
