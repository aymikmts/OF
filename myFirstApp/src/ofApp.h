/**
* @brief    OpenFrameworks�̗��K�p
* @date     2017/11/28
* @note
*   refs: http://yoppa.org/tau_media17
*   refs: https://github.com/CreativeVisualization/ws_example17/tree/master/week03/09_randomWalkerGiui
**/
#pragma once

#include "ofMain.h"
//#include "ofxCv.h"
#include "ofxGui.h"
#include "RandomWalker.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

    void keyPressed(int key);
//    void resetBackgroundPressed();
#if 0  
    ofVideoGrabber cam;
    ofxCv::ContourFinder contourFinder;
    ofxCv::RunningBackground background;
    ofImage thresholded;

    ofxPanel gui;
    ofxFloatSlider bgThresh;            // �w�i������臒l
    ofxFloatSlider contourThresh;       // �֊s���o��臒l
    ofxButton resetBackgroundButton;    // �w�i���Z�b�g�{�^��
#endif

    static const int NUM = 100;
    RandomWalker walker[NUM];

    ofxPanel gui;
    ofxFloatSlider size;
    ofxFloatSlider pointAlpha;
    ofxFloatSlider bgAlpha;
    ofVboMesh mesh;
};
