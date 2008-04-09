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

PHPAPI zend_class_entry * taglib_ce_ID3v2_Frame = NULL;

PHP_METHOD(TagLib_ID3v2_Frame, __toString)
{
	ze_taglib_object *intern = NULL;

	intern = (ze_taglib_object*) zend_object_store_get_object(getThis() TSRMLS_CC);

	char* str = strdup((char*) ((TagLib::ID3v2::Frame *) intern->frame)->toString().toCString());

	RETURN_STRING(str, 1);
}

static zend_function_entry TagLib_ID3v2_Frame_methods[] = {
	PHP_ME(TagLib_ID3v2_Frame, __toString, NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

void taglib_init_TagLib_ID3v2_Frame(void)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "TagLib_ID3v2_Frame", TagLib_ID3v2_Frame_methods);
	ce.create_object = taglib_init_TagLib_new;
	taglib_ce_ID3v2_Frame = zend_register_internal_class(&ce TSRMLS_CC);
}
