#include "ofxCosineGradient.h"

ofxCosineGradient::ofxCosineGradient()
{}

void ofxCosineGradient::init(const int width, const int height)
{
    mWidth = width; mHeight = height;

    ofFboSettings s;
    s.width = mWidth;
    s.height = mHeight;
    s.numColorbuffers = 1;
    s.useDepth = false;
    s.useStencil = false;
    s.depthStencilAsTexture = false;
    s.textureTarget = GL_TEXTURE_2D;
    s.internalformat = GL_RGB;
    s.wrapModeHorizontal = GL_CLAMP_TO_EDGE;
    s.wrapModeVertical = GL_CLAMP_TO_EDGE;
    s.minFilter = GL_LINEAR;
    s.maxFilter = GL_LINEAR;
    s.numSamples = 0;
    mFbo.allocate(s);

    initShader();
}

void ofxCosineGradient::initShader()
{
    std::stringstream vert;

    vert << "#version 410 core\n";
    vert << "in vec4 position;\n";
    vert << "\n";
    vert << "uniform mat4 modelViewProjectionMatrix;\n";
    vert << "\n";
    vert << "void main() {\n";
    vert << "\tgl_Position = modelViewProjectionMatrix * position;\n";
    vert << "}\n";

    std::stringstream frag;

    frag << "#version 410 core\n";
    frag << "precision mediump float;\n";
    frag << "\n";
    frag << "uniform vec2 uResolution;\n";
    frag << "uniform vec3 uA;\n";
    frag << "uniform vec3 uB;\n";
    frag << "uniform vec3 uC;\n";
    frag << "uniform vec3 uD;\n";
    frag << "\n";
    frag << "out vec4 fragColor;\n";
    frag << "\n";
    frag << "vec3 cosineGradient(in float t, in vec3 a, in vec3 b, in vec3 c, in vec3 d){\n";
    frag << "return a + b * cos(6.28318 * (c * t + d));\n";
    frag << "}\n";
    frag << "\n";
    frag << "void main() {\n";
    frag << "\tvec2 uv = gl_FragCoord.xy / uResolution.xy;\n";
    frag << "\n";
    frag << "\tvec3 color = cosineGradient(uv.x, uA, uB, uC, uD);\n";
    frag << "\n";
    frag << "\tfragColor.rgb = color;\n";
    frag << "\tfragColor.a = 1.0;\n";
    frag << "}\n";

    mShader.setupShaderFromSource(GL_VERTEX_SHADER, vert.str());
    mShader.setupShaderFromSource(GL_FRAGMENT_SHADER, frag.str());
    mShader.bindDefaults();
    mShader.linkProgram();
}

void ofxCosineGradient::update()
{
    mFbo.begin();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    mShader.begin();
    mShader.setUniform2f("uResolution", mWidth, mHeight);
    mShader.setUniform3f("uA", mBias);
    mShader.setUniform3f("uB", mAmplitude);
    mShader.setUniform3f("uC", mFrequency);
    mShader.setUniform3f("uD", mPhase);
    ofDrawRectangle(0, 0, mWidth, mHeight);
    mShader.end();
    mFbo.end();
}

void ofxCosineGradient::render(const glm::vec2& pos, const int width, const int height)
{
    mFbo.draw(pos, width, height);
}

glm::vec3 ofxCosineGradient::cosinGradient( const float t
                       , const glm::vec3& a
                       , const glm::vec3& b
                       , const glm::vec3& c
                       , const glm::vec3& d
                       )
{
    return a + b * cos(6.28318 * (c * t + d));
}
