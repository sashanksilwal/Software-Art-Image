#include "ofApp.h"

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    fft.setup();
    showGraph = true;
    clearScreen = false;
    ofBackground(0,0,0);
    ofSetLineWidth(2);
    ofNoFill();
    ofSetCircleResolution(30);
    ofSetBackgroundAuto(false);
    artChoice = 2;
    
    sucessTimeDelta = 2000;
    
    
}

void ofApp::update() {
    fft.update();
    ofSeedRandom(39);
    
  
}

void ofApp::draw() {
    if (showGraph){
        
        if (artChoice == 0){
            fft.soundArt();}
        else if(artChoice == 1){
            fft.experiment();}
        else
            fft.soundArtImage();
    }
    if (clearScreen){
        ofPushMatrix();
        ofPushStyle();
        float time = ofGetElapsedTimef();
        actualTime = ofGetElapsedTimeMillis();
        if (actualTime - time > sucessTimeDelta) {
            actualTime = ofGetElapsedTimeMillis();
            ofClear(0,255);
        }
        ofSetColor(0, 0, 0, 30);
        ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        clearScreen = false;
        ofPopMatrix();
        ofPopStyle();
    }
    
//    if (clearScreen && showGraph){
//        showGraph = false;
//        clearScreen = false;
//        ofPushMatrix();
//        ofSetColor(0, 0, 0, 30);
//        ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
//        ofNoFill();
//        ofPopMatrix();
//
//    }
    
    
    
    
    
}

void ofApp::keyPressed(int key){
    
    //toggle between normalized and not to get a sense of the effects
    //You will need to set a volume range if you're not normalizing everything - but this will depend on your sound source and input type to determine the maximum volume range of your codez
    
    //    if(key=='q'){
    //        fft.setVolumeRange(100);
    //        fft.setNormalize(false);
    //    }
    //    if(key=='r'){
    //        fft.setNormalize(true);
    //    }
    switch(key){
        case 't':
            showGraph = !showGraph;
            break;
//        case 's':
//            clearScreen = !clearScreen;
//            break;
        case ' ':
            artChoice = (artChoice + 1) % 2;
            break;
            
        case 'q':
            if (fft.getNoImage() < 10) {break;}
            fft.setNoImage(fft.getNoImage() - 2);
            break;
            
            
        case 'w':
            if (fft.getNoImage() < 35)  
            fft.setNoImage(fft.getNoImage() +2);
            break;
            
        // press up to increase playback volume
        case OF_KEY_UP:
            fft.setVolumeRange(fft.getVolumeRange()+5);
            
            break;
        // press down to decrease playback volume
        case OF_KEY_DOWN:
            int volRange = fft.getVolumeRange();
            
            if (volRange > 10){
                fft.setVolumeRange(fft.getVolumeRange()-5);
            }
            break;
        
     
            
    }
    
}
