#include "ofApp.h"

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(30);
    
    // setting the sound input
    fft.setup();
    
    //initializing the bool values
    showGraph = true;
    clearScreen = false;
    
    //setting the background
    ofBackground(0,0,0);
    ofSetBackgroundAuto(false);
    
    
    ofSetLineWidth(2);
    ofNoFill();
    
    //setting the default art to display
    artChoice = 2;
    
    //setting the delay time
    sucessTimeDelta = 2000;
}

void ofApp::update() {
    fft.update();
    ofSeedRandom(39);
}

void ofApp::draw() {
    
    if (showGraph){
        // letting the user choose the art
            // 0 for the circle pattern
            // 1 for experimental circle and image
            // 2 for image art
        
        if (artChoice == 0){
            fft.soundArt();}
        else if(artChoice == 1){
            fft.experiment();}
        else
            fft.soundArtImage();
    }
    // code to clear the screen
    if (clearScreen){
        
        ofPushMatrix();
        ofPushStyle();
        
        // code to delay time by sucessTimeDelta
        float time = ofGetElapsedTimef();
        actualTime = ofGetElapsedTimeMillis();
        if (actualTime - time > sucessTimeDelta) {
            actualTime = ofGetElapsedTimeMillis();
            ofClear(0,255);
        }
        ofSetColor(0, 0, 0, 30);
        
        // code to clear the screen
        ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        clearScreen = false;
        ofPopMatrix();
        ofPopStyle();
    }
}

void ofApp::keyPressed(int key){
    int volRange = fft.getVolumeRange();
    
    switch(key){
        case 't':
            showGraph = !showGraph;
            break;
//        case 's':
//            clearScreen = !clearScreen;
//            break;
            
        // press spacebar to change between the art syles
        case ' ':
            artChoice = (artChoice + 1) % 2;
            break;
            
        // press q to decrease the number of images used
        case 'q':
            if (fft.getNoImage() < 10) {break;}
            fft.setNoImage(fft.getNoImage() - 2);
            break;
            
        // increase the number of images used
        case 'w':
            if (fft.getNoImage() < 35)  
            fft.setNoImage(fft.getNoImage() +2);
            break;
            
        // press up to increase playback volume
        case OF_KEY_UP:
            
            
            if (volRange < 600){
                fft.setVolumeRange(fft.getVolumeRange()+5);
            }
            break;
            
        // press down to decrease playback volume
        case OF_KEY_DOWN:
             
            
            if (volRange > 10){
                fft.setVolumeRange(fft.getVolumeRange()-5);
            }
            break;
    
    }
    
}
