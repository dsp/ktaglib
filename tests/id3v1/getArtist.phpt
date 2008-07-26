--TEST--
TagLib_Tag::getArtist()
--SKIPIF--
if (!extension_loaded('taglib')) echo 'skip';
--FILE--
<?php

$taglib = new TagLib_MPEG_File('tests/id3v1/id3v1.mp3');

var_dump($taglib->getID3v1Tag()->getArtist());
--EXPECT--
string(17) "Test ID3v1 Artist"
