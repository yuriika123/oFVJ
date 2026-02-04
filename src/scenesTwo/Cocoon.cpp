#include "Cocoon.h"

void Cocoon::setup() {
	lineCount = 10;
	pointCount = 5;
	speed = 1;
	lines.resize(lineCount);
}

void Cocoon::update(bool isBeat) {
	auto time = ofGetElapsedTimef();
	lines.clear();
	lines.resize(lineCount);
	for (int i = 0; i < lineCount; i++) {
		for (int j = 0; j < pointCount; j ++) {
			float x = sin(j * i * speed * time);
			x = ofMap(x, -1, 1, -ofGetWidth() / 2, ofGetWidth() / 2);
			float y = cos(j * i * speed * time);
			y = ofMap(y, -1, 1, -ofGetHeight() / 2, ofGetHeight() / 2);
			lines[i].addVertex(ofVec3f(x, y, 0));
		}
		lines[i].close();
	}
}

void Cocoon::draw() {
	ofSetColor(255);
	ofSetLineWidth(4);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotate(ofMap(cos(ofGetElapsedTimef() * speed), -1, 1, 0, 360));
	for (auto& line : lines) {
		line.draw();
	}
}

void Cocoon::keyPressed(int key) {
	if (key == 'r') {
		lineCount = ofRandom(2, 10);
	}
	if (key == 't') {
		pointCount = ofRandom(1, 20);
	}
	if (key == 'y') {
		speed = ofRandom(0.1, 1);
	}
}


