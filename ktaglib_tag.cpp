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

zend_class_entry * ktaglib_ce_Tag = NULL;

PHP_METHOD(KTaglib_Tag, getTitle)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	/*
               RETURN_STRING( xyz, 1 ); tells the engine to take a copy of the string
               so it can nuke it when it needs to. Previously the string was duplicated
               twice using strdup and then giving 1 as second parameter to RETURN_STRING
	*/
	char* str = estrdup((char*) ((TagLib::Tag*) intern->tag)->title().toCString());
	RETURN_STRING(str, 0);
}

PHP_METHOD(KTaglib_Tag, getArtist)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	char* str = estrdup((char*) ((TagLib::Tag*) intern->tag)->artist().toCString());
	RETURN_STRING(str, 0);
}

PHP_METHOD(KTaglib_Tag, getAlbum)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	char* str = estrdup((char*) ((TagLib::Tag*) intern->tag)->album().toCString());
	RETURN_STRING(str, 0);
}

PHP_METHOD(KTaglib_Tag, getComment)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	char* str = estrdup((char*) ((TagLib::Tag*) intern->tag)->comment().toCString());
	RETURN_STRING(str, 0);
}

PHP_METHOD(KTaglib_Tag, getGenre)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	char* str = estrdup((char*) ((TagLib::Tag*) intern->tag)->genre().toCString());
	RETURN_STRING(str, 0);
}

PHP_METHOD(KTaglib_Tag, getYear)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_LONG(((TagLib::Tag*) intern->tag)->year());
}

PHP_METHOD(KTaglib_Tag, getTrack)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	RETURN_LONG(((TagLib::Tag*) intern->tag)->track());
}

PHP_METHOD(KTaglib_Tag, setTitle)
{
	int filename_len;
	char * filename;
	ze_ktaglib_object * intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Tag*)intern->tag)->setTitle(filename);
}

PHP_METHOD(KTaglib_Tag, setArtist)
{
	int filename_len;
	char * filename;
	ze_ktaglib_object * intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Tag*)intern->tag)->setArtist(filename);
}

PHP_METHOD(KTaglib_Tag, setAlbum)
{
	int filename_len;
	char * filename;
	ze_ktaglib_object * intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Tag*)intern->tag)->setAlbum(filename);
}

PHP_METHOD(KTaglib_Tag, setComment)
{
	int filename_len;
	char * filename;
	ze_ktaglib_object * intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Tag*)intern->tag)->setComment(filename);
}

PHP_METHOD(KTaglib_Tag, setGenre)
{
	int filename_len;
	char * filename;
	ze_ktaglib_object * intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Tag*)intern->tag)->setGenre(filename);
}

PHP_METHOD(KTaglib_Tag, setYear)
{
	int year;
	ze_ktaglib_object * intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &year) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Tag*)intern->tag)->setYear(year);
}

PHP_METHOD(KTaglib_Tag, setTrack)
{
	int year;
	ze_ktaglib_object * intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &year) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	((TagLib::Tag*)intern->tag)->setTrack(year);
}

PHP_METHOD(KTaglib_Tag, isEmpty)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	if (((TagLib::Tag*) intern->tag)->isEmpty()) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}

PHP_METHOD(KTaglib_Tag, __construct)
{
}

static zend_function_entry KTaglib_Tag_methods[] = {
	PHP_ME(KTaglib_Tag, __construct, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(KTaglib_Tag, getTitle,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, getArtist,   NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, getAlbum,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, getComment,  NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, getGenre,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, getYear,     NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, getTrack,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, setTitle,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, setArtist,   NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, setAlbum,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, setComment,  NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, setGenre,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, setYear,     NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, setTrack,    NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Tag, isEmpty,     NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void ktaglib_init_KTaglib_Tag(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "KTaglib_Tag", KTaglib_Tag_methods);
	ce.create_object = ktaglib_init_KTaglib_new;
	ktaglib_ce_Tag = zend_register_internal_class(&ce TSRMLS_CC);
}

