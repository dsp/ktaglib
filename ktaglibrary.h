#ifndef PHP_KTAGLIBRARY_H
#define PHP_KTAGLIBRARY_H

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
#include <mpegproperties.h>
#include <mpegheader.h>
#include <speexfile.h>
#include <vorbisfile.h>
#include <xiphcomment.h>


/* Extends zend object */
typedef struct _ze_ktaglib_file_object {
	zend_object zo;
	int refcount;
	TagLib::File *file;
} ze_ktaglib_file_object;

typedef struct _ze_ktaglib_object {
	zend_object zo;
	ze_ktaglib_file_object * zo_file;
	TagLib::Tag *tag;
	TagLib::ID3v2::Frame *frame;
	TagLib::MPEG::Properties *properties;
} ze_ktaglib_object;

void ktaglib_ref_class(ze_ktaglib_object*, ze_ktaglib_file_object*);

#endif
