/**
* @brief    OpenFrameworks�̗��K�p
*           CSV�t�@�C������ܓx�E�o�x��ǂݍ��݁AofVboMesh�Ń}�b�s���O
* @date     2017/11/30
* @note
*   refs: http://yoppa.org/tau_media17
*   refs: https://github.com/CreativeVisualization/ws_example17/tree/master/week03/09_randomWalkerGiui
**/
#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        ofxCsv csv;
        ofVboMesh mesh;
};
