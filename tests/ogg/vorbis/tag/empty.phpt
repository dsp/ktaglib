--TEST--
KTaglib_Ogg_Tag::isEmpty()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

var_dump($ktaglib->getTag()->isEmpty());

?>
--EXPECT--
bool(false)
