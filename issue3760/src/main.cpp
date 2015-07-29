#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ofXml_test
#include "ofXml.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(issue3760)

/* In the ofXml class, when I try to read through an XML file sequentially
   using the setToSibling() method, I get EXC_BAD_ACCESS from getValue()
   when a commented line, like <!-- <pRangeMin>36</pRangeMin>--> is encountered.

   The test data "issue3760.xml" contains comments in different places.
 */

BOOST_AUTO_TEST_CASE(sequential_setToSibling)
{
  ofFile file;
  BOOST_REQUIRE( file.doesFileExist("issue3760.xml") );

  ofXml xmldata;
  BOOST_REQUIRE( xmldata.load("issue3760.xml") );
  BOOST_REQUIRE_EQUAL( 4, xmldata.getNumChildren() );
  BOOST_REQUIRE( xmldata.setToChild(0) );
  // trying setToSibling() for iteration should work 4 times
  // since only 4 elements (=3 siblings) are there (one
  // is commented out)
  BOOST_CHECK( xmldata.setToSibling() );
  BOOST_CHECK( xmldata.setToSibling() );
  BOOST_CHECK( xmldata.setToSibling() );
  BOOST_CHECK( !xmldata.setToSibling() );
}

BOOST_AUTO_TEST_CASE(sequential_setToSibling_getValue)
{
  ofFile file;
  BOOST_REQUIRE( file.doesFileExist("issue3760.xml") );

  ofXml xmldata;
  BOOST_REQUIRE( xmldata.load("issue3760.xml") );
  BOOST_REQUIRE_EQUAL( 4, xmldata.getNumChildren() );
  BOOST_REQUIRE( xmldata.setToChild(0) );
  // trying setToSibling() for iteration and trying to retrieve
  // the value should trigger the bug.
  BOOST_CHECK_EQUAL( "1", xmldata.getValue() );
  BOOST_CHECK( xmldata.setToSibling() );
  BOOST_CHECK_EQUAL( "2", xmldata.getValue() );
  BOOST_CHECK( xmldata.setToSibling() );  // critical element
  BOOST_CHECK_EQUAL( "4", xmldata.getValue() );  // trigger bug
  BOOST_CHECK( xmldata.setToSibling() );
  BOOST_CHECK_EQUAL( "5", xmldata.getValue() );
  BOOST_CHECK( !xmldata.setToSibling() );
}

BOOST_AUTO_TEST_CASE(third_element_comment_child_getValue)
{
  ofFile file;
  BOOST_REQUIRE( file.doesFileExist("issue3760.xml") );

  ofXml xmldata;
  BOOST_REQUIRE( xmldata.load("issue3760.xml") );
  BOOST_REQUIRE_EQUAL( 4, xmldata.getNumChildren() );
  BOOST_CHECK( xmldata.setToChild(0) );
  BOOST_CHECK_EQUAL( "1", xmldata.getValue() );
  BOOST_CHECK( xmldata.setToSibling() );
  BOOST_CHECK_EQUAL( "2", xmldata.getValue() );
  BOOST_CHECK( xmldata.setToSibling() );  // critical element
  BOOST_CHECK_EQUAL( "4", xmldata.getValue() );  // trigger bug
  BOOST_CHECK( xmldata.setToSibling() );
  BOOST_CHECK_EQUAL( "5", xmldata.getValue() );
  BOOST_CHECK( !xmldata.setToSibling() );
}

BOOST_AUTO_TEST_CASE(directly_get_child_getValue)
{
  ofFile file;
  BOOST_REQUIRE( file.doesFileExist("issue3760.xml") );

  ofXml xmldata;
  BOOST_REQUIRE( xmldata.load("issue3760.xml") );
  BOOST_REQUIRE_EQUAL( 4, xmldata.getNumChildren() );
  BOOST_CHECK( xmldata.setToChild(2) );  // jump to critical node
  BOOST_CHECK_EQUAL( "4", xmldata.getValue() );  // potentiall trigger bug
}

BOOST_AUTO_TEST_CASE(only_comment_child_getValue)
{
  ofFile file;
  BOOST_REQUIRE( file.doesFileExist("issue3760-2.xml") );

  ofXml xmldata;
  BOOST_REQUIRE( xmldata.load("issue3760-2.xml") );
  BOOST_REQUIRE_EQUAL( 0, xmldata.getNumChildren() );
  BOOST_CHECK( !xmldata.setToChild(0) );  // potentially trigger bug
  BOOST_CHECK( !xmldata.setToSibling() );
}

BOOST_AUTO_TEST_CASE(whitespace_and_comment_handling)
{
  ofFile file;
  BOOST_REQUIRE( file.doesFileExist("issue3760-3.xml") );

  ofXml xmldata;
  BOOST_REQUIRE( xmldata.load("issue3760-3.xml") );
  BOOST_REQUIRE_EQUAL( 0, xmldata.getNumChildren() );
  BOOST_CHECK( !xmldata.setToChild(0) );
  BOOST_CHECK( !xmldata.setToSibling() );
}

BOOST_AUTO_TEST_SUITE_END()
