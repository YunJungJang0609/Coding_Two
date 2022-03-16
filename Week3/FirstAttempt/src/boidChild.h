#ifndef _BOID_CHILD
#define _BOID_CHILD


#include "boid.h"

	class BoidChild : public Boid
	{
		// all the methods and variables after the
		// private keyword can only be used inside
		// the class
	private:
		/*ofVec3f position;
		ofVec3f velocity;

		float separationWeight;
		float cohesionWeight;
		float alignmentWeight;

		float separationThreshold;
		float neighbourhoodSize;*/

		float avoidWeight;

		ofVec3f separation(std::vector<BoidChild *> &otherBoids);
		ofVec3f cohesion(std::vector<BoidChild *> &otherBoids);
		ofVec3f alignment(std::vector<BoidChild *> &otherBoids);

		ofVec3f avoid(std::vector<Boid *> &otherOtherBoids);

		// all the methods and variables after the
		// public keyword can only be used by anyone
	public:

		Boid boidC{};

		BoidChild();
		BoidChild(ofVec3f &pos, ofVec3f &vel);

		virtual ~BoidChild();

		ofVec3f getPosition();
		ofVec3f getVelocity();


		float getSeparationWeight();
		float getCohesionWeight();
		float getAlignmentWeight();
		float getAvoidWeight();

		float getSeparationThreshold();
		float getNeighbourhoodSize();

		void setSeparationWeight(float f);
		void setCohesionWeight(float f);
		void setAlignmentWeight(float f);
		void setAvoidWeight(float f);

		void setSeparationThreshold(float f);
		void setNeighbourhoodSize(float f);

		virtual void update(std::vector<BoidChild *> &otherBoids, std::vector<Boid *> &otherOtherBoids, ofVec3f &min, ofVec3f &max);

		void walls(ofVec3f &min, ofVec3f &max);

		void draw();
	};

#endif	
