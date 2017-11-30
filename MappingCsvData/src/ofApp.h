/**
* @brief    OpenFrameworksの練習用
*           CSVファイルから緯度・経度を読み込み、ofVboMeshでマッピング
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
