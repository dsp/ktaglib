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

#include "php_ktaglib.h"
#include "ktaglibrary.h"

#if HAVE_TAGLIB

/* {{{ Class definitions */

/*    {{{ Class KTaglib_File */
zend_class_entry *ktaglib_ce_FileNotFoundException;
zend_class_entry *ktaglib_ce_TagNotFoundException;

static zend_class_entry * KTaglib_File_ce_ptr = NULL;

void ktaglib_ref_class(ze_ktaglib_object * zo, ze_ktaglib_file_object *zo_file)
{
	zo->zo_file = zo_file;
	zo_file->refcount++;
}

/* Exceptions */
void ktaglib_init_class(zend_class_entry ** ppce, zend_class_entry *pce, const char * name, zend_function_entry * functions TSRMLS_DC)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, name, functions);
	ce.name_length = strlen(name);
	*ppce = zend_register_internal_class_ex(&ce, pce, NULL TSRMLS_CC);
	(*ppce)->create_object = pce->create_object;
}

void ktaglib_init_KTaglib_Exceptions(TSRMLS_D)
{
	ktaglib_init_class(&ktaglib_ce_FileNotFoundException, zend_exception_get_default(TSRMLS_C), "KTaglib_FileNotFoundException", NULL TSRMLS_CC);
	ktaglib_init_class(&ktaglib_ce_TagNotFoundException, zend_exception_get_default(TSRMLS_C), "KTaglib_TagNotFoundException", NULL TSRMLS_CC);
}


void ktaglib_init_KTaglib_File_free(void *object TSRMLS_DC) /* {{{ */
{
	ze_ktaglib_file_object * intern = (ze_ktaglib_file_object *) object;

	intern->refcount--;
	if (intern->refcount <= 0 && intern->file) {
		delete intern->file;
	}

	zend_object_std_dtor(&intern->zo TSRMLS_CC);
	efree(intern);
}


void ktaglib_init_KTaglib_free(void *object TSRMLS_DC) /* {{{ */
{
	ze_ktaglib_object * intern = (ze_ktaglib_object *) object;

	if (intern->zo_file) {
		intern->zo_file->refcount--;
	}

	zend_object_std_dtor(&intern->zo TSRMLS_CC);
	efree(intern);
}

zend_object_value ktaglib_init_KTaglib_File_new(zend_class_entry *class_type TSRMLS_DC) /* {{{ */
{
	ze_ktaglib_file_object *intern;
	zval *tmp;
	zend_object_value retval;

	intern = (ze_ktaglib_file_object*) emalloc(sizeof(ze_ktaglib_file_object));
	memset(&intern->zo, 0, sizeof(zend_object));

	intern->file = NULL;
	intern->refcount = 1;

	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	zend_hash_copy(intern->zo.properties, &class_type->default_properties, (copy_ctor_func_t) zval_add_ref,
					(void *) &tmp, sizeof(zval *));

	retval.handle = zend_objects_store_put(intern,
						NULL,
						(zend_objects_free_object_storage_t) ktaglib_init_KTaglib_File_free,
						NULL TSRMLS_CC);

	retval.handlers = zend_get_std_object_handlers();

	/* Preventing object cloning is easier than creating the handlers for clone :) */
	retval.handlers->clone_obj = NULL;

	return retval;

}


zend_object_value ktaglib_init_KTaglib_new(zend_class_entry *class_type TSRMLS_DC) /* {{{ */
{
	ze_ktaglib_object *intern;
	zval *tmp;
	zend_object_value retval;

	intern = (ze_ktaglib_object*) emalloc(sizeof(ze_ktaglib_object));
	memset(&intern->zo, 0, sizeof(zend_object));

	intern->zo_file = NULL;
	intern->tag = NULL;
	intern->frame = NULL;

	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	zend_hash_copy(intern->zo.properties, &class_type->default_properties, (copy_ctor_func_t) zval_add_ref,
					(void *) &tmp, sizeof(zval *));

	retval.handle = zend_objects_store_put(intern,
						NULL,
						(zend_objects_free_object_storage_t) ktaglib_init_KTaglib_free,
						NULL TSRMLS_CC);

	retval.handlers = zend_get_std_object_handlers();
	retval.handlers->clone_obj = NULL;
	return retval;

}

/*       }}} Methods */
/*    }}} Class KTaglib */


/* {{{ ktaglib_functions[] */
function_entry ktaglib_functions[] = {
	{ NULL, NULL, NULL }
};
/* }}} */


/* {{{ ktaglib_module_entry
 */
zend_module_entry ktaglib_module_entry = {
	STANDARD_MODULE_HEADER,
	"ktaglib",
	ktaglib_functions,
	PHP_MINIT(ktaglib),     /* Replace with NULL if there is nothing to do at php startup   */ 
	PHP_MSHUTDOWN(ktaglib), /* Replace with NULL if there is nothing to do at php shutdown  */
	PHP_RINIT(ktaglib),     /* Replace with NULL if there is nothing to do at request start */
	PHP_RSHUTDOWN(ktaglib), /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(ktaglib),
	PHP_KTAGLIB_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_KTAGLIB
extern "C" {
ZEND_GET_MODULE(ktaglib)
} // extern "C"
#endif


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(ktaglib)
{
	ktaglib_init_KTaglib_Exceptions(TSRMLS_C);
	ktaglib_init_KTaglib_MPEG_File(TSRMLS_C);
	ktaglib_init_KTaglib_Tag(TSRMLS_C);
	ktaglib_init_KTaglib_ID3v1_Tag(TSRMLS_C);
	ktaglib_init_KTaglib_ID3v2_Tag(TSRMLS_C);
	ktaglib_init_KTaglib_ID3v2_Frame(TSRMLS_C);
	ktaglib_init_KTaglib_ID3v2_PictureFrame(TSRMLS_C);
	ktaglib_init_KTaglib_ID3v2_CommentsFrame(TSRMLS_C);
	ktaglib_init_KTaglib_MPEG_AudioProperties(TSRMLS_C);
	ktaglib_init_KTaglib_MPEG_Header(TSRMLS_C);

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(ktaglib)
{
	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(ktaglib)
{
	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(ktaglib)
{
	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(ktaglib)
{
	char version[5];

	sprintf(version, "%1d.%1d.%1d", 
			TAGLIB_MAJOR_VERSION, TAGLIB_MINOR_VERSION, TAGLIB_PATCH_VERSION);

	php_info_print_table_start();
	php_info_print_table_row(2, "ktaglib Support", "enabled");
	php_info_print_table_row(2, "taglib Version", version);
	php_info_print_table_row(2, "Supported Formats", "ID3v1, ID3v2");
	php_info_print_table_row(2, "Version", PHP_KTAGLIB_VERSION);
	php_info_print_table_end();

}
/* }}} */

#endif /* HAVE_TAGLIB */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
