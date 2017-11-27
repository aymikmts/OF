/**
* @file     ofApp.cpp
* @author   aymikmts
* @date     2017/11/27
* @note     refs: https://drive.google.com/file/d/0BzyVHU69QO3mc2xSa2FkbkhfaFU/view
**/
#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
}

void ofApp::update() {
    cam.update();
    if (cam.isFrameNew()) {
        contourFinder.setThreshold(ofMap(mouseX, 0, ofGetWidth(), 0, 255));
        contourFinder.findContours(cam);
    }
}

void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    contourFinder.draw();
}
