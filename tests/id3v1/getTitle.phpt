--TEST--
TagLib_Tag::getTitle()
--SKIPIF--
if (!extension_loaded('taglib')) echo 'skip';
--FILE--
<?php

$taglib = new TagLib_MPEG_File('tests/id3v1/id3v1.mp3');

var_dump($taglib->getID3v1Tag()->getTitle());
--EXPECT--
string(16) "Test ID3v1 Title"
