#include "ofApp.h"

void ofApp::setup(){
  ofFbo fbo;
  fbo.allocate(1920, 1080, GL_RGBA);
  fbo.begin();
  ofClear(0, 0, 0);
  fbo.end();

  ofFloatPixels pixels;
  fbo.readToPixels(pixels);
  pixels.resize(1920 / 4, 1080 / 4);
}

void ofApp::draw(){
  ofFbo fbo;
  fbo.allocate(1920, 1080, GL_RGBA);
  fbo.begin();
  ofClear(0, 0, 0);
  fbo.end();

  ofFloatPixels pixels;
  fbo.readToPixels(pixels);
  pixels.resize(1920 / 4, 1080 / 4);
}
