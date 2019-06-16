#pragma once

#include "ofMain.h"

#include "ofxCosineGradient.h"
#include "ofxImGui.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    
private:
    ofxCosineGradient mCosineGradient;

    ofxImGui::Gui mGui;
    glm::vec3 mBias { 0, 0, 0 };
    glm::vec3 mAmplitude { 0, 0, 0 };
    glm::vec3 mFrequency { 0, 0, 0 };
    glm::vec3 mPhase { 0, 0, 0 };
};
