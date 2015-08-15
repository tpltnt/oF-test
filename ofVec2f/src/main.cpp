#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ofVec2f_test
#include "ofVec2f.h"
#include "ofVec3f.h"
#include "ofVec4f.h"
#include <math.h>
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

BOOST_AUTO_TEST_CASE(getScaled_0)
{
  ofVec2f v1(3, 4);
  BOOST_CHECK_EQUAL(5.0f, v1.length());  // length should be 5

  // get scaled vector of length 15
  ofVec2f v2 = v1.getScaled(15);
  BOOST_CHECK_EQUAL(15.0f, v2.length());
}

BOOST_AUTO_TEST_CASE(getScaled_1)
{
  ofVec2f v1(-3, 4);
  BOOST_CHECK_EQUAL(5.0f, v1.length());  // length should be 5

  // get scaled vector of length 15
  ofVec2f v2 = v1.getScaled(15);
  BOOST_CHECK_EQUAL(15.0f, v2.length());
}

BOOST_AUTO_TEST_CASE(scale_0)
{
  ofVec2f v1(3, 4);
  BOOST_CHECK_EQUAL(5.0f, v1.length());  // length should be 5

  // get scaled vector of length 15
  BOOST_CHECK_EQUAL(15.0f, v1.scale(15).length());
}

BOOST_AUTO_TEST_CASE(scale_1)
{
  ofVec2f v1(-3, 4);
  BOOST_CHECK_EQUAL(5.0f, v1.length());  // length should be 5

  BOOST_CHECK_EQUAL(15.0f, v1.scale(15).length());
}

BOOST_AUTO_TEST_CASE(getRotated_0)
{
  ofVec2f v1(1, 0);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate 45 degrees
  ofVec2f v2 = v1.getRotated(45);
  BOOST_CHECK_EQUAL(sqrtf(2.0f)/2, v2.x);
  BOOST_CHECK_EQUAL(sqrtf(2.0f)/2, v2.y);

  // rotate another 45 degrees -> show numerical artefact
  ofVec2f v3 = v2.getRotated(45);
  BOOST_CHECK_EQUAL(0.0f, v3.x);
  BOOST_CHECK_EQUAL(0.99999994f, v3.y);
}

BOOST_AUTO_TEST_CASE(getRotated_1)
{
  ofVec2f v1(1, 0);
  ofVec2f p(0, 1);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate 45 degrees, but non-center pivot
  ofVec2f v2 = v1.getRotated(45, p);
  BOOST_CHECK_EQUAL(sqrtf(2.0f), v2.x);
  BOOST_CHECK_EQUAL(1.0f, v2.y);
}

BOOST_AUTO_TEST_CASE(getRotated_2)
{
  // pivoting around (0,0) should be like normal
  // getRotated()
  ofVec2f v1(1, 0);
  ofVec2f p(0, 0);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate 45 degrees
  ofVec2f v2 = v1.getRotated(45);
  ofVec2f v2p = v1.getRotated(45);
  BOOST_CHECK_EQUAL(v2.x, v2p.x);
  BOOST_CHECK_EQUAL(v2.y, v2p.y);

  // rotate another 45 degrees -> show numerical artefacf
  ofVec2f v3 = v2.getRotated(45);
  ofVec2f v3p = v2.getRotated(45, p);
  BOOST_CHECK_EQUAL(v3.x, v3p.x);
  BOOST_CHECK_EQUAL(v3.y, v3p.y);
}

BOOST_AUTO_TEST_CASE(getRotatedRad_0)
{
  // numerical imprecisions since float
  // is used internally
  ofVec2f v1(1, 0);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate PI/2 (=90) degrees
  ofVec2f v2 = v1.getRotatedRad(PI/2);
  BOOST_CHECK_EQUAL(-4.37113883e-08f, v2.x);
  BOOST_CHECK_EQUAL(1.0f, v2.y);

  // rotate  PI/4 (=45) degrees
  ofVec2f v3 = v2.getRotatedRad(PI/4);
  BOOST_CHECK_EQUAL(-0.707106829f, v3.x);
  BOOST_CHECK_EQUAL(0.707106709f, v3.y);
}

