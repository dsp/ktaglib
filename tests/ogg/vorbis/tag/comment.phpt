--TEST--
KTaglib_Ogg_Tag::setComment() / KTaglib_Ogg_Tag::getComment()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->setComment('');
$ktaglib->getTag()->setComment('Cheese');

$ktaglib->save();

var_dump($ktaglib->getTag()->getComment());
?>
--EXPECT--
string(6) "Cheese"
