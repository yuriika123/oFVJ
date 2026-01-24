#include "bpmManager.h"

void bpmManager::setup() {
	bpm = 120;
	lastKeyTime = ofGetElapsedTimef();
	lastBeatTime = 0;
	isBeat = false;
}

void bpmManager::update() {
	float beatInterval = 60.0 / bpm;
	float currentTime = ofGetElapsedTimef();
	if (currentTime - lastBeatTime >= beatInterval) {
		isBeat = true;
		lastBeatTime += beatInterval;
	} else {
		isBeat = false;
	}
}

void bpmManager::keyPressed(int key) {
	if (key == 'b') {
		float currentTime = ofGetElapsedTimef();
		float beatInterval = currentTime - lastKeyTime;
		bpm = 60.0 / beatInterval;
		lastKeyTime = ofGetElapsedTimef();
	}
	if (key == 'v') {
		bpm -= 1;
	}
	if (key == 'n') {
		bpm += 1;
	}
}
