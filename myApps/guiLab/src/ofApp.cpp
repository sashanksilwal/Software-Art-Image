#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(intSlider.setup("start value", 64, 3, 100));
    gui.add(floatSlider.setup("float slider", 20.0, 0.0, 100.0));
    
    gui.add(toggle.setup("Toggle",true));
    gui.add(button.setup("button"));
    
    gui.add(label.setup("label", "this is a label"));
    
    gui.add(intField.setup("Int Field", 30, 0,100));
    gui.add(floatField.setup("floatField", 80.0, 0.0, 1000));
    gui.add(textField.setup("Text Field", "Text"));
    
    gui.add(vec2slider.setup("Vec 2 slider", ofVec2f(1.0, 100.0), ofVec2f(0,0), ofVec2f(ofGetWindowWidth(), ofGetWindowHeight())));
    
    gui.add(vec3slider.setup("Vec 3 slider", ofVec3f(100,90,80), ofVec3f(0,0,0), ofVec3f(255,255,255)));
    
    gui.add(vec4slider.setup("Vec 4 slider", ofVec4f(0,0,0,0), ofVec4f(0,0,0,0), ofVec4f(255,255,255,255)));
    
    
    size = 10;
    x1 = 0;
    y1 = 0;
    x2 = 100;
    y2 = 100;
    ofSetFrameRate(15);
}

//--------------------------------------------------------------
void ofApp::update(){
    myLine.addVertex( ofRandom(ofGetWindowWidth()),   ofRandom(ofGetWindowHeight()));
}

//--------------------------------------------------------------
void ofApp::draw(){
//    int speedDivisor = 10;
//
//    if(ofGetFrameNum() % speedDivisor != 0)
//    {
//        return;
//    }
    
    if (button){
        ofSetColor(ofRandom(vec3slider -> x), ofRandom(vec3slider -> y),ofRandom(vec3slider -> z));
    }
    ofDrawCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 128);
    ofSetCircleResolution(intSlider);
    ofSetColor(vec4slider->x, vec4slider->y, vec4slider->z, vec4slider->w);
    ofDrawCircle(vec2slider->x, vec2slider->y, 123);
    gui.draw();
//    ofColor ofDrawCol;
//    ofDrawCol.setHsb(155,155,155,80);
   
//    ofSetLineWidth(size);
//    myLine.draw();
//    x2 = int(x2+ ofRandom(ofGetWindowWidth())) %  ofGetWindowWidth();
//    y2 = int(y2+ofRandom(ofGetWindowHeight())) % ofGetWindowHeight();
//    ofDrawLine(x1, y1,x2,y2);
//    x1 = x2;
//    y1 = y2;
//    ofDrawLine(ofGetWindowWidth(), 0,ofGetWindowWidth()- x2,ofGetWindowHeight() -y2);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f'){
        ofToggleFullscreen();
    }
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
