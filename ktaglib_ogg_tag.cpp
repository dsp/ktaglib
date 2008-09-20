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
   |          Anatoliy Belsky <ab@php.net>                                |
   +----------------------------------------------------------------------+
*/

#include "php_ktaglib.h"
#include "ktaglibrary.h"

zend_class_entry *ktaglib_ce_Ogg_Tag = NULL;

PHP_METHOD(KTaglib_Ogg_Tag, getTitle)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_STRING((char*) file->tag()->title().toCString(), 1);
}

PHP_METHOD(KTaglib_Ogg_Tag, setTitle)
{
	ze_ktaglib_object *intern = NULL;
	char *text;
	int text_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->setTitle(text);

}

PHP_METHOD(KTaglib_Ogg_Tag, getArtist)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_STRING((char*) file->tag()->artist().toCString(), 1);
}

PHP_METHOD(KTaglib_Ogg_Tag, setArtist)
{
	ze_ktaglib_object *intern = NULL;
	char *text;
	int text_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->setArtist(text);

}

PHP_METHOD(KTaglib_Ogg_Tag, getAlbum)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_STRING((char*) file->tag()->album().toCString(), 1);
}

PHP_METHOD(KTaglib_Ogg_Tag, setAlbum)
{
	ze_ktaglib_object *intern = NULL;
	char *text;
	int text_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->setAlbum(text);

}

PHP_METHOD(KTaglib_Ogg_Tag, getComment)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_STRING((char*) file->tag()->comment().toCString(), 1);
}

PHP_METHOD(KTaglib_Ogg_Tag, setComment)
{
	ze_ktaglib_object *intern = NULL;
	char *text;
	int text_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->setComment(text);

}

PHP_METHOD(KTaglib_Ogg_Tag, getGenre)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_STRING((char*) file->tag()->genre().toCString(), 1);
}

PHP_METHOD(KTaglib_Ogg_Tag, setGenre)
{
	ze_ktaglib_object *intern = NULL;
	char *text;
	int text_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->setGenre(text);

}

PHP_METHOD(KTaglib_Ogg_Tag, getTrack)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETURN_LONG((long) file->tag()->track());
}

PHP_METHOD(KTaglib_Ogg_Tag, setTrack)
{
	ze_ktaglib_object *intern = NULL;
	long num;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &num) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->setTrack((uint) num);

}

PHP_METHOD(KTaglib_Ogg_Tag, getYear)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETURN_LONG((long) file->tag()->year());
}

PHP_METHOD(KTaglib_Ogg_Tag, setYear)
{
	ze_ktaglib_object *intern = NULL;
	long num;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &num) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->setYear((uint) num);

}

PHP_METHOD(KTaglib_Ogg_Tag, isEmpty)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_BOOL((zend_bool) file->tag()->isEmpty());
}

PHP_METHOD(KTaglib_Ogg_Tag, addField)
{
	ze_ktaglib_object *intern = NULL;
	char *key, *value;
	long key_len, value_len;
	zend_bool replace = 1;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|b", &key, &key_len, &value, &value_len, &replace) == FAILURE) {
		return;
	}

	/**
	 * key gets automatically converted to uppercase
	 * by taglib itself
	 */

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->addField(key, value, replace);
}

PHP_METHOD(KTaglib_Ogg_Tag, getVendorId)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_STRING((char*) file->tag()->vendorID().toCString(), 1);
}

PHP_METHOD(KTaglib_Ogg_Tag, removeField)
{
	ze_ktaglib_object *intern = NULL;
	char *key, *value = NULL;
	int key_len, value_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s", &key, &key_len, &value, &value_len) == FAILURE) {
		return;
	}

	/**
	 * Must be uppercase because of convention
	 */
	php_strtoupper(key, key_len);

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	file->tag()->removeField(key, value_len ? value : TagLib::String::null);
}

PHP_METHOD(KTaglib_Ogg_Tag, contains)
{
	ze_ktaglib_object *intern = NULL;
	char *key;
	int key_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &key, &key_len) == FAILURE) {
		return;
	}

	/**
	 * Must be uppercase because of convention
	 */
	php_strtoupper(key, key_len);

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETVAL_BOOL(file->tag()->contains(key));
}

PHP_METHOD(KTaglib_Ogg_Tag, getField)
{
	ze_ktaglib_object *intern = NULL;
	char *key;
	int key_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &key, &key_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	/**
	 * Must be uppercase because of convention
	 */
	php_strtoupper(key, key_len);

	if(file->tag()->contains(key)) {
		TagLib::Ogg::FieldListMap fields = file->tag()->fieldListMap();

		RETVAL_STRING((char*) fields[key].front().toCString(), 1);

		return;
	}

	RETURN_NULL();
}

PHP_METHOD(KTaglib_Ogg_Tag, fieldCount)
{
	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	RETURN_LONG((long) file->tag()->fieldCount());
}


PHP_METHOD(KTaglib_Ogg_Tag, getTagList)
{
	array_init(return_value);

	ze_ktaglib_object *intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	TagLib::Ogg::Vorbis::File *file = (TagLib::Ogg::Vorbis::File*) intern->zo_file->file;

	TagLib::Ogg::FieldListMap fields = file->tag()->fieldListMap();
	TagLib::Ogg::FieldListMap::ConstIterator it = fields.begin();

	while(it != fields.end()) {
		if(!(*it).second.isEmpty()) {
			zval *value;
			ALLOC_INIT_ZVAL(value);
			ZVAL_STRING(value, (char*) (*it).second.front().toCString(), 1);
			add_assoc_zval(return_value, (char*) (*it).first.toCString(), value);
		}
		it++;
	}
}


static zend_function_entry KTaglib_Ogg_Tag_methods[] = {
	PHP_ME(KTaglib_Ogg_Tag, getTitle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, setTitle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getArtist, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, setArtist, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getAlbum, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, setAlbum, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getComment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, setComment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getGenre, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, setGenre, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getTrack, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, setTrack, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getYear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, setYear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, addField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getVendorId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, removeField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, contains, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, fieldCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_Ogg_Tag, getTagList, NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void ktaglib_init_KTaglib_Ogg_Tag(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "KTaglib_Ogg_Tag", KTaglib_Ogg_Tag_methods);
	ce.create_object = ktaglib_init_KTaglib_new;
	ktaglib_ce_Ogg_Tag = zend_register_internal_class(&ce TSRMLS_CC);
}
