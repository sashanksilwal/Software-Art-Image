#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(10);
    gui.setup();
    gui.add(label.setup("label", "You can change the thickness below"));
    gui.add(intSlider.setup("Thickness", 64, 3, 100));
    gui.add(toggle.setup("Multiple Lines",false));
    gui.add(button.setup("Randomize Color"));
    gui.add(label.setup("label", "You can change the color below"));
    gui.add(vec4slider.setup("Change Color", ofVec4f(30,130,140,150), ofVec4f(0,0,0,100), ofVec4f(255,255,255,255)));
    gui.add(vec3slider.setup("Change Color of Additional Lines", ofVec3f(100,90,80), ofVec3f(0,0,0), ofVec3f(255,255,255)));
    
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
 
    ofSetLineWidth(intSlider);
//    myLine.draw();
    if (toggle){
        ofSetColor(vec3slider->x, vec3slider->y, vec3slider->z );
        ofDrawLine(ofGetWindowWidth()-x1, ofGetWindowHeight()-y1,x2,y2);
        ofDrawLine(ofGetWindowWidth()-x1, ofGetWindowHeight()-y1,ofGetWindowWidth() - x2,ofGetWindowHeight() - y2);
    }
    ofSetColor(vec4slider->x, vec4slider->y, vec4slider->z, vec4slider->w);
    
    if (button){
        ofSetColor(ofRandom(vec4slider -> x), ofRandom(vec4slider -> y),ofRandom(vec4slider -> z),255);
    }
    
    x2 = int(x2+ ofRandom(ofGetWindowWidth())) %  ofGetWindowWidth();
    y2 = int(y2+ofRandom(ofGetWindowHeight())) % ofGetWindowHeight();
    
    x1 = x2;
    y1 = y2;
    
    ofDrawLine(x1, y1,x2,y2);
    ofDrawLine(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()),ofGetWindowWidth() - x2,ofGetWindowHeight() - y2);
    gui.draw();
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
