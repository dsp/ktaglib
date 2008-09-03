--TEST--
KTaglib_Ogg_Tag::contains()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->addField('whatever2', 'Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->contains('whatever'));

$ktaglib->getTag()->removeField('whatever2', 'Cheese');
?>
--EXPECT--
bool(true)
