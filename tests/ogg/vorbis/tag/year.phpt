--TEST--
KTaglib_Ogg_Tag::setYear() / KTaglib_Ogg_Tag::getYear()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

$ktaglib->getTag()->setYear(2007);

$ktaglib->save();

var_dump($ktaglib->getTag()->getYear());
?>
--EXPECT--
int(2007)
