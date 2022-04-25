#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mp3Audio.load("audio0.mp3");
    mp3Audio.play();
    mp3Audio.setLoop(true);
    mp3Audio.setSpeed(1);
    
    bandsToGet = 50;
    
    b_gui = true;
    decay = 0.9f;
    ofSetBackgroundAuto(false);
    fft = new float[bandsToGet];
    for (int i = 0; i < bandsToGet; i++) {
        fft[i] = 0.0f;
    }
    
    choice = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    soundSpectrum = ofSoundGetSpectrum(bandsToGet);
    for (int i = 0; i < bandsToGet; i++) {
        fft[i] *= decay;
        
        
        
        
        
        if (fft[i] < soundSpectrum[i]) {
            fft[i] = soundSpectrum[i];
        }
        hue = ofRandom(255) ;
        if (fft[i] > 0.06){
            
            particle newParticles(ofGetWindowWidth()/2, ofGetWindowHeight()/2, hue);
            particles.push_back(newParticles);
        }
        
    
    }
    
//    for (int j=0; j< fft[0]; j++){
//    if (fft[i] > 0.05){
//        hue = ofRandom(255);
//        particle newParticles(ofGetWindowWidth()/2, ofGetWindowHeight()/2, hue);
//        particles.push_back(newParticles);
//    }
//
    
    for (int i=0; i<particles.size(); i++){
        particles[i].update();
         if (particles[i].size <= 0){
             particles.erase( particles.begin(), particles.begin()+i);
        }
    }
//    ofLog() << particles.size();

//    particles.erase( particles.begin(), particles.begin()+2 );
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 0, 0, 30);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    ofSetColor(255,255,255);
    
    if (b_gui){
        ofDrawBitmapString("Instructions:", 50, 100);
        ofDrawBitmapString("'g' to toggle instruction", 50, 120);
        ofDrawBitmapString("'f' to change screen size", 50, 140);
        ofDrawBitmapString("'s' to take screenshot", 50, 160);
    }
    
    int width = (ofGetWindowWidth()-100) / bandsToGet;
    
    
    for (int i = 0; i < bandsToGet; i++) {
        ofColor newColor;
        ofPushMatrix();
//        ofSetColor(0,120,220);
        newColor.setHsb(ofMap(i, 0, bandsToGet,   255, 0), 255, 255, 200);
        ofSetColor(newColor);
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofRotate(360.0 /bandsToGet*i);
        ofDrawRectangle(100, -20/2, 800*fft[i]+1, 10);
        
        ofPopMatrix();
    }
    for (int i=0; i<particles.size(); i++){
        particles[i].draw();
    }

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}
//--------------------------------------------------------------
string ofApp::timestampedFilename() {
    return ofGetTimestampString("color-%Y%m%d-%H%M%S-%i.png");
}

//--------------------------------------------------------------

void ofApp::saveImage(string filename) {
    imageScreenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    imageScreenshot.save(filename);
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key){
        case 'g':
            b_gui = !b_gui;
            break;
        case 'f':
            ofToggleFullscreen();
            break;
        case 's':
            string filename = this->timestampedFilename();
            ofLog(OF_LOG_NOTICE, "Saving image to %s", filename.c_str());
            this->saveImage(filename);
            break;
//        default:
//            break;
                
    }
    
        
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
//    choice = (choice + 1) % 2;
//    mp3Audio.load("audio1.mp3");
    
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
//--------------------------------------------------------------

particle::particle(int startX, int startY, int hue){
    position = glm::vec2(startX, startY);
    direction = glm::vec2(ofRandom(-2.0,2.0), ofRandom(-2.0,2.0));
    size = 20;
    color.setHsb(hue, 120, 255, 200);
}

void particle::update(){
    position += direction;
    
    if (size > 1){
        size -= 0.07;
    }
    
    float brightness  = color.getBrightness();
    if (brightness > 20){
        color.setBrightness(brightness -= 0.07);
    }
   
    
}

void particle::draw(){
    ofSetColor(color);
    ofDrawCircle(position,  size);
}

particle::~particle(){
    
}
