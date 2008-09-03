--TEST--
KTaglib_Ogg_Tag::setGenre() / KTaglib_Ogg_Tag::getGenre()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->setGenre('');
$ktaglib->getTag()->setGenre('Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->getGenre());
?>
--EXPECT--
string(6) "Cheese"
