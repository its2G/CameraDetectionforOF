#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofVideoGrabber cam;  // Video capture object
    ofxCvColorImage colorImg;   // Color image for OpenCV
    ofxCvGrayscaleImage grayImage;  // Grayscale image
    ofxCvGrayscaleImage grayBg;     // Background image
    ofxCvGrayscaleImage grayDiff;   // Difference image

    int threshold = 90;         // Threshold value for detecting motion
    bool bLearnBackground = true;  // Flag to learn background
};
