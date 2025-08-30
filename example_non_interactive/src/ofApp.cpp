#include "ofApp.h"

#include "ofxFade.h"

ofxFade::NonInteractiveFader fader;

//--------------------------------------------------------------
void ofApp::setup(){
    // fadein = 1.0, static = 1.0, fadeout = 0.5 (sec)
    fader = ofxFade::NonInteractiveFader(1.0f, 1.0f, 0.5f);
    fader.start();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    fader.delta<float>(100, [](float delta, float alpha){
        ofSetColor(255, 0, 0, alpha);
        ofDrawEllipse(220, 100 + delta, 100, 100);
    }, ofxeasing::Function::Bounce, ofxeasing::Type::Out,
        ofxeasing::Function::Linear, ofxeasing::Type::In);

    // if(fader.isFinished()){
        ofDrawBitmapString("click to restart", 400, 100);
    // }
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
    // if(fader.isFinished()){
        fader.start();
    // }
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
