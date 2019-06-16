#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    mCosineGradient.init(ofGetWidth(), ofGetHeight());
    mGui.setup();
}

//--------------------------------------------------------------
void ofApp::update()
{
    mCosineGradient.setBias(mBias);
    mCosineGradient.setAmplitude(mAmplitude);
    mCosineGradient.setFrequency(mFrequency);
    mCosineGradient.setPhase(mPhase);
    mCosineGradient.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    mCosineGradient.render(glm::vec2(0), ofGetWidth(), ofGetHeight());

    mGui.begin();
    {
        ImGui::Begin("ofxCosineGradient");
        {
            ImGui::SliderFloat3("Bias", &mBias[0], 0.0f, 1.0f);
            ImGui::SliderFloat3("Amplitude", &mAmplitude[0], 0.0f, 1.0f);
            ImGui::SliderFloat3("Frequency", &mFrequency[0], 0.0f, 1.0f);
            ImGui::SliderFloat3("Phase", &mPhase[0], 0.0f, 1.0f);
        }
        ImGui::End();
    }
    mGui.end();
}

//--------------------------------------------------------------
