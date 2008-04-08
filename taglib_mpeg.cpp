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

#include "php_taglib.h"
#include "taglibrary.h"

PHPAPI zend_class_entry * taglib_ce_MPEG_File = NULL;

static
ZEND_BEGIN_ARG_INFO_EX(TagLib_MPEG_File___construct_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

/*       {{{ Methods */
PHP_METHOD(TagLib_MPEG_File, __construct)
{
	ze_taglib_object *intern = NULL;
	const char * filename = NULL;
	int filename_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	if (filename_len == 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Empty string as source");
		RETURN_FALSE;
	}	

	if (PG(safe_mode) && (!php_checkuid(filename, NULL, CHECKUID_CHECK_FILE_AND_DIR))) {
		RETURN_FALSE;
	}

	if (php_check_open_basedir(filename TSRMLS_CC)) {
		RETURN_FALSE;
	}
	
	intern->file = new TagLib::MPEG::File(filename);

	if (!intern->file->isValid()) {
		zend_throw_exception(taglib_ce_FileNotFoundException, "File not found", 0 TSRMLS_CC);
	}
}

PHP_METHOD(TagLib_MPEG_File, getID3v1Tag)
{
	ze_taglib_object *intern = NULL;
	const char * filename = NULL;
	int filename_len = 0;

	TagLib::MPEG::File *file;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	file   = (TagLib::MPEG::File*) intern->file;
	if (file->ID3v1Tag()) {
		/* initialize the zend object and 
		   set the internal ->tag pointer to the tag object
		   returned by TagLib::MPEG::File::ID3v1Tag()
		   We don't have to call a constructor here as TagLib_MPEG_Tag doesn't have one
		*/
		object_init_ex(return_value, taglib_ce_ID3v1_Tag TSRMLS_CC);
		intern = (ze_taglib_object*) zend_object_store_get_object(return_value TSRMLS_CC);
		intern->tag = file->ID3v1Tag();
		return;
	}

	zend_throw_exception(taglib_ce_TagNotFoundException, "No ID3v1 Tag found", 0 TSRMLS_CC);
}

PHP_METHOD(TagLib_MPEG_File, getID3v2Tag)
{
	ze_taglib_object *intern = NULL;

	TagLib::MPEG::File *file;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	file   = (TagLib::MPEG::File*) intern->file;
	if (file->ID3v2Tag()) {
		object_init_ex(return_value, taglib_ce_ID3v2_Tag TSRMLS_CC);
		intern = (ze_taglib_object*) zend_object_store_get_object(return_value TSRMLS_CC);
		intern->tag = file->ID3v2Tag();
		return;
	}

	zend_throw_exception(taglib_ce_TagNotFoundException, "No ID3v2 Tag found", 0 TSRMLS_CC);
}

static zend_function_entry TagLib_File_MPEG_methods[] = {
	PHP_ME(TagLib_MPEG_File, __construct, TagLib_MPEG_File___construct_args, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_MPEG_File, getID3v1Tag, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_MPEG_File, getID3v2Tag, NULL, /**/ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void taglib_init_TagLib_MPEG_File(void)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "TagLib_MPEG_File", TagLib_File_MPEG_methods);
	ce.create_object = taglib_init_TagLib_File_new;
	taglib_ce_MPEG_File = zend_register_internal_class(&ce);
}

