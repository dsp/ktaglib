--TEST--
KTaglib_Ogg_Tag::addField() / KTaglib_Ogg_Tag::getField()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->addField('whatever', 'Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->getField('whatever'));
?>
--EXPECT--
string(6) "Cheese"
