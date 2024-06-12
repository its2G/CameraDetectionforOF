#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setDeviceID(2);  // Set to your device ID
    cam.setDesiredFrameRate(30);
    cam.initGrabber(640, 480);

    colorImg.allocate(640, 480);
    grayImage.allocate(640, 480);
    grayBg.allocate(640, 480);
    grayDiff.allocate(640, 480);
}

//--------------------------------------------------------------
void ofApp::update() {
    cam.update();

    if (cam.isFrameNew()) {
        colorImg.setFromPixels(cam.getPixels());
        grayImage = colorImg;

        if (bLearnBackground) {
            grayBg = grayImage;  // Capture the background
            bLearnBackground = false;
        }

        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);

        if (grayDiff.countNonZeroInRegion(0, 0, grayDiff.getWidth(), grayDiff.getHeight()) > 1000) {
            // Motion detected, implement your notification logic here
            ofLog() << "Motion Detected!";
            // You can add more advanced notifications here
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(255);
    cam.draw(20, 20);
    grayImage.draw(680, 20);
    grayBg.draw(20, 520);
    grayDiff.draw(680, 520);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'b') {
        bLearnBackground = true;
    }
}
