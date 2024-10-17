#pragma once
#include <cstdlib>  // Include the library for system()
#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

private:
    ofVideoGrabber vidGrabber;     // Video grabber for the camera input
    ofImage prevFrame;             // To store the previous frame
    ofImage diffFrame;             // To store the difference between frames
    int camWidth;
    int camHeight;

    ofSoundPlayer   mySound;

    bool motionDetected;  // A flag to indicate whether motion is detected
    int motionThreshold;  // A threshold for detecting significant motion
};
