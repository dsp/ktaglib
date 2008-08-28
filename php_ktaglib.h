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

#ifndef PHP_KTAGLIB_H
#define PHP_KTAGLIB_H

#define PHP_KTAGLIB_VERSION "0.0.1-dev"

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
#include <ext/standard/info.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_extensions.h>

extern zend_class_entry *ktaglib_ce_FileNotFoundException;
extern zend_class_entry *ktaglib_ce_TagNotFoundException;
extern zend_class_entry *ktaglib_ce_BadAllocException;

extern zend_class_entry *ktaglib_ce_MPEG_File;
extern zend_class_entry *ktaglib_ce_Tag;
extern zend_class_entry *ktaglib_ce_ID3v1_Tag;
extern zend_class_entry *ktaglib_ce_ID3v2_Tag;
extern zend_class_entry *ktaglib_ce_ID3v2_Frame;
extern zend_class_entry *ktaglib_ce_ID3v2_PictureFrame;
extern zend_class_entry *ktaglib_ce_ID3v2_CommentsFrame;
extern zend_class_entry *ktaglib_ce_MPEG_AudioProperties;
extern zend_class_entry *ktaglib_ce_MPEG_Header;
extern zend_class_entry *ktaglib_ce_Ogg_Vorbis_File;
extern zend_class_entry *ktaglib_ce_Ogg_Vorbis_AudioProperties;
extern zend_class_entry *ktaglib_ce_Ogg_Tag;

extern zend_module_entry ktaglib_module_entry;
#define phpext_ktaglib_ptr &ktaglib_module_entry

#ifdef PHP_WIN32
#define PHP_KTAGLIB_API __declspec(dllexport)
#else
#define PHP_KTAGLIB_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#ifdef  __cplusplus
} // extern "C" 
#endif


/* internal functions */
void ktaglib_init_class(zend_class_entry **, zend_class_entry *, const char *, zend_function_entry *);
zend_object_value ktaglib_init_KTaglib_File_new(zend_class_entry * TSRMLS_DC);
zend_object_value ktaglib_init_KTaglib_new(zend_class_entry * TSRMLS_DC);
void ktaglib_init_KTaglib_File_free(void *);
void ktaglib_init_KTaglib_free(void *);
void ktaglib_init_KTaglib_Exceptions(TSRMLS_D);
void ktaglib_init_KTaglib_MPEG_File(TSRMLS_D);
void ktaglib_init_KTaglib_Tag(TSRMLS_D);
void ktaglib_init_KTaglib_ID3v1_Tag(TSRMLS_D);
void ktaglib_init_KTaglib_ID3v2_Tag(TSRMLS_D);
void ktaglib_init_KTaglib_ID3v2_Frame(TSRMLS_D);
void ktaglib_init_KTaglib_ID3v2_PictureFrame(TSRMLS_D);
void ktaglib_init_KTaglib_ID3v2_CommentsFrame(TSRMLS_D);
void ktaglib_init_KTaglib_MPEG_AudioProperties(TSRMLS_D);
void ktaglib_init_KTaglib_MPEG_Header(TSRMLS_D);
void ktaglib_init_KTaglib_Ogg_Vorbis_File(TSRMLS_D);
void ktaglib_init_KTaglib_Ogg_Vorbis_AudioProperties(TSRMLS_D);
void ktaglib_init_KTaglib_Ogg_Tag(TSRMLS_D);

/* mirrored PHP Constants */
#define KTAGLIB_TYPE_NONE 0
#define KTAGLIB_TYPE_ID3v1 1
#define KTAGLIB_TYPE_ID3v2 2

#endif /* PHP_HAVE_TAGLIB */

#endif /* PHP_KTAGLIB_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
