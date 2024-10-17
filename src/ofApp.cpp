#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    mySound.load("zombies.mp3");

    camWidth = 640 ;  // Set the width of the camera
    camHeight = 480; // Set the height of the camera

    vidGrabber.setDeviceID(1);  // Use the first available device
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);

    // Allocate space for imagesc
    prevFrame.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
    diffFrame.allocate(camWidth, camHeight, OF_IMAGE_COLOR);

    ofSetVerticalSync(true); // Synchronize the frame rate with the screen's refresh rate

    motionDetected = false;
    motionThreshold = 1000;  // Adjust this value based on your needs


}

//--------------------------------------------------------------
void ofApp::update() {
    vidGrabber.update();

    if (vidGrabber.isFrameNew()) {
        ofPixels& currentPixels = vidGrabber.getPixels();

        if (prevFrame.isAllocated()) {
            int numChangedPixels = 0;  // Counter for changed pixels

            for (int y = 0; y < camHeight; y++) {
                for (int x = 0; x < camWidth; x++) {
                    ofColor currentColor = currentPixels.getColor(x, y);
                    ofColor prevColor = prevFrame.getColor(x, y);

                    int threshold = 60;

                    int diffR = abs(currentColor.r - prevColor.r);
                    int diffG = abs(currentColor.g - prevColor.g);
                    int diffB = abs(currentColor.b - prevColor.b);

                    if (diffR < threshold) diffR = 0;
                    if (diffG < threshold) diffG = 0;
                    if (diffB < threshold) diffB = 0;

                    // If any channel difference exceeds the threshold, count it as a changed pixel
                    if (diffR > 0 || diffG > 0 || diffB > 0) {
                        numChangedPixels++;
                    }

                    diffFrame.setColor(x, y, ofColor(diffR, diffG, diffB));
                }
            }
            diffFrame.update();

            // Determine if motion is detected based on the number of changed pixels
            if (numChangedPixels > motionThreshold) {
                motionDetected = true;
            }
            else {
                motionDetected = false;
            }
        }

        // Store the current frame as the previous frame for the next iteration
        prevFrame.setFromPixels(currentPixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    vidGrabber.draw(0, 0);          // Draw the original video frame
    diffFrame.draw(camWidth, 0);    // Draw the difference frame next to the original

    if (!motionDetected) {
        


        ofResetElapsedTimeCounter();  // Reset the timer when motion is detected after 5 seconds
        float Timer = ofGetElapsedTimef();  // Store the start time

    }



    if (motionDetected) {
        float lastResetTime = 0;
        static bool hasRun = false;  // Declare a flag to check if the code has already run


        ofSetColor(255, 0, 0);  // Set text color to red
        ofDrawBitmapString("Motion Detected!", camWidth / 2 - 50, camHeight + 20);
        ofSetColor(255);  // Reset color to white

        float currentTime = ofGetElapsedTimef();  // Get the current time


        if (ofGetElapsedTimef() - lastResetTime >= 2.0)
        {
            if (!hasRun)
            {
                system("python send_email.py");
                cout << "Sending Email...";
                hasRun = true;  // Set the flag to true so it won't run again
                mySound.play();

                lastResetTime = currentTime;  // Update lastResetTime after sending the email

                 

            }
  
               
            else if (ofGetElapsedTimef() - lastResetTime >= 5.0)
            {

                hasRun = false;

            }
            

        }
        float Timer = ofGetElapsedTimef();  // Store the start time
        cout << Timer << endl;    // print integerx
    }


    
    //else if (motionDetected > ) {

    //}
}
