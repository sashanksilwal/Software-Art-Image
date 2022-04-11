#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
   
    gui.add(clearAlpha.setup("Set Alpha", 20, 0, 255));
    gui.add(colorVal.setup("Color Rep", 10, 1, 30));
    gui.add(rotation.setup("Rotation", 0.45, 0, 1));

    
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(255);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
   

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /*
     * Some code below are from
     * http://openframeworks.kr/ofBook/chapters/intro_to_graphics.html
     *
     */
    ofColor darkColor(0,0,0,255);  // Opaque black
     
    ofColor bgColor = darkColor;
    bgColor.a = clearAlpha;
     
    // Semi-clear the screen, using a transparent rectangle
    ofSetColor(bgColor);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    // Draw the spiraling rectangles
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    gui.draw();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i=0; i<100; i++) {
        
        int val = i;
        val = val % colorVal;
        ofColor c;
        
        c.setHsb(ofMap(val, 0, 10, 0, 255), 255, 255, 255);
        ofSetColor(c);
        ofNoFill();
        
        // Draw the smallest rectangle first and scale out to bigger ones progressively
        ofScale(1.1, 1.1);

        
        float noise = ofSignedNoise(rotation) * 20.0;
        ofRotate(noise);

        ofDrawRectangle(0, 0, 50, 50);
    }
 
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
