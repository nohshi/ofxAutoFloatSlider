#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup();
    gui.add(slider.setup("slider", 0, 0, 1));
    gui.add(autoSlider.setup("autoSlider", 0, 0, 1));
    
    autoSlider.speed = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    autoSlider.update();
    cout << autoSlider.getRate() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    float r = 400;
    ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, autoSlider * r);
    gui.draw();
    
    ofSetColor(0);
    ofDrawBitmapString("RIGHT click on gui bar : autoSlider.swicth_FORWARD_STOP();", 10, 100);
    ofDrawBitmapString("press key LEFT  :  autoSlider.swicth_BACK_STOP();", 10, 120);
    ofDrawBitmapString("press key RIGHT :  autoSlider.swicth_FORWARD_STOP();", 10, 140);
    ofDrawBitmapString("press key DOWN  :  autoSlider.mode = ofxAutoFloatSlider::STOP;", 10, 160);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT)  autoSlider.swicth_BACK_STOP();
    if (key == OF_KEY_RIGHT) autoSlider.swicth_FORWARD_STOP();
    if (key == OF_KEY_DOWN)  autoSlider.mode = ofxAutoFloatSlider::STOP;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
