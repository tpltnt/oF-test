#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ofVec2f_test
#include "ofVec2f.h"
#include "ofVec3f.h"
#include "ofVec4f.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(constructors)

BOOST_AUTO_TEST_CASE(empty)
{
  ofVec2f v;
  BOOST_REQUIRE_EQUAL( v.x, 0.0 );
  BOOST_REQUIRE_EQUAL( v.y, 0.0 );
}

BOOST_AUTO_TEST_CASE(scalar)
{
  ofVec2f v(3.0f);
  BOOST_REQUIRE_EQUAL( v.x, 3.0f );
  BOOST_REQUIRE_EQUAL( v.y, 3.0f );
}

BOOST_AUTO_TEST_CASE(explicit_x_y)
{
  ofVec2f v(3.0f, 5.0f);
  BOOST_REQUIRE_EQUAL( v.x, 3.0f );
  BOOST_REQUIRE_EQUAL( v.y, 5.0f );
}

BOOST_AUTO_TEST_CASE(from_ofVec3f)
{
  ofVec3f t(1.0f, 2.0f, 3.0f);
  ofVec2f v(t);
  BOOST_REQUIRE_EQUAL( v.x, 1.0f );
  BOOST_REQUIRE_EQUAL( v.y, 2.0f );
}

BOOST_AUTO_TEST_CASE(from_ofVec4f)
{
  ofVec4f t(1.0f, 2.0f, 3.0f, 4.0f);
  ofVec2f v(t);
  BOOST_REQUIRE_EQUAL( v.x, 1.0f );
  BOOST_REQUIRE_EQUAL( v.y, 2.0f );
}

BOOST_AUTO_TEST_SUITE_END()
