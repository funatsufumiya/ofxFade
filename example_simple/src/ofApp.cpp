#include "ofApp.h"

#include "ofxFadeHelper.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float t = std::fmodf(ofGetElapsedTimef(), 2.0f);

    // fadein: 0.5, static: 1.0, fadeout: 0.5
    ofxFadeHelper::alpha(t, 0.5f, 1.0f, 0.5f, [](float a){
        ofSetColor(255, 0, 0, a);
        ofDrawEllipse(100, 100, 100, 100);
    });

    // fadein: 0.5, static: 1.0, fadeout: 0.5
    ofxFadeHelper::simple(t, 0.5f, 1.0f, 0.5f, [](float r, ofxFadeHelper::Phase phase){
        std::string s1 = "r: " + ofToString(r, 2);
        ofDrawBitmapString(s1, 200, 50);

        std::string s2 = ofxFadeHelper::phaseToString(phase);
        ofDrawBitmapStringHighlight(s2, 200, 150);

        ofSetColor(100);
        ofDrawRectangle(200, 60, 100, 4);

        ofSetColor(255);
        ofDrawRectangle(200, 60, 100 * r, 4);
    });
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
