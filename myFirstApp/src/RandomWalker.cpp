#include "RandomWalker.h"


RandomWalker::RandomWalker() {

    // set initial position
    position.x = ofGetWidth()/2.0;
    position.y = ofGetHeight()/2.0;

    // set moving rate to random
    left = ofRandom(1.0);
    right = ofRandom(1.0);
    top = ofRandom(1.0);
    bottom = ofRandom(1.0);
}

void RandomWalker::draw() {

    for (int i = 0; i < 10; i++) {

        // move random
        position.x += ofRandom(-left, right);
        position.y += ofRandom(-top, bottom);

        // circle appears to opposite side when it reach to edge
        if (position.x < 0) {
            position.x = ofGetWidth();
        }
        if (position.x > ofGetWidth()) {
            position.x = 0;
        }
        if (position.y < 0) {
            position.y = ofGetHeight();
        }
        if (position.y > ofGetHeight()) {
            position.y = 0;
        }
    }
}