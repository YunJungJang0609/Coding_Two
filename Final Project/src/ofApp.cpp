#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	shared_ptr<Reactive> react = make_shared<Reactive>("Reactive", &smoothedVol);

	scenes.addScene(react);

	scenes.setTransitionMode(ofxSceneTransition::FADE);
	scenes.setSceneDuration(0.1f, 0.1f);
	
	scenes.setup(ofGetWidth(), ofGetHeight());

	//Setup initial Values
	int bufferSize = 256;
	leftChannel.assign(bufferSize, 0.0);
	rightChannel.assign(bufferSize, 0.0);
	bufferCounter = 0;
	drawCounter = 0;
	smoothedVol = 0.0f;
	scaledVol = 0.0f;

	//Init Settings Object
	ofSoundStreamSettings settings;

	//Set Default Device
	auto devices = soundStream.getDeviceList();
	if (!devices.empty()) {
		settings.setInDevice(devices[4]);
	}

	//Set Sound Stream Settings
	settings.setInListener(this);
	settings.sampleRate = 44100;
	settings.numOutputChannels = 0;
	settings.numInputChannels = 2;
	settings.bufferSize = bufferSize;
	soundStream.setup(settings);

}

//--------------------------------------------------------------
void ofApp::update(){
	scenes.update();

	//Scale the Vol
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
	volHistory.push_back(scaledVol);

	if (volHistory.size() >= 400) {
		volHistory.erase(volHistory.begin(), volHistory.begin() + 1);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	scenes.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key = '1') scenes.changeScene(0);
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

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input) {
	//SetValues
	float curVol = 0.0;
	float numCounted = 0.0;

	//Go Through Sound Buffer and Roughly Calculate RMS
	for (size_t i = 0; i < input.getNumFrames() - 2; i++) {
		leftChannel[i] = input[i * 2] * 0.5;
		rightChannel[i] = input[i * 2 +1] * 0.5;
		
		curVol += leftChannel[i] * leftChannel[i];
		curVol += rightChannel[i] * rightChannel[i];

		numCounted += 2;
	
	}


	curVol /= (float)numCounted;

	curVol = sqrt(curVol);

	smoothedVol *- 0.93;
	smoothedVol += 0.07*curVol;
	bufferCounter++;
}