#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofSetWindowShape(1600, 900);
	ofSetWindowPosition((ofGetScreenWidth() - ofGetWidth()) / 2., (ofGetScreenHeight() - ofGetHeight()) / 2. + 16);
	ofBackground(0);
	ofSetCircleResolution(60);
	
	bpmMgr.setup();
	
	showScenesOne = true;
	scenesOne.push_back(make_shared<SplineCurve>());
	scenesOne.push_back(make_shared<AlignmentShapes>());
	currentSceneOneIndex = 0;
	for (auto& scene : scenesOne) {
		scene->setup();
	}
	
	showScenesTwo = false;
	scenesTwo.push_back(make_shared<Sky>());
	currentSceneTwoIndex = 0;
	for (auto& scene : scenesTwo) {
		scene->setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	bpmMgr.update();
	
	if (scenesOne.size() > 0 && showScenesOne) {
		scenesOne[currentSceneOneIndex]->update(bpmMgr.isBeat);
	}
	
	if (scenesTwo.size() > 0 && showScenesTwo) {
		scenesTwo[currentSceneTwoIndex]->update(bpmMgr.isBeat);
	}
	
	string title = "";
	if (showScenesOne) {
		title += "Scene 1: " + scenesOne[currentSceneOneIndex]->getName();
	}
	if (showScenesTwo) {
		title += " | Scene 2: " + scenesTwo[currentSceneTwoIndex]->getName();
	}
	title += " | FPS: " + ofToString(round(ofGetFrameRate()));
	title += " | BPM: " + ofToString(bpmMgr.bpm);
	ofSetWindowTitle(title);
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (scenesOne.size() > 0 && showScenesOne) {
		scenesOne[currentSceneOneIndex]->draw();
	}
	
	if (scenesTwo.size() > 0 && showScenesTwo) {
		scenesTwo[currentSceneTwoIndex]->draw();
	}
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	bpmMgr.keyPressed(key);
	
	if (key == '3') {
		currentSceneOneIndex += 1;
		if (currentSceneOneIndex >= scenesOne.size()) {
			currentSceneOneIndex = 0;
		}
	}
	if (key == '2') {
		currentSceneOneIndex -= 1;
		if (currentSceneOneIndex < 0) {
			currentSceneOneIndex = scenesOne.size() - 1;
		}
	}
	if (key == 'e') {
		currentSceneTwoIndex += 1;
		if (currentSceneTwoIndex >= scenesTwo.size()) {
			currentSceneTwoIndex = 0;
		}
	}
	if (key == 'w') {
		currentSceneTwoIndex -= 1;
		if (currentSceneTwoIndex < 0) {
			currentSceneTwoIndex = scenesTwo.size() - 1;
		}
	}

	
	if (scenesOne.size() > 0) {
		scenesOne[currentSceneOneIndex]->keyPressed(key);
	}
	if (scenesTwo.size() > 0) {
		scenesTwo[currentSceneTwoIndex]->keyPressed(key);
	}
	
	if (key == '1') {
		showScenesOne = !showScenesOne;
	}
	if (key == 'q') {
		showScenesTwo = !showScenesTwo;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
