--TEST--
KTaglib_Ogg_Tag::setTrack() / KTaglib_Ogg_Tag::getTrack()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->setTrack(17);

$ktaglib->save();

var_dump($ktaglib->getTag()->getTrack());
?>
--EXPECT--
int(17)
