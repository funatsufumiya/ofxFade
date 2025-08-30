#include "ofApp.h"

#include "ofxFade.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // loop time: 2.5 (sec)
    float t = std::fmodf(ofGetElapsedTimef(), 2.5f);

    // fadein: 0.5, static: 1.0, fadeout: 0.5
    ofxFade::alpha(t, 0.5f, 1.0f, 0.5f, [](float a){
        ofSetColor(255, 0, 0, a);
        ofDrawEllipse(100, 100, 100, 100);
    });

    //
    // Text and indicators (Advanced usage)
    //

    // fadein: 0.5, static: 1.0, fadeout: 0.5
    ofxFade::advanced(t, 0.5f, 1.0f, 0.5f, [](float rateEasing, float rateTime, ofxFade::Phase phase){
        std::string s1 = "rateEasing: " + ofToString(rateEasing, 2);
        ofDrawBitmapString(s1, 200, 50);

        std::string s2 = "rateTime: " + ofToString(rateTime, 2);
        ofDrawBitmapString(s2, 200, 100);

        std::string s3 = ofxFade::phaseToString(phase);
        ofDrawBitmapStringHighlight(s3, 200, 150);

        ofSetColor(100);
        ofDrawRectangle(200, 60, 100, 4);

        ofSetColor(255);
        ofDrawRectangle(200, 60, 100 * rateEasing, 4);

        ofSetColor(100);
        ofDrawRectangle(200, 110, 100, 4);

        ofSetColor(255);
        ofDrawRectangle(200, 110, 100 * rateTime, 4);
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
