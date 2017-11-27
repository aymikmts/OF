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
    // init CV
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
    background.setLearningTime(900);
    background.setThresholdValue(20);

    // GUI
    resetBackgroundButton.addListener(this, &ofApp::resetBackgroundPressed);
    gui.setup();
    gui.add(bgThresh.setup("background thresh", 50, 0, 100));
    gui.add(contourThresh.setup("contour finder thresh", 127, 0, 255));
    gui.add(resetBackgroundButton.setup("reset background"));
}

void ofApp::update() {
    cam.update();
    if (cam.isFrameNew()) {
        // �w�i�����摜�𐶐�
        background.setThresholdValue(bgThresh);
        background.update(cam, thresholded);
        thresholded.update();

        // �w�i�����̗֊s���o
        contourFinder.setThreshold(contourThresh);
        contourFinder.findContours(thresholded);
    }
}

void ofApp::draw() {
    // �����摜��`��
    ofSetColor(255);
    thresholded.draw(0, 0);
    // �֊s���o���ʂ�`��
    ofSetColor(255, 0, 0);
    contourFinder.draw();
    // GUI
    gui.draw();
}


void ofApp::resetBackgroundPressed() {
    background.reset();
}