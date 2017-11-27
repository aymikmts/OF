/**
* @file     ofApp.h
* @author   aymikmts
* @date     2017/11/27
* @note     refs: https://drive.google.com/file/d/0BzyVHU69QO3mc2xSa2FkbkhfaFU/view
**/
#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    
    ofVideoGrabber cam;
    ofxCv::ContourFinder contourFinder;
};
