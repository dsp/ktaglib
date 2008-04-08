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

/* Extends zend object */
typedef struct _ze_taglib_object {
	zend_object zo;
	TagLib::File *file;
	TagLib::Tag *tag;
	TagLib::ID3v2::Frame *frame;
} ze_taglib_object;

#endif
