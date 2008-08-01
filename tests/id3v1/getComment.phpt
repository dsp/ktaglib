--TEST--
KTaglib_Tag::getComment()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_MPEG_File('tests/id3v1/id3v1.mp3');

var_dump($ktaglib->getID3v1Tag()->getComment());
--EXPECT--
string(18) "Test ID3v1 Comment"
