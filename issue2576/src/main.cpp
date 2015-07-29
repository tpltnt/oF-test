#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ofXml_test
#include "ofGraphics.h"
#include "ofFbo.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(issue2576)

/* If you call the resize method on an ofFloatPixels object
   you get a memory access issue with either method of
   resizing (OF_INTERPOLATE_NEAREST_NEIGHBOR or OF_INTERPOLATE_BICUBIC)

   Temporary solution is to just use ofPixels

   This happens with 0.74 and the dev branch
 */

BOOST_AUTO_TEST_CASE(interpolate_nearest_neighbor)
{
  ofFbo fbo;
  fbo.allocate(1920, 1080, GL_RGBA);
  fbo.begin();
  ofClear(0, 0, 0);
  fbo.end();

  ofFloatPixels pixels;
  fbo.readToPixels(pixels);
  BOOST_CHECK( pixels.resize(1920 / 4, 1080 / 4, OF_INTERPOLATE_NEAREST_NEIGHBOR) );
}

BOOST_AUTO_TEST_CASE(interpolate_bilinear)
{
  ofFbo fbo;
  fbo.allocate(1920, 1080, GL_RGBA);
  fbo.begin();
  ofClear(0, 0, 0);
  fbo.end();

  ofFloatPixels pixels;
  fbo.readToPixels(pixels);
  BOOST_CHECK( pixels.resize(1920 / 4, 1080 / 4, OF_INTERPOLATE_BILINEAR) );
}

BOOST_AUTO_TEST_CASE(interpolate_bicubic)
{
  ofFbo fbo;
  fbo.allocate(1920, 1080, GL_RGBA);
  fbo.begin();
  ofClear(0, 0, 0);
  fbo.end();

  ofFloatPixels pixels;
  fbo.readToPixels(pixels);
  BOOST_CHECK( pixels.resize(1920 / 4, 1080 / 4, OF_INTERPOLATE_BICUBIC) );
}

BOOST_AUTO_TEST_SUITE_END()
