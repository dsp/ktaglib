--TEST--
KTaglib_Ogg_Tag::setTitle() / KTaglib_Ogg_Tag::getTitle()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->setTitle('');
$ktaglib->getTag()->setTitle('Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->getTitle());
?>
--EXPECT--
string(6) "Cheese"
