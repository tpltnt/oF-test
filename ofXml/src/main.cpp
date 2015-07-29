#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ofXml_test
#include "ofXml.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(setTo)

BOOST_AUTO_TEST_CASE(no_object)
{
  ofXml xmldata;
  // should warn with "empty document"
  BOOST_REQUIRE( !xmldata.setTo("") );
}

BOOST_AUTO_TEST_CASE(empty_path)
{
  ofFile file;

  BOOST_REQUIRE( file.doesFileExist("empty.xml") );
  BOOST_REQUIRE( file.open("empty.xml") );
  ofBuffer buffer = file.readToBuffer();

  ofXml xmldata;
  //xmldata.loadFromBuffer(buffer.getText());
  // should warn with "empty document"
  BOOST_REQUIRE( !xmldata.setTo("") );

  file.close();
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(tutorial)

BOOST_AUTO_TEST_CASE(select_element)
{
  ofFile file;

  BOOST_REQUIRE( file.doesFileExist("pictures.xml") );
  BOOST_REQUIRE( file.open("pictures.xml") );
  ofBuffer buffer = file.readToBuffer();

  ofXml pictures;
  pictures.loadFromBuffer(buffer.getText());

  BOOST_CHECK( pictures.setTo("pictures") );
  BOOST_CHECK( pictures.setTo("pictures/picture[0]") );
  BOOST_CHECK( pictures.setTo("picture[1]") );
  BOOST_CHECK( pictures.setTo("pictures/picture[@id=0]") );
  /*
  BOOST_CHECK( pictures.setTo("pictures") );
  BOOST_CHECK( pictures.setTo("//pictures/picture[0]") );
  BOOST_CHECK( pictures.setTo("//picture[1]") );
  BOOST_CHECK( pictures.setTo("//pictures/picture[@id=0]") );
  */
  file.close();
}


BOOST_AUTO_TEST_CASE(traversal)
{
  ofFile file;

  BOOST_REQUIRE( file.doesFileExist("pictures.xml") );
  BOOST_REQUIRE( file.open("pictures.xml") );
  ofBuffer buffer = file.readToBuffer();

  ofXml pictures;
  pictures.loadFromBuffer(buffer.getText());
  // start at first picture
  int children = pictures.getNumChildren();
  BOOST_CHECK( children == 2);
  BOOST_CHECK( pictures.setTo("pictures") );
  BOOST_CHECK( pictures.setToChild(0) );
  children = pictures.getNumChildren();
  BOOST_CHECK( children == 3);  // url, width, height
  BOOST_CHECK( pictures.setToParent() ); // go up a level
  BOOST_CHECK( pictures.setToChild(0) ); // reset position
  BOOST_CHECK( pictures.setToSibling() ); // go to the next at your level
  BOOST_CHECK( pictures.setToPrevSibling() ); // go to the previous at your level

  file.close();
}

BOOST_AUTO_TEST_CASE(get_value)
{
  ofFile file;

  BOOST_REQUIRE( file.doesFileExist("pictures.xml") );
  BOOST_REQUIRE( file.open("pictures.xml") );
  ofBuffer buffer = file.readToBuffer();

  ofXml pictures;
  pictures.loadFromBuffer(buffer.getText());
  // start at first picture
  BOOST_REQUIRE( "http://apicture.co.uk/pic2.png" == pictures.getValue("pictures/picture[0]/url") );

  file.close();
}

BOOST_AUTO_TEST_CASE(set_value)
{
  ofFile file;

  BOOST_REQUIRE( file.doesFileExist("pictures.xml") );
  BOOST_REQUIRE( file.open("pictures.xml") );
  ofBuffer buffer = file.readToBuffer();

  ofXml pictures;
  pictures.loadFromBuffer(buffer.getText());

  BOOST_REQUIRE( pictures.setValue("pictures/picture[0]/url", "http://superpicks.jp/pic1.png") );
  BOOST_REQUIRE( "http://superpicks.jp/pic1.png" == pictures.getValue("pictures/picture[0]/url") );
  
  file.close();
}

BOOST_AUTO_TEST_SUITE_END()
