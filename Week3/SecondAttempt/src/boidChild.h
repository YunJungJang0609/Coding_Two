
#ifndef boidChild_h
#define boidChild_h

#include <stdio.h>
#include "boid.h"

class boidChild : public Boid
{
public:
	//this is a new constructor for our derived Babies class
	boidChild();

	//here in the new class's header file we announce that we are
	//going to change what the inherited draw() function does
	void draw();
};

#endif

