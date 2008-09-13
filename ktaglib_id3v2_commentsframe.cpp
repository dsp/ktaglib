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

zend_class_entry * ktaglib_ce_ID3v2_CommentsFrame = NULL;

PHP_METHOD(KTaglib_ID3v2_CommentsFrame, __construct)
{
	char * desc, *text, *lang;
	int * desc_len, text_len, lang_len;
	ze_ktaglib_object *intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|sss", &desc, &desc_len, &text, &text_len, &lang, &lang_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);
	intern->frame = new TagLib::ID3v2::CommentsFrame();

	TagLib::ByteVector vec(lang);
	((TagLib::ID3v2::CommentsFrame *)intern->frame)->setLanguage(vec);
	((TagLib::ID3v2::CommentsFrame *)intern->frame)->setDescription(desc);
	((TagLib::ID3v2::CommentsFrame *)intern->frame)->setText(text);
}

PHP_METHOD(KTaglib_ID3v2_CommentsFrame, getDescription)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	RETURN_STRING((char*) ((TagLib::ID3v2::CommentsFrame *)intern->frame)->description().toCString(), 1);
}

PHP_METHOD(KTaglib_ID3v2_CommentsFrame, getText)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	RETURN_STRING((char*) ((TagLib::ID3v2::CommentsFrame *)intern->frame)->text().toCString(), 1);
}

PHP_METHOD(KTaglib_ID3v2_CommentsFrame, getLanguage)
{
	ze_ktaglib_object *intern = NULL;

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	char* str = strdup((char*) ((TagLib::ID3v2::CommentsFrame *) intern->frame)->language().data());

	RETURN_STRING(str, 1);
}

PHP_METHOD(KTaglib_ID3v2_CommentsFrame, setDescription)
{
	char * desc;
	int desc_len;
	ze_ktaglib_object *intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &desc, &desc_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	((TagLib::ID3v2::CommentsFrame *)intern->frame)->setDescription(desc);
}

PHP_METHOD(KTaglib_ID3v2_CommentsFrame, setText)
{
	char * text;
	int text_len;
	ze_ktaglib_object *intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len) == FAILURE) {
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	((TagLib::ID3v2::CommentsFrame *)intern->frame)->setText(text);
}

PHP_METHOD(KTaglib_ID3v2_CommentsFrame, setLanguage)
{
	char * lang;
	int lang_len;
	ze_ktaglib_object *intern = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &lang, &lang_len) == FAILURE) {
		return;
	}

	if (lang_len != 3) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "String must contain 3 characters");
		return;
	}

	intern = (ze_ktaglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	TagLib::ByteVector vec(lang);
	((TagLib::ID3v2::CommentsFrame *)intern->frame)->setLanguage(vec);
}

static zend_function_entry KTaglib_ID3v2_CommentsFrame_methods[] = {
	PHP_ME(KTaglib_ID3v2_CommentsFrame, __construct, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_CommentsFrame, getText, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_CommentsFrame, getDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_CommentsFrame, getLanguage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_CommentsFrame, setText, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_CommentsFrame, setDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(KTaglib_ID3v2_CommentsFrame, setLanguage, NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void ktaglib_init_KTaglib_ID3v2_CommentsFrame(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "KTaglib_ID3v2_CommentsFrame", KTaglib_ID3v2_CommentsFrame_methods);
	ce.create_object = ktaglib_init_KTaglib_new;
	ktaglib_ce_ID3v2_CommentsFrame = zend_register_internal_class_ex(&ce, ktaglib_ce_ID3v2_Frame, NULL TSRMLS_CC);
}
