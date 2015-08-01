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
  BOOST_CHECK_EQUAL( v.x, 0.0 );
  BOOST_CHECK_EQUAL( v.y, 0.0 );
}

BOOST_AUTO_TEST_CASE(scalar)
{
  ofVec2f v(3.0f);
  BOOST_CHECK_EQUAL( v.x, 3.0f );
  BOOST_CHECK_EQUAL( v.y, 3.0f );
}

BOOST_AUTO_TEST_CASE(explicit_x_y)
{
  ofVec2f v(3.0f, 5.0f);
  BOOST_CHECK_EQUAL( v.x, 3.0f );
  BOOST_CHECK_EQUAL( v.y, 5.0f );
}

BOOST_AUTO_TEST_CASE(from_ofVec3f)
{
  ofVec3f t(1.0f, 2.0f, 3.0f);
  ofVec2f v(t);
  BOOST_CHECK_EQUAL( v.x, 1.0f );
  BOOST_CHECK_EQUAL( v.y, 2.0f );
}

BOOST_AUTO_TEST_CASE(from_ofVec4f)
{
  ofVec4f t(1.0f, 2.0f, 3.0f, 4.0f);
  ofVec2f v(t);
  BOOST_CHECK_EQUAL( v.x, 1.0f );
  BOOST_CHECK_EQUAL( v.y, 2.0f );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(access_components)

BOOST_AUTO_TEST_CASE(getPtr)
{
  ofVec2f v = ofVec2f(3.0f, 5.0f);
  float * ptr = v.getPtr();

  BOOST_ASSERT(NULL != ptr);
  BOOST_CHECK_EQUAL( *(ptr), 3.0f );
  BOOST_CHECK_EQUAL( *(ptr+1), 5.0f );
}

BOOST_AUTO_TEST_CASE(array_like)
{
  ofVec2f v = ofVec2f(3.0f, 5.0f);

  BOOST_CHECK_EQUAL( v[0], 3.0f );
  BOOST_CHECK_EQUAL( v[1], 5.0f );
}

BOOST_AUTO_TEST_CASE(set_floats)
{
  ofVec2f v;
  v.set(3.0, 5.0);
  BOOST_CHECK_EQUAL( v.x, 3.0f );
  BOOST_CHECK_EQUAL( v.y, 5.0f );
}

BOOST_AUTO_TEST_CASE(set_ofvec2f)
{
  ofVec2f v_t = ofVec2f(3.0f, 5.0f);
  ofVec2f v;
  v.set(v_t);
  BOOST_CHECK_EQUAL( v.x, 3.0f );
  BOOST_CHECK_EQUAL( v.y, 5.0f );
}

BOOST_AUTO_TEST_CASE(set_scalar)
{
  ofVec2f v;
  v.set(23.5);
  BOOST_CHECK_EQUAL( v.x, 23.5f );
  BOOST_CHECK_EQUAL( v.y, 23.5f );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(comparison)

BOOST_AUTO_TEST_CASE(operator_equal)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(3.0f, 5.0f);

  BOOST_CHECK( v1 == v2 );
}

BOOST_AUTO_TEST_CASE(operator_unequal)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(-5.0f, 23.42f);

  BOOST_CHECK( v1 != v2 );
}

BOOST_AUTO_TEST_CASE(match_valid)
{
  ofVec2f v1(3.0f, 4.2f);
  ofVec2f v2(3.0f, 4.2f);

  BOOST_CHECK( v1.match(v2) );
}

BOOST_AUTO_TEST_CASE(match_invalid)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(-5.0f, 23.42f);

  BOOST_CHECK( !v1.match(v2) );
}

BOOST_AUTO_TEST_CASE(match_tolerance)
{
  ofVec2f v1(40.0f, 20.0f);
  ofVec2f v2(40.01f, 19.999f);

  BOOST_CHECK( v1.match(v2, 0.01f) );
  BOOST_CHECK( !v1.match(v2, 0.001f) );
}

BOOST_AUTO_TEST_CASE(isAligned)
{
  ofVec2f v1(40.0f, 20.0f);
  ofVec2f v2(4.0f, 2.0f);

  BOOST_CHECK( v1.isAligned(v2) );
}

BOOST_AUTO_TEST_CASE(isAlignedRad)
{
  ofVec2f v1(40.0f, 20.0f);
  ofVec2f v2(4.0f, 2.0f);

  BOOST_CHECK( v1.isAlignedRad(v2) );
}

BOOST_AUTO_TEST_SUITE_END()
