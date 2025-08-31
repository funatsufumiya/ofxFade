#include "ofApp.h"

#include "ofxFade.h"

ofxFade::InteractiveFader fader;

//--------------------------------------------------------------
void ofApp::setup(){
    // fadein = 1.0, fadeout = 1.0 (sec)
    fader = ofxFade::InteractiveFader(1.0f, 1.0f);
    fader.start();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    fader.alpha([](float a){
        ofSetColor(255, 0, 0, a);
        ofDrawEllipse(100, 100, 100, 100);
    });

    ofDrawBitmapString("click to toggle fade", 100, 100);
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
    if(fader.isStarted() && !fader.isFadeOutStarted()){
        fader.fadeOut();

        // NOTE: fader.fadeOut() normally execute fade-out soon (keeping fade-in rate)
        //       if immediate = false, execute fade-out after fade-in
    }else if(fader.isFinished()){
        fader.start();
    }
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
