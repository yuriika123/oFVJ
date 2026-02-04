#include "SplineCurve.h"

void SplineCurve::setup() {
	int pointCount = 10;
	for (int i = 0; i < pointCount; i++) {
		int x = ofRandom(ofGetWidth());
		int y = ofRandom(ofGetHeight());
		points.push_back(ofPoint(x, y));
		targetPoints.push_back(ofPoint(x, y));
	}
	
	isFill = false;
}

void SplineCurve::update(bool isBeat) {
	if (isBeat) {
		targetPoints.clear();
		for (int i = 0; i < points.size(); i++) {
			int x = ofRandom(ofGetWidth());
			int y = ofRandom(ofGetHeight());
			targetPoints.push_back(ofPoint(x, y));
		}
	}
	for (int i = 0; i < points.size(); i++) {
		points[i].interpolate(targetPoints[i], 0.2);
	}
}

void SplineCurve::draw() {
	ofSetColor(randCol);
	if (isFill) {
		ofFill();
	} else {
		ofNoFill();;
	}
	ofSetLineWidth(3);
	ofBeginShape();
	if (points.size() > 0) {
		ofCurveVertex(points[0]);
		for (int i = 0; i < points.size(); i++) {
			ofCurveVertex(points[i]);
		}
		ofCurveVertex(points.back());
	}
	ofEndShape();
}

void SplineCurve::keyPressed(int key) {
	if (key == '4') {
		isFill = !isFill;
	}
	if (key == '5') {
		randCol.setHsb(ofRandom(255), ofRandom(255), 255);
	}
}
