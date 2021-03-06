#include "testApp.h"

testApp::~testApp()
{

	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
		//delete boidChilds[i];
	}

	for (int i = 0; i < boidChilds.size(); i++)
	{
		//delete boids[i];
		delete boidChilds[i];
	}
}

//--------------------------------------------------------------
void testApp::setup(){
	
	
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(0,50,50);
	
	// set up the boids
	for (int i = 0; i < 20; i++) {
		boids.push_back(new Boid());
		//boidChilds.push_back(new BoidChild());
	}

	for (int i = 0; i < 50; i++) {
		//boids.push_back(new Boid());
		boidChilds.push_back(new BoidChild());
	}

}


//--------------------------------------------------------------
void testApp::update(){
	
    ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);
		//boidChilds[i]->update(boidChilds, min, max);
	}

	for (int i = 0; i < boidChilds.size(); i++)
	{
		//boids[i]->update(boids, min, max);
		boidChilds[i]->update(boidChilds, boids, min, max);
	}

}

//--------------------------------------------------------------
void testApp::draw(){


	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
		//boidChilds[i]->draw();
	}

	for (int i = 0; i < boidChilds.size(); i++)
	{
		//boids[i]->draw();
		boidChilds[i]->draw();
	}

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
 
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
