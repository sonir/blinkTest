#pragma once

#define PORT 65137
#define SC_W 640
#define SC_H 480
#define SC_MARGIN_LEFT 20
#define SC_MARGIN_TOP 20
#define BLINK_SPD 8

#include <iostream>
#include "ofMain.h"
#include "sloBlink.h"
#include "blinkTest.h"
#include "setup.h"
#include "Osc.h"
class Osc;

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void blinkAll();
        void setSpecials(specials_t sp);
    
    
        vector <sloBlink> blinks;
        Osc *osc;
        ofxOscSender sender;
    
    
    private:
        blinkTest app;
        int timer_blink_all = 0;
};
