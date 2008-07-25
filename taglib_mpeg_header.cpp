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

PHPAPI zend_class_entry *taglib_ce_MPEG_Header = NULL;

static zend_function_entry TagLib_MPEG_Header_methods[] = {
	{ NULL, NULL, NULL }
};

void taglib_init_TagLib_MPEG_Header(void)
{
	zend_class_entry ce;

	TSRMLS_FETCH();

	INIT_CLASS_ENTRY(ce, "TagLib_MPEG_Header", TagLib_MPEG_Header_methods);
	ce.create_object = taglib_init_TagLib_new;
	taglib_ce_MPEG_Header = zend_register_internal_class(&ce);

	zend_declare_class_constant_long(taglib_ce_MPEG_Header, "VERSION1",  strlen("VERSION1"), TagLib::MPEG::Header::Version1 TSRMLS_DC);
	zend_declare_class_constant_long(taglib_ce_MPEG_Header, "VERSION2",  strlen("VERSION2"), TagLib::MPEG::Header::Version2 TSRMLS_DC);
	zend_declare_class_constant_long(taglib_ce_MPEG_Header, "VERSION2_5",  strlen("VERSION2_5"), TagLib::MPEG::Header::Version2_5 TSRMLS_DC);
}
