#pragma once

#include "ofApp.h"
#include "ofxProcessFFT.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    
    // bools for displaying the graph and clearing the screen
    bool showGraph;
    bool clearScreen;
    
    // codes for further experimentation
    vector<ofPolyline> circlePolys;
    vector<glm::vec2> base_location_list;
    vector<vector<glm::vec3>> log_list;
    
    // choosing the art type
    int artChoice;
    
    // code for time delay
    unsigned long actualTime, sucessTimer;
    unsigned int sucessTimeDelta;
    
    // sound input
    ProcessFFT fft;

};
