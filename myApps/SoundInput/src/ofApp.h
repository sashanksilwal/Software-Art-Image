#pragma once

#include "ofApp.h"
#include "ofxProcessFFT.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    ProcessFFT fft;
    
    bool showGraph;
    bool clearScreen;
    
    vector<ofPolyline> circlePolys;
    
    vector<glm::vec2> base_location_list;
    vector<vector<glm::vec3>> log_list;
    
    int artChoice;
    
    unsigned long actualTime, sucessTimer;
    unsigned int sucessTimeDelta;

};
