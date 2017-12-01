/**
* @date 2017/11/30
* @note ref: https://github.com/CreativeVisualization/ws_example17/blob/master/week03/14_PerlinNoise04
**/
#pragma once
#include "ofMain.h"

class Particles {
public:
    Particles(int maxParticles);
    void update();
    void draw();
    void addParticle(ofVec2f position,
        ofVec2f velocity = ofVec2f(0, 0),
        ofColor color = 0xffffff);
    void resetForce();
    void addForce(int count, ofVec2f force);
    void addDampingForce();
    void resetOffWalls();
    void updatePos();

    int maxParticles;
    float pointSize;

    int numParticles;
    deque<ofVec2f> positions;
    deque<ofVec2f> velocitys;
    deque<ofVec2f> forces;
    deque<ofColor> colors;
    float friction;

    ofVboMesh mesh;
};