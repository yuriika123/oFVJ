#include "Sky.h"

void Sky::setup() {
	int imageCount = 5;
	images.resize(imageCount);
	for (int i = 0; i < imageCount; i++) {
		string imageName = ofToString(i) + ".JPG";
		images[i].load("Sky/" + imageName);
		images[i].resize(ofGetWidth() / 5, ofGetWidth() / 5 / images[i].getWidth() * images[i].getHeight());
		images[i].setAnchorPercent(0.5, 0.5);
	}
	
	for (int i = 0; i < images.size(); i++) {
		int x = ofRandom(ofGetWidth());
		int y = ofRandom(ofGetHeight());
		points.push_back(ofPoint(x, y));
		showImage.push_back(false);
	}
	
	timeOffset = ofRandom(10);
	randCol.set(255);
}

void Sky::update(bool isBeat) {
	float time = ofGetElapsedTimef();
	for (int i = 0; i < images.size(); i++) {
		if (sin(time + timeOffset * i * 3.0) > 0.9) {
			showImage[i] = true;
		}
		if (sin(time + timeOffset * (i + 1)) < -0.9) {
			showImage[i] = false;
			int x = ofRandom(ofGetWidth());
			int y = ofRandom(ofGetHeight());
			points[i] = ofPoint(x, y);
		}
	}
}

void Sky::draw() {
	ofSetColor(randCol);
	for (int i = 0; i < images.size(); i++) {
		if (showImage[i]) {
			images[i].draw(points[i].x, points[i].y);
		}
	}
}

void Sky::keyPressed(int key) {
	if (key == 'r') {
		timeOffset = ofRandom(-10, 10);
	}
	if (key == 't') {
		randCol.set(255);
	}
	if (key == 'y') {
		randCol.setHsb(ofRandom(255), ofRandom(255), 255);
	}
}

