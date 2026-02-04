#include "AlignmentShapes.h"

void AlignmentShapes::setup() {
	ofSetCircleResolution(64);
	circleCount = 32;
	for (int i = 0; i < circleCount; i++) {
		int x = ofGetWidth() / (circleCount + 1) * (i + 1);
		for (int j = 0; j < circleCount; j++) {
			int y = ofGetHeight() / (circleCount + 1) * (j + 1);
			points.push_back(ofPoint(x, y));
			radius.push_back(ofGetWidth() / 15);
		}
	}
	
	randCol.setHsb(ofRandom(255), ofRandom(255), 255);
	isFill = false;
}

void AlignmentShapes::update(bool isBeat) {
	if (isBeat) {
		radius.clear();
		points.clear();
		for (int i = 0; i < circleCount; i++) {
			int rad = ofRandom(ofGetWidth() / 30, ofGetWidth() / 5);
			radius.push_back(rad);
			
			int x = ofRandom(ofGetWidth());
			int y = ofRandom(ofGetHeight());
			points.push_back(ofPoint(x, y));
		}
	}
	for (int i = 0; i < radius.size(); i++) {
		radius[i] *= 0.95;
	}
}

void AlignmentShapes::draw() {
	ofSetColor(randCol);
	if (isFill) {
		ofFill();
	} else {
		ofNoFill();
	}
	
	for (int i = 0; i < points.size(); i++) {
		ofDrawCircle(points[i].x + ofRandom(-4, 4), points[i].y + ofRandom(-4, 4), radius[i]);
	}
}

void AlignmentShapes::keyPressed(int key) {
	if (key == '4') {
		isFill = !isFill;
	}
	if (key == '5') {
		randCol.setHsb(ofRandom(255), ofRandom(255), 255);
	}
}
