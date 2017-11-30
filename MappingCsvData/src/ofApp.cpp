/**
* @brief    OpenFrameworksの練習用
*           CSVファイルから緯度・経度を読み込み、ofVboMeshでマッピング
* @date     2017/11/30
* @note
*   refs: http://yoppa.org/tau_media17
*   refs: https://github.com/CreativeVisualization/ws_example17/tree/master/week03/09_randomWalkerGiui
**/
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);

    ofSetCircleResolution(4);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    static GLfloat distance[] = { 0.0,0.0,1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(1500);

#if 0
    // log level
    ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE);

    // read csv file
    if (csv.load("airports-extended.dat")) {
        // output all data to log
        for (int i = 0; i < csv.getNumRows(); i++) {
            // get line data
            ofxCsvRow row = csv[i];

            // read position
            float latitude = row.getFloat(6);
            float longitude = row.getFloat(7);
            string type = row.getString(12);

            cout << i << ": latitude = " << latitude;
            cout << ", longitude = " << longitude;
            cout << ", type = "<< type << endl;
        }
    }
#else
    csv.load("airports-extended.dat");
#endif

    mesh.clear();

    for (int i = 0; i < csv.getNumRows(); i++) {
        // get line data
        ofxCsvRow row = csv[i];

        ofFloatColor color;
        string type = row.getString(12);
        if (type == "airport") {
            color = ofFloatColor(0.2, 0.5, 1.0);
        }
        else if (type == "station") {
            color = ofFloatColor(1.0, 0.5, 0.2);
        }
        else if (type == "port")
        {
            color = ofFloatColor(0.5, 1.0, 0.2);
        }
        else {
            color = ofFloatColor(0.8);
        }

        // read position
        ofQuaternion latRot, longRot, spinQuat;
        latRot.makeRotate(row.getFloat(6), 1, 0, 0);
        longRot.makeRotate(row.getFloat(7), 0, 1, 0);
        spinQuat.makeRotate(ofGetFrameNum(), 0, 1, 0);

        ofVec3f radius = ofVec3f(0, 0, 300);
        ofVec3f worldPoint = latRot * longRot * spinQuat * radius;

        mesh.addColor(color);
        mesh.addVertex(worldPoint);
    }

    mesh.draw();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {

    ofVec2f airportLoc;

    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateY(ofGetFrameNum()/100);
    mesh.draw();
    ofPopMatrix();

    ofSetColor(255);
    ofDrawBitmapStringHighlight("fps = " + ofToString(ofGetFrameRate()), 20, 20);

}
