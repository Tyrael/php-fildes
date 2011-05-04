/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2011 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 310447 2011-04-23 21:14:10Z bjori $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_fildes.h"

/* If you declare any globals in php_fildes.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(fildes)
*/

/* True global resources - no need for thread safety here */
static int le_fildes;

/* {{{ fildes_functions[]
 *
 * Every user visible function must have an entry in fildes_functions[].
 */
const zend_function_entry fildes_functions[] = {
	PHP_FE(fildes_fileno,	NULL)
	PHP_FE(fildes_fdopen,	NULL)
	{NULL, NULL, NULL}	/* Must be the last line in fildes_functions[] */
};
/* }}} */

/* {{{ fildes_module_entry
 */
zend_module_entry fildes_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"fildes",
	fildes_functions,
	PHP_MINIT(fildes),
	PHP_MSHUTDOWN(fildes),
	PHP_RINIT(fildes),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(fildes),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(fildes),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_FILDES
ZEND_GET_MODULE(fildes)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("fildes.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_fildes_globals, fildes_globals)
    STD_PHP_INI_ENTRY("fildes.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_fildes_globals, fildes_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_fildes_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_fildes_init_globals(zend_fildes_globals *fildes_globals)
{
	fildes_globals->global_value = 0;
	fildes_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(fildes)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(fildes)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(fildes)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(fildes)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(fildes)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "fildes support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* {{{ proto long fildes_fileno(resource fp)
   Return the file descriptor for the given file pointer */
PHP_FUNCTION(fildes_fileno)
{
    zval *zstream;
    int fd;
    php_stream *stream = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zstream) == FAILURE) {
        RETURN_FALSE;
    }

    php_stream_from_zval(stream, &zstream);
    if (FAILURE == php_stream_cast(stream, PHP_STREAM_AS_FD, (void **)&fd, REPORT_ERRORS)) {
        RETURN_FALSE;
    }

    RETURN_LONG(fd);
}
/* }}} */

/* {{{ proto long fildes_fdopen(int fd, string mode)
   Open an file pointer for the given file descriptor */
PHP_FUNCTION(fildes_fdopen)
{
    long fd;
    char *mode;
    int mode_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", &fd, &mode, &mode_len) == FAILURE) {
        RETURN_NULL();
    }
    php_stream * stream = php_stream_fopen_from_fd(fd, mode, NULL);
    php_stream_to_zval(stream, return_value);
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
