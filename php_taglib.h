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

/* $ Id: $ */ 

#ifndef PHP_TAGLIB_H
#define PHP_TAGLIB_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#ifdef HAVE_TAGLIB

#include <php_ini.h>
#include <php_streams.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_extensions.h>

extern PHPAPI zend_class_entry *taglib_ce_FileNotFoundException;
extern PHPAPI zend_class_entry *taglib_ce_TagNotFoundException;
extern PHPAPI zend_class_entry *taglib_ce_MPEG_File;
extern PHPAPI zend_class_entry *taglib_ce_Tag;
extern PHPAPI zend_class_entry *taglib_ce_ID3v1_Tag;
extern PHPAPI zend_class_entry *taglib_ce_ID3v2_Tag;
extern PHPAPI zend_class_entry *taglib_ce_ID3v2_Frame;
extern PHPAPI zend_class_entry *taglib_ce_ID3v2_PictureFrame;

extern zend_module_entry taglib_module_entry;
#define phpext_taglib_ptr &taglib_module_entry

#ifdef PHP_WIN32
#define PHP_TAGLIB_API __declspec(dllexport)
#else
#define PHP_TAGLIB_API
#endif

PHP_MINIT_FUNCTION(taglib);
PHP_MSHUTDOWN_FUNCTION(taglib);
PHP_RINIT_FUNCTION(taglib);
PHP_RSHUTDOWN_FUNCTION(taglib);
PHP_MINFO_FUNCTION(taglib);

#ifdef ZTS
#include "TSRM.h"
#endif

#define FREE_RESOURCE(resource) zend_list_delete(Z_LVAL_P(resource))

#define PROP_GET_LONG(name)    Z_LVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_LONG(name, l) zend_update_property_long(_this_ce, _this_zval, #name, strlen(#name), l TSRMLS_CC)

#define PROP_GET_DOUBLE(name)    Z_DVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_DOUBLE(name, d) zend_update_property_double(_this_ce, _this_zval, #name, strlen(#name), d TSRMLS_CC)

#define PROP_GET_STRING(name)    Z_STRVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_GET_STRLEN(name)    Z_STRLEN_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_STRING(name, s) zend_update_property_string(_this_ce, _this_zval, #name, strlen(#name), s TSRMLS_CC)
#define PROP_SET_STRINGL(name, s, l) zend_update_property_stringl(_this_ce, _this_zval, #name, strlen(#name), s, l TSRMLS_CC)


PHP_METHOD(TagLib_MPEG_File, __construct);
PHP_METHOD(TagLib_MPEG_File, getID3v1Tag);

#ifdef  __cplusplus
} // extern "C" 
#endif


/* internal functions */
void taglib_init_class(zend_class_entry **, zend_class_entry *, const char *, zend_function_entry *);
zend_object_value taglib_init_TagLib_File_new(zend_class_entry *);
void taglib_init_TagLib_File_free(void *);
void taglib_init_TagLib_Exceptions(void);
void taglib_init_TagLib_MPEG_File(void);
void taglib_init_TagLib_Tag(void);
void taglib_init_TagLib_ID3v1_Tag(void);
void taglib_init_TagLib_ID3v2_Tag(void);
void taglib_init_TagLib_ID3v2_Frame(void);
void taglib_init_TagLib_ID3v2_PictureFrame(void);

/* mirrored PHP Constants */
#define TAGLIB_TYPE_NONE 0
#define TAGLIB_TYPE_ID3v1 1
#define TAGLIB_TYPE_ID3v2 2

#endif /* PHP_HAVE_TAGLIB */

#endif /* PHP_TAGLIB_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
