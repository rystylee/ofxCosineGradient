#pragma once

#include "ofMain.h"

class ofxCosineGradient
{
public:
    ofxCosineGradient();

    void init(const int width, const int height);
    void initShader();
    void update();
    void render(const glm::vec2& pos, const int width, const int height);

    const ofTexture& getTexture() const { return mFbo.getTexture(); }

    static glm::vec3 cosinGradient(
        const float t
        , const glm::vec3& a
        , const glm::vec3& b
        , const glm::vec3& c
        , const glm::vec3& d
    );

    void setBias(const glm::vec3& bias) { mBias = bias; }
    void setAmplitude(const glm::vec3& amplitude) { mAmplitude = amplitude; }
    void setFrequency(const glm::vec3& frequency) { mFrequency = frequency; }
    void setPhase(const glm::vec3& phase) { mPhase = phase; }

private:
    int mWidth;
    int mHeight;

    ofShader mShader;
    ofFbo mFbo;

    // Control
    glm::vec3 mBias { 0, 0, 0 };
    glm::vec3 mAmplitude { 0, 0, 0 };
    glm::vec3 mFrequency { 0, 0, 0 };
    glm::vec3 mPhase { 0, 0, 0 };
};
