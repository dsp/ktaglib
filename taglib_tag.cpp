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

PHPAPI zend_class_entry * taglib_ce_Tag = NULL;

PHP_METHOD(TagLib_Tag, getTitle)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_STRING((char*) ((TagLib::Tag*) intern->tag)->title().toCString(), 1);
}

PHP_METHOD(TagLib_Tag, getArtist)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_STRING((char*) ((TagLib::Tag*) intern->tag)->artist().toCString(), 1);
}

PHP_METHOD(TagLib_Tag, getAlbum)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_STRING((char*) ((TagLib::Tag*) intern->tag)->album().toCString(), 1);
}

PHP_METHOD(TagLib_Tag, getComment)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_STRING((char*) ((TagLib::Tag*) intern->tag)->comment().toCString(), 1);
}

PHP_METHOD(TagLib_Tag, getGenre)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_STRING((char*) ((TagLib::Tag*) intern->tag)->genre().toCString(), 1);
}

PHP_METHOD(TagLib_Tag, getYear)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_LONG(((TagLib::Tag*) intern->tag)->year());
}

PHP_METHOD(TagLib_Tag, getTrack)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_LONG(((TagLib::Tag*) intern->tag)->track());
}

PHP_METHOD(TagLib_Tag, isEmpty)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	if (((TagLib::Tag*) intern->tag)->isEmpty()) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}

PHP_METHOD(TagLib_Tag, __construct)
{
}

static zend_function_entry TagLib_Tag_methods[] = {
	PHP_ME(TagLib_Tag, __construct, NULL, /**/ZEND_ACC_PRIVATE)
	PHP_ME(TagLib_Tag, getTitle, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_Tag, getArtist, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_Tag, getAlbum, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_Tag, getComment, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_Tag, getGenre, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_Tag, getYear, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_Tag, getTrack, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(TagLib_Tag, isEmpty, NULL, /**/ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void taglib_init_TagLib_Tag(void)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "TagLib_Tag", TagLib_Tag_methods);
	ce.create_object = taglib_init_TagLib_File_new;
	taglib_ce_Tag = zend_register_internal_class(&ce);
}

