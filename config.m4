dnl $Id$
dnl config.m4 for extension fildes

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(fildes, for fildes support,
dnl Make sure that the comment is aligned:
dnl [  --with-fildes             Include fildes support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(fildes, whether to enable fildes support,
dnl Make sure that the comment is aligned:
dnl [  --enable-fildes           Enable fildes support])

if test "$PHP_FILDES" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-fildes -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/fildes.h"  # you most likely want to change this
  dnl if test -r $PHP_FILDES/$SEARCH_FOR; then # path given as parameter
  dnl   FILDES_DIR=$PHP_FILDES
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for fildes files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       FILDES_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$FILDES_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the fildes distribution])
  dnl fi

  dnl # --with-fildes -> add include path
  dnl PHP_ADD_INCLUDE($FILDES_DIR/include)

  dnl # --with-fildes -> check for lib and symbol presence
  dnl LIBNAME=fildes # you may want to change this
  dnl LIBSYMBOL=fildes # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $FILDES_DIR/lib, FILDES_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_FILDESLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong fildes lib version or lib not found])
  dnl ],[
  dnl   -L$FILDES_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(FILDES_SHARED_LIBADD)

  PHP_NEW_EXTENSION(fildes, fildes.c, $ext_shared)
fi
