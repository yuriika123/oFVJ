#pragma once

#include "ofMain.h"
#include "bpmManager.h"
#include "BaseScene.h"
#include "SplineCurve.h"
#include "AlignmentShapes.h"
#include "Sky.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
		
	bpmManager bpmMgr;
	
	vector<shared_ptr<BaseScene>> scenesOne;
	int currentSceneOneIndex;
	bool showScenesOne;
	
	vector<shared_ptr<BaseScene>> scenesTwo;
	int currentSceneTwoIndex;
	bool showScenesTwo;
};
