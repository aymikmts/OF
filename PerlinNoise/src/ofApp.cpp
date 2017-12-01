/**
* @date 2017/12/01
* @note ref: https://github.com/CreativeVisualization/ws_example17/blob/master/week03/14_PerlinNoise04
**/
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // init window
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0);

    width = ofGetWidth();
    height = ofGetHeight();

    // allocate image
    myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
    pixels = myImage.getPixels().getData();

    // create particle
    particleNum = PARTICLE_NUM;
    particles = new Particles(particleNum);

    for (int i = 0; i < particleNum; i++) {
        ofVec3f position = ofVec3f(ofRandom(width), ofRandom(height));
        particles->addParticle(position);
    }

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            float noiseX = ofMap(i, 0, width, 0, scaleX);
            float noiseY = ofMap(j, 0, height, 0, scaleY);
            int noiseVal = ofNoise(noiseX, noiseY) * 255;
            pixels[j * width + i] = noiseVal;
        }
    }
    myImage.update();

    scaleX.addListener(this, &ofApp::scaleXChanged);
    scaleY.addListener(this, &ofApp::scaleYChanged);

    gui.setup();
    gui.add(speed.setup("speed", 0.1, 0.0, 0.5));
    gui.add(friction.setup("friction", 0.01, 0.0, 0.04));
    gui.add(scaleX.setup("scale x", 5.0, 1.0, 10.0));
    gui.add(scaleY.setup("scaleyx", 5.0, 1.0, 10.0));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    particles->friction = friction;
    particles->resetForce();
    for (int i = 0; i < particleNum; i++) {
        int n = int(particles->positions[i].y) * width + int(particles->positions[i].x);
        if (n < width*height) {
            int val = pixels[n];
            int angle = ofMap(val, 0, 255, 0, PI*2.0);
            ofVec3f force;
            force.x = cos(angle) * speed;
            force.y = sin(angle) * speed;
            particles->addForce(i, force);
        }
    }
    particles->addDampingForce();
    particles->updatePos();
    particles->resetOffWalls();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(0, 7);
    ofRect(0, 0, width, height);

    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255);
    particles->draw();

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::scaleXChanged(float &scaleX) {
    updateNoise();
}

void ofApp::scaleYChanged(float &scaleY) {
    updateNoise();
}

void ofApp::updateNoise() {

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            float noiseX = ofMap(i, 0, width, 0, scaleX);
            float noiseY = ofMap(j, 0, height, 0, scaleY);
            int noiseVal = ofNoise(noiseX, noiseY) * 255;
            pixels[j * width + i] = noiseVal;
        }
    }
}

