#ifndef PHP_TAGLIBRARY_H
#define PHP_TAGLIBRARY_H

#include <taglib.h>
#include <fileref.h>
#include <tag.h>
#include <tstring.h>
#include <mpegfile.h>
#include <tfile.h>
#include <id3v1tag.h>
#include <id3v2tag.h>
#include <attachedpictureframe.h>
#include <commentsframe.h>

/* Extends zend object */
typedef struct _ze_taglib_file_object {
	zend_object zo;
	int refcount;
	TagLib::File *file;
} ze_taglib_file_object;

typedef struct _ze_taglib_object {
	zend_object zo;
	ze_taglib_file_object * zo_file;
	TagLib::Tag *tag;
	TagLib::ID3v2::Frame *frame;
} ze_taglib_object;

void taglib_ref_class(ze_taglib_object*, ze_taglib_file_object*);

#endif
