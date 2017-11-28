/**
* @brief    OpenFrameworksÇÃó˚èKóp
* @date     2017/11/28
* @note
*   refs: http://yoppa.org/tau_media17
*   refs: https://github.com/CreativeVisualization/ws_example17/tree/master/week03/09_randomWalkerGiui
**/
#include "ofApp.h"

//using namespace ofxCv;
//using namespace cv;

void ofApp::setup() {
    
    // init window
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);

    // set mesh mode
    mesh.setMode(OF_PRIMITIVE_POINTS);

    // init gui
    gui.setup();
    gui.add(size.setup("pint size", 2.0, 0.0, 4.0));
    gui.add(pointAlpha.setup("pint alpha", 35, 0, 63));
    gui.add(bgAlpha.setup("background alpha", 10, 0, 31));

#if 0
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
#endif
}

void ofApp::update() {
#if 0
    cam.update();
    if (cam.isFrameNew()) {
        // îwåiç∑ï™âÊëúÇê∂ê¨
        background.setThresholdValue(bgThresh);
        background.update(cam, thresholded);
        thresholded.update();

        // îwåiç∑ï™ÇÃó÷äsíäèo
        contourFinder.setThreshold(contourThresh);
        contourFinder.findContours(thresholded);
    }
#endif
}

void ofApp::draw() {

    // fadeout
    ofSetColor(0, 0, 0, bgAlpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

    // set point color
    ofSetColor(255, pointAlpha);

    // reflesh
    mesh.clear();

    // draw RandomWalker
    glPointSize(size);
    for (int i = 0; i < NUM; i++) {
        walker[i].draw();
        ofVec3f pos = ofVec3f(walker[i].position.x, walker[i].position.y, 0);
        mesh.addVertex(pos);
    }
    mesh.draw();
    gui.draw();

#if 0
    // ç∑ï™âÊëúÇï`âÊ
    ofSetColor(255);
    thresholded.draw(0, 0);
    // ó÷äsíäèoåãâ Çï`âÊ
    ofSetColor(255, 0, 0);
    contourFinder.draw();
    // GUI
    gui.draw();
#endif
}

#if 0
void ofApp::resetBackgroundPressed() {
    background.reset();
}
#endif

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    for (int i = 0; i < NUM; i++) {
        walker[i].position.set(ofGetWidth() / 2, ofGetHeight() / 2);
    }
}