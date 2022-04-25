#pragma once

#include "ofMain.h"
class particle{
public:
    float size;
    glm::vec2 force, position, direction;
    
    void update();
    void draw();
    ofColor color;
    
    particle(int x, int y, int hue);
    ~particle();
};


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void saveImage(string filename);
    
    ofSoundPlayer mp3Audio;
    float* soundSpectrum;
    float* fft_decay;
    int bandsToGet;
    float decay;
    bool b_gui;
    
    vector<particle> particles;
    int hue;
    
    ofImage imageScreenshot;
    string timestampedFilename();
    
    int choice;
};
