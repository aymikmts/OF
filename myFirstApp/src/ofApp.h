/**
* @file     ofApp.h
* @author   aymikmts
* @date     2017/11/27
* @note     refs: https://drive.google.com/file/d/0BzyVHU69QO3mc2xSa2FkbkhfaFU/view
**/
#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void resetBackgroundPressed();
    
    ofVideoGrabber cam;
    ofxCv::ContourFinder contourFinder;
    ofxCv::RunningBackground background;
    ofImage thresholded;

    ofxPanel gui;
    ofxFloatSlider bgThresh;            // �w�i������臒l
    ofxFloatSlider contourThresh;       // �֊s���o��臒l
    ofxButton resetBackgroundButton;    // �w�i���Z�b�g�{�^��
};
