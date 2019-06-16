#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ) {
	ofGLFWWindowSettings s;
	s.setGLVersion(4, 1);
	s.setSize(1280, 720);
	ofCreateWindow(s);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
