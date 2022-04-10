#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
   
    gui.add(clearAlpha.setup("Clear Alpha", 20, 0, 255));
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
    
    
    ofColor darkColor(0,0,0,255);  // Opaque black
    ofColor lightColor(255,255,255,255);  // Opaque white
    
     
    ofColor bgColor = darkColor;  // Color for the transparent rectangle we use to clear the screen
    bgColor.a = clearAlpha;  // Our initial colors were opaque, but our rectangle needs to be transparent
     
     
    // Semi-clear the screen, using a transparent rectangle
    ofSetColor(bgColor);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());  // ofBackground doesn't work with alpha, so draw a transparent rect

    // Draw the spiraling rectangles
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    gui.draw();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);  // Translate to the center of the screen
    for (int i=0; i<100; i++) {
        int val = i;
        val = val % colorVal;
        ofColor c;
         c.setHsb(ofMap(val, 0, 10, 0, 255), 255, 255, 255);
        ofSetColor(c);
        ofNoFill();
        
        // Draw the smallest rectangle first and scale out to bigger ones progressively
        ofScale(1.1, 1.1);

        // Make the rectangles spiral
        float time = ofGetElapsedTimef();
        float noise = ofSignedNoise(rotation  ) * 20.0;
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
