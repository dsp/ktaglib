dnl
dnl $ Id: $
dnl

PHP_ARG_WITH(taglib, This extension requires the TagLib Library version 1.4
	  or above and a working pkg-config installation.,[  --with-taglib[=DIR]  With taglib support])


if test "$PHP_TAGLIB" != "no"; then
  PHP_REQUIRE_CXX
  AC_LANG_CPLUSPLUS
  PHP_ADD_LIBRARY(stdc++,,TAGLIB_SHARED_LIBADD)

  
  if test -z "$PKG_CONFIG"
  then
	AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  fi
  if test "$PKG_CONFIG" = "no"
  then
	AC_MSG_ERROR([required utility 'pkg-config' not found])
  fi

  if ! $PKG_CONFIG --exists taglib
  then
	AC_MSG_ERROR(['taglib' not known to pkg-config])
  fi

  if ! $PKG_CONFIG --atleast-version 1.4 taglib
  then
	PKG_VERSION=`$PKG_CONFIG --modversion taglib`
	AC_MSG_ERROR(['taglib'\ is version $PKG_VERSION, 1.4 required])
  fi

  PHP_EVAL_INCLINE(`$PKG_CONFIG --cflags-only-I taglib`)
  PHP_EVAL_LIBLINE(`$PKG_CONFIG --libs taglib`, TAGLIB_SHARED_LIBADD)

  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_TAGLIB"
  AC_CHECK_HEADER([taglib.h], [], AC_MSG_ERROR('taglib.h' header not found))
  AC_CHECK_HEADER([fileref.h], [], AC_MSG_ERROR('fileref.h' header not found))
  AC_CHECK_HEADER([tag.h], [], AC_MSG_ERROR('tag.h' header not found))
  AC_CHECK_HEADER([tstring.h], [], AC_MSG_ERROR('tstring.h' header not found))
  AC_CHECK_HEADER([mpegfile.h], [], AC_MSG_ERROR('mpegfile.h' header not found))
  AC_CHECK_HEADER([tfile.h], [], AC_MSG_ERROR('tfile.h' header not found))
  AC_CHECK_HEADER([id3v1tag.h], [], AC_MSG_ERROR('id3v1tag.h' header not found))
  AC_CHECK_HEADER([id3v2tag.h], [], AC_MSG_ERROR('id3v2tag.h' header not found))
  export CPPFLAGS="$OLD_CPPFLAGS"

  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_TAGLIB"

  export CPPFLAGS="$OLD_CPPFLAGS"


  PHP_SUBST(TAGLIB_SHARED_LIBADD)
  AC_DEFINE(HAVE_TAGLIB, 1, [ ])

  PHP_NEW_EXTENSION(taglib, taglib.cpp taglib_mpeg.cpp taglib_tag.cpp \
                            taglib_id3v1_tag.cpp \
                            taglib_id3v2_tag.cpp taglib_id3v2_frame.cpp \ 
                            taglib_id3v2_attachedpictureframe.cpp taglib_id3v2_commentsframe.cpp \
                            taglib_mpeg_audioproperties.cpp taglib_mpeg_header.cpp, $ext_shared)

fi

