--TEST--
KTaglib_Ogg_Tag::setAlbum() / KTaglib_Ogg_Tag::getAlbum()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->setAlbum('');
$ktaglib->getTag()->setAlbum('Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->getAlbum());
?>
--EXPECT--
string(6) "Cheese"
