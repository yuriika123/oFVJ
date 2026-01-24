#pragma once

#include "BaseScene.h"

class AlignmentShapes : public BaseScene {
public:
	AlignmentShapes() {
		sceneName = "Alignment Shapes";
	}
	
	void setup() override;
	void update(bool isBeat) override;
	void draw() override;
	void keyPressed(int key) override;
	
	vector<ofPoint> points;
	vector<int> radius;
	int circleCount;
	bool isFill;
	ofColor randCol;
};

