#pragma once

#include "BaseScene.h"

class Cocoon : public BaseScene {
public:
	Cocoon() {
		sceneName = "Cocoon";
	}
	
	void setup() override;
	void update(bool isBeat) override;
	void draw() override;
	void keyPressed(int key) override;
	
	int lineCount;
	int pointCount;
	vector<ofPolyline> lines;
	float speed;
};
