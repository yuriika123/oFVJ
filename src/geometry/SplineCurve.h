#pragma once

#include "BaseScene.h"

class SplineCurve : public BaseScene {
public:
	SplineCurve() {
		sceneName = "Spline Curve";
	}
	
	void setup() override;
	void update(bool isBeat) override;
	void draw() override;
	void keyPressed(int key) override;
	
	vector<ofPoint> points;
	vector<ofPoint> targetPoints;
	bool isFill;
	ofColor randCol;
};
