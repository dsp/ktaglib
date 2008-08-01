--TEST--
KTaglib_Tag::getTrack()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_MPEG_File('tests/id3v1/id3v1.mp3');

var_dump($ktaglib->getID3v1Tag()->getTrack());
--EXPECT--
int(1)
