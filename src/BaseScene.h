#pragma once
#include "ofMain.h"

class BaseScene {
public:
	virtual ~BaseScene() {}
	
	virtual void setup() = 0;
	virtual void update(bool isBeat) = 0;
	virtual void draw() = 0;
	virtual void keyPressed(int key) {}
	
	string getName() { return sceneName; }
	
protected:
	string sceneName = "BaseScene";
};
