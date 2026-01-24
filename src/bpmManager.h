#pragma once

#include "ofMain.h"

class bpmManager {
public:
	void setup();
	void update();
	void keyPressed(int key);
	
	int bpm;
	float lastKeyTime;
	float lastBeatTime;
	bool isBeat;
};
