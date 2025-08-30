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

    // fadein: 0.5, static: 1.0, fadeout: 0.5, delta: 100
    ofxFade::delta<float>(t, 0.5f, 1.0f, 0.5f, 100.0f, [](float delta){
        ofSetColor(255, 0, 0);
        ofDrawEllipse(100, 100 + delta, 100, 100);
    });

    // fadein: 0.5, static: 1.0, fadeout: 0.5, delta: 100
    ofxFade::delta<float>(t, 0.5f, 1.0f, 0.5f, 100.0f, [](float delta, float alpha){
        ofSetColor(255, 0, 0, alpha);
        ofDrawEllipse(220, 100 + delta, 100, 100);
    });

    // fadein: 0.5, static: 1.0, fadeout: 0.5, delta: (30, 100)
    ofxFade::delta<ofVec2f>(t, 0.5f, 1.0f, 0.5f, ofVec2f(30, 100), [](ofVec2f delta, float alpha){
        ofSetColor(255, 0, 0, alpha);
        ofDrawEllipse(340 + delta.x, 100 + delta.y, 100, 100);
    });

    // fadein: 0.5, static: 1.0, fadeout: 0.5
    ofxFade::advanced(t, 0.5f, 1.0f, 0.5f, [](float r, float rt, ofxFade::Phase phase){
        const float x = 460;

        std::string s1 = "rateEasing: " + ofToString(r, 2);
        ofDrawBitmapString(s1, x, 50);

        std::string s2 = "rateTime: " + ofToString(rt, 2);
        ofDrawBitmapString(s2, x, 100);

        std::string s3 = ofxFade::phaseToString(phase);
        ofDrawBitmapStringHighlight(s3, x, 150);

        ofSetColor(100);
        ofDrawRectangle(x, 60, 100, 4);

        ofSetColor(255);
        ofDrawRectangle(x, 60, 100 * r, 4);

        ofSetColor(100);
        ofDrawRectangle(x, 110, 100, 4);

        ofSetColor(255);
        ofDrawRectangle(x, 110, 100 * rt, 4);
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
