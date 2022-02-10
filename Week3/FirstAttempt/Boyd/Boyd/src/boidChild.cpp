#include "boidChild.h"

BoidChild::BoidChild()
{

	Boid::separationWeight = 1.0f;
	Boid::cohesionWeight = 0.2f;
	Boid::alignmentWeight = 0.1f;
	avoidWeight = 0.1f;

	Boid::separationThreshold = 15;
	Boid::neighbourhoodSize = 150;

	Boid::position = ofVec3f(ofRandom(100, 200), ofRandom(100, 200));
	Boid::velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
}


BoidChild::BoidChild(ofVec3f &pos, ofVec3f &vel)
{
	avoidWeight = 0.1f;
	Boid::separationWeight = 1.0f;
	Boid::cohesionWeight = 0.2f;
	Boid::alignmentWeight = 0.1f;

	Boid::separationThreshold = 15;
	Boid::neighbourhoodSize = 150;

	Boid::position = pos;
	Boid::velocity = vel;
}




BoidChild::~BoidChild()
{

}
float BoidChild::getAvoidWeight()
{
	return avoidWeight;
}

float BoidChild::getSeparationWeight()
{
	return separationWeight;
}
float  BoidChild::getCohesionWeight()
{
	return cohesionWeight;
}

float  BoidChild::getAlignmentWeight()
{
	return alignmentWeight;
}


float  BoidChild::getSeparationThreshold()
{
	return separationThreshold;
}

float BoidChild::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void  BoidChild::setSeparationWeight(float f)
{
	separationWeight = f;
}
void  BoidChild::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void  BoidChild::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}

void BoidChild::setAvoidWeight(float f) {
	avoidWeight = f;
}


void  BoidChild::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void  BoidChild::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}


ofVec3f  BoidChild::getPosition()
{
	return position;
}

ofVec3f  BoidChild::getVelocity()
{
	return velocity;
}

ofVec3f  BoidChild::separation(std::vector<BoidChild *> &otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position - otherBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}

ofVec3f  BoidChild::cohesion(std::vector<BoidChild *> &otherBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - position;
	v.normalize();
	return v;
}

ofVec3f  BoidChild::alignment(std::vector<BoidChild *> &otherBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - velocity;
	v.normalize();
	return v;
}

void  BoidChild::update(std::vector<BoidChild *> &otherBoids, std::vector<Boid *> &otherOtherBoids, ofVec3f &min, ofVec3f &max)
{
	velocity += separationWeight * separation(otherBoids);
	velocity += cohesionWeight * cohesion(otherBoids);
	velocity += alignmentWeight * alignment(otherBoids);
	//velocity += avoidWeight * avoid(otherOtherBoids);
	//velocity += separationWeight * cohesion(otherBoids);

	walls(min, max);
	position += velocity;
}

void  BoidChild::walls(ofVec3f &min, ofVec3f &max)
{
	if (position.x < min.x) {
		position.x = min.x;
		velocity.x *= -1;
	}
	else if (position.x > max.x) {
		position.x = max.x;
		velocity.x *= -1;
	}

	if (position.y < min.y) {
		position.y = min.y;
		velocity.y *= -1;
	}
	else if (position.y > max.y) {
		position.y = max.y;
		velocity.y *= -1;
	}


}





ofVec3f BoidChild::avoid(std::vector<Boid *> &otherOtherBoids) {
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	for (int i = 0; i < otherOtherBoids.size(); i++)
	{
		if (position.distance(otherOtherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position - otherOtherBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}



void  BoidChild::draw()
{
	ofSetColor(255, 255, 255);
	ofDrawCircle(getPosition().x, getPosition().y, 5);
}

