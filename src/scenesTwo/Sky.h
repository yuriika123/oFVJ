#pragma once

#include "BaseScene.h"

class Sky : public BaseScene {
public:
	Sky() {
		sceneName = "Sky";
	}
	
	void setup() override;
	void update(bool isBeat) override;
	void draw() override;
	void keyPressed(int key) override;
	
	vector<ofPoint> points;
	vector<ofImage> images;
	vector<bool> showImage;
	
	float timeOffset;
	ofColor randCol;
};
