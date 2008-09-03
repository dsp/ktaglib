--TEST--
KTaglib_Ogg_Tag::setArtist() / KTaglib_Ogg_Tag::getArtist()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->setArtist('');
$ktaglib->getTag()->setArtist('Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->getArtist());
?>
--EXPECT--
string(6) "Cheese"
