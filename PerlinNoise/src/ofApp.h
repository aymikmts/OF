/**
* @date 2017/12/01
* @note ref: https://github.com/CreativeVisualization/ws_example17/blob/master/week03/14_PerlinNoise04
**/
#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Particles.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void scaleXChanged(float &scaleX);
        void scaleYChanged(float &scaleY);
        void updateNoise();

        const int PARTICLE_NUM = 4000;

        int width, height;
        ofImage myImage;
        unsigned char * pixels;
        //ofPixels pixels;
        int particleNum;
        Particles *particles;

        ofxPanel gui;
        ofxFloatSlider scaleX;
        ofxFloatSlider scaleY;
        ofxFloatSlider speed;
        ofxFloatSlider friction;
};