BOOST_AUTO_TEST_CASE(getRotatedRad_1)
{
  // numerical imprecisions since float
  // is used internally
  ofVec2f v1(1, 0);
  ofVec2f p(0, 1);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate PI/4 (=45) degrees, but non-center pivot
  ofVec2f v2 = v1.getRotatedRad(PI/4, p);
  BOOST_CHECK_EQUAL(sqrtf(2.0f), v2.x);
  BOOST_CHECK_EQUAL(1.0f, v2.y);
}

BOOST_AUTO_TEST_CASE(getRotatedRad_2)
{
  // pivoting around (0,0) should be like normal
  // getRotatedRad()
  ofVec2f v1(1, 0);
  ofVec2f p(0, 0);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate PI/2 (=90) degrees
  ofVec2f v2 = v1.getRotatedRad(PI/2);
  ofVec2f v2p = v1.getRotatedRad(PI/2);
  BOOST_CHECK_EQUAL(v2.x, v2p.x);
  BOOST_CHECK_EQUAL(v2.y, v2p.y);

  // rotate another PI/4 (=45) degrees
  ofVec2f v3 = v2.getRotatedRad(PI/4);
  ofVec2f v3p = v2.getRotatedRad(PI/4, p);
  BOOST_CHECK_EQUAL(v3.x, v3p.x);
  BOOST_CHECK_EQUAL(v3.y, v3p.y);
}

BOOST_AUTO_TEST_CASE(rotate_0)
{
  // numerical imprecisions since float
  // is used internally
  ofVec2f v1(1, 0);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate 90 degrees
  ofVec2f v2 = v1.rotate(90);
  BOOST_CHECK_EQUAL(-4.37113883e-08f, v1.x);
  BOOST_CHECK_EQUAL(1.0f, v1.y);
  BOOST_CHECK_EQUAL(-4.37113883e-08f, v2.x);
  BOOST_CHECK_EQUAL(1.0f, v2.y);

  // rotate  45 degrees
  ofVec2f v3 = v1.rotate(45);
  BOOST_CHECK_EQUAL(-0.707106829f, v3.x);
  BOOST_CHECK_EQUAL(0.707106709f, v3.y);
}

BOOST_AUTO_TEST_CASE(rotate_1)
{
  // numerical imprecisions since float
  // is used internally
  ofVec2f v1(1, 0);
  ofVec2f p(0, 1);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotate 45 degrees, but non-center pivot
  ofVec2f v2 = v1.rotate(45, p);
  BOOST_CHECK_EQUAL(sqrtf(2.0f), v1.x);
  BOOST_CHECK_EQUAL(1.0f, v1.y);
  BOOST_CHECK_EQUAL(sqrtf(2.0f), v2.x);
  BOOST_CHECK_EQUAL(1.0f, v2.y);
}

BOOST_AUTO_TEST_CASE(rotateRad_0)
{
  // numerical imprecisions since float
  // is used internally
  ofVec2f v1(1, 0);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotateRad PI/2 (=90) degrees
  ofVec2f v2 = v1.rotateRad(PI/2);
  BOOST_CHECK_EQUAL(-4.37113883e-08f, v1.x);
  BOOST_CHECK_EQUAL(1.0f, v1.y);
  BOOST_CHECK_EQUAL(-4.37113883e-08f, v2.x);
  BOOST_CHECK_EQUAL(1.0f, v2.y);

  // rotateRad PI/4 (=45) degrees
  ofVec2f v3 = v1.rotateRad(PI/4);
  BOOST_CHECK_EQUAL(-0.707106829f, v3.x);
  BOOST_CHECK_EQUAL(0.707106709f, v3.y);
}

BOOST_AUTO_TEST_CASE(rotateRad_1)
{
  // numerical imprecisions since float
  // is used internally
  ofVec2f v1(1, 0);
  ofVec2f p(0, 1);
  BOOST_CHECK_EQUAL(1.0f, v1.x);
  BOOST_CHECK_EQUAL(0.0f, v1.y);

  // rotateRad PI/4 (=45) degrees, but non-center pivot
  ofVec2f v2 = v1.rotateRad(PI/4, p);
  BOOST_CHECK_EQUAL(sqrtf(2.0f), v1.x);
  BOOST_CHECK_EQUAL(1.0f, v1.y);
  BOOST_CHECK_EQUAL(sqrtf(2.0f), v2.x);
  BOOST_CHECK_EQUAL(1.0f, v2.y);
}

BOOST_AUTO_TEST_SUITE_END()
