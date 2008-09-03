--TEST--
KTaglib_Ogg_Tag::removeField()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->addField('whatever', 'Cheese');

$ktaglib->save();

$ktaglib->getTag()->removeField('whatever', 'Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->getField('whatever'));
?>
--EXPECT--
NULL
