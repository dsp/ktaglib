--TEST--
KTaglib_Ogg_Tag::getFieldList()
--SKIPIF--
if (!extension_loaded('ktaglib')) echo 'skip';
--FILE--
<?php

/**
 * NOTE no saving manipulations in this test -
 * it can cause all other tests to fail
 * and make the test file unusable
 */
$ktaglib = new KTaglib_Ogg_Vorbis_File('tests/ogg/vorbis/cow.ogg');

/**
 * Get all tags and remove all of them
 */
$keys = array_keys($ktaglib->getTag()->getTagList());

foreach($keys as $tagname) {
	$ktaglib->getTag()->removeField($tagname);
}

/**
 * Add one field
 */
$ktaglib->getTag()->
addField('hello', 'world');

var_dump($ktaglib->getTag()->getTagList());
--EXPECT--
array(1) {
  ["HELLO"]=>
  string(5) "world"
}