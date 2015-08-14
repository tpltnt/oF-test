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
  ofVec2f v2(40.1f, 19.9f);

  BOOST_CHECK( v1.match(v2, 0.2f) );
  BOOST_CHECK( !v1.match(v2, 0.1f) );
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


BOOST_AUTO_TEST_SUITE(operators)

BOOST_AUTO_TEST_CASE(operator_addition_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  ofVec2f v_t = v1 + v2;

  BOOST_CHECK_EQUAL( v_t.x, 4.0f );
  BOOST_CHECK_EQUAL( v_t.y, 13.0f );
}

BOOST_AUTO_TEST_CASE(operator_addition_scalar)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v_t = v1 + 7;

  BOOST_CHECK_EQUAL( v_t.x, 10.0f );
  BOOST_CHECK_EQUAL( v_t.y, 12.0f );
}

BOOST_AUTO_TEST_CASE(operator_addition_equal_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  v1 += v2;

  BOOST_CHECK_EQUAL( v1.x, 4.0f );
  BOOST_CHECK_EQUAL( v1.y, 13.0f );
}

BOOST_AUTO_TEST_CASE(operator_addition_equal_scalar)
{
  ofVec2f v1(3.0f, 5.0f);
  v1 += 7;

  BOOST_CHECK_EQUAL( v1.x, 10.0f );
  BOOST_CHECK_EQUAL( v1.y, 12.0f );
}

BOOST_AUTO_TEST_CASE(operator_substraction_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  ofVec2f v_t = v1 - v2;

  BOOST_CHECK_EQUAL( v_t.x, 2.0f );
  BOOST_CHECK_EQUAL( v_t.y, -3.0f );
}

BOOST_AUTO_TEST_CASE(operator_substraction_scalar)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v_t = v1 - 7;

  BOOST_CHECK_EQUAL( v_t.x, -4.0f );
  BOOST_CHECK_EQUAL( v_t.y, -2.0f );
}

BOOST_AUTO_TEST_CASE(operator_substraction_equal_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  v1 -= v2;

  BOOST_CHECK_EQUAL( v1.x, 2.0f );
  BOOST_CHECK_EQUAL( v1.y, -3.0f );
}

BOOST_AUTO_TEST_CASE(operator_substraction_equal_scalar)
{
  ofVec2f v1(3.0f, 5.0f);
  v1 -= 7;

  BOOST_CHECK_EQUAL( v1.x, -4.0f );
  BOOST_CHECK_EQUAL( v1.y, -2.0f );
}

BOOST_AUTO_TEST_CASE(operator_negate)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2;
  v2 = -v1;

  BOOST_CHECK_EQUAL( v2.x, -3.0f );
  BOOST_CHECK_EQUAL( v2.y, -5.0f );
}

BOOST_AUTO_TEST_CASE(operator_asterisc_scaling_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  ofVec2f v_t = v1 * v2;

  BOOST_CHECK_EQUAL( v_t.x, 3.0f );
  BOOST_CHECK_EQUAL( v_t.y, 40.0f );
}

BOOST_AUTO_TEST_CASE(operator_asterisc_scaling_scalar)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v_t = v1 * -7;

  BOOST_CHECK_EQUAL( v_t.x, -21.0f );
  BOOST_CHECK_EQUAL( v_t.y, -35.0f );
}

BOOST_AUTO_TEST_CASE(operator_asterisc_scaling_equal_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  v1 *= v2;

  BOOST_CHECK_EQUAL( v1.x, 3.0f );
  BOOST_CHECK_EQUAL( v1.y, 40.0f );
}

BOOST_AUTO_TEST_CASE(operator_asterisc_scaling_equal_scalar)
{
  ofVec2f v1(3.0f, 5.0f);
  v1 *= 7;

  BOOST_CHECK_EQUAL( v1.x, 21.0f );
  BOOST_CHECK_EQUAL( v1.y, 35.0f );
}

BOOST_AUTO_TEST_CASE(operator_slash_scaling_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  ofVec2f v_t = v1 / v2;

  BOOST_CHECK_EQUAL( v_t.x, 3.0f );
  BOOST_CHECK_EQUAL( v_t.y, 0.625f );
}

BOOST_AUTO_TEST_CASE(operator_slash_scaling_scalar)
{
  ofVec2f v1(7.0f, -14.0f);
  ofVec2f v_t = v1 / -7;

  BOOST_CHECK_EQUAL( v_t.x, -1.0f );
  BOOST_CHECK_EQUAL( v_t.y, 2.0f );
}

BOOST_AUTO_TEST_CASE(operator_slash_scaling_equal_vector)
{
  ofVec2f v1(3.0f, 5.0f);
  ofVec2f v2(1.0f, 8.0f);
  v1 /= v2;

  BOOST_CHECK_EQUAL( v1.x, 3.0f );
  BOOST_CHECK_EQUAL( v1.y, 0.625f );
}

BOOST_AUTO_TEST_CASE(operator_slash_scaling_equal_scalar)
{
  ofVec2f v1(7.0f, -14.0f);
  v1 /= 7;

  BOOST_CHECK_EQUAL( v1.x, 1.0f );
  BOOST_CHECK_EQUAL( v1.y, -2.0f );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(simple_manipulations)

BOOST_AUTO_TEST_CASE(getScaled)
{
  ofVec2f v1(3, 4);
  BOOST_CHECK_EQUAL(5.0f, v1.length());  // length should be 5

  // get scaled vector of length 15
  ofVec2f v2 = v1.getScaled(15);
  BOOST_CHECK_EQUAL(15.0f, v2.length());
}

BOOST_AUTO_TEST_SUITE_END()
