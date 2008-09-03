--TEST--
KTaglib_Ogg_Vorbis_AudioProperties::getLength()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

var_dump($ktaglib->getAudioProperties()->getLength());
?>
--EXPECT--
int(1)
