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
    ofxFloatSlider bgThresh;            // 背景差分の閾値
    ofxFloatSlider contourThresh;       // 輪郭抽出の閾値
    ofxButton resetBackgroundButton;    // 背景リセットボタン
};
