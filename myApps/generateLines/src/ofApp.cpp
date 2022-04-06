#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(10);
    gui.setup();
    gui.add(label.setup("label", "You can change the thickness below"));
    gui.add(toggle.setup("Multiple Lines",false));
    gui.add(button.setup("Randomize Color"));
    gui.add(label.setup("label", "You can change the color below"));
    gui.add(vec4slider.setup("Change Color", ofVec4f(208,130,140,150), ofVec4f(0,0,0,100), ofVec4f(255,255,255,255)));
    gui.add(vec3slider.setup("Change Color of Additional Lines", ofVec3f(25,200,180), ofVec3f(0,0,0), ofVec3f(255,255,255)));
    gui.add(intSlider.setup("No Lines", 360, 10, 720));
    
    size = 10;
    x1 = 0;
    y1 = 0;
    x2 = 100;
    y2 = 100;
    
    
    radius = 0;
    minRadius = 200;
    maxRadius = 400;
     
 }

//--------------------------------------------------------------
void ofApp::update(){
    
 }

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor c;
    if (toggle){
        for (int i = 1; i < intSlider; i++) {
            ofSetColor(vec3slider->x, vec3slider->y, vec3slider->z );
            ofDrawLine(ofGetWindowWidth()/2, ofGetWindowHeight()/2,ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
        }
    }
    ofSetColor(vec4slider->x, vec4slider->y, vec4slider->z, vec4slider->w);
    
   
    
    for (int i = 1; i < intSlider; i++) {
        radius =   minRadius;
         
        deg +=  1;
        
        radian = (TWO_PI / 360) * (deg % 360);
        location.x = radius * cos(radian);
        location.y = radius * sin(radian);
        
        c.setHsb(ofMap(radian, 0, TWO_PI, 0, 255), 255, ofMap(radius, minRadius, maxRadius, 0, 255), 255);
        ofSetColor(c);
        
        if (button){
            ofSetColor(ofRandom(vec4slider -> x), ofRandom(vec4slider -> y),ofRandom(vec4slider -> z),255);
        }
        ofDrawLine(ofGetWindowWidth()/2, ofGetWindowHeight()/2, ofGetWindowWidth()/2+location.x, ofGetWindowHeight()/2+location.y);
    }
   
 
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f'){
        ofToggleFullscreen();
    }
    if (key == ' '){
        imageScreenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        imageScreenshot.save("screenshot" + ofToString(cnt) + ".png");
        cnt ++;
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
