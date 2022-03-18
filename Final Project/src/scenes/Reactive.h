#pragma once
#include "ofMain.h"
#include "ofxSceneManager.h"

class Reactive : public ofxScene {
public:
	Reactive() {}
	~Reactive(){}
	Reactive(string text, float* smoothedVol) {
		//Set the values of the text and Smoothed Vol
		this->smoothedVol = smoothedVol;
		this->text = "Sound React";
	}
	void draw() override {
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
		ofNoFill();
		ofSetLineWidth(2);
		ofSetRectMode(OF_RECTMODE_CENTER);

		for (int i = 0; i < 30; i++) {
			ofRotateDeg(ofGetElapsedTimef());
			ofScale(0.9);
			ofDrawRectangle(ofGetWidth() / 2, ofGetHeight() / 2, *smoothedVol*300.0f, *smoothedVol*300.0f);
		}
	}
private:
	string text;
	float* smoothedVol;
};