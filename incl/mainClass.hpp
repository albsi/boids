#ifndef __MAIN_CLASS_HPP__
#define __MAIN_CLASS_HPP__

#include <vector>
#include "boid.hpp"
#include "group.hpp"
#include <pthread.h>

class mainClass{
public:
	mainClass();
	void run();
	int boids;
	int threads;
	int rounds;
	void* start_worker(void *context);
private:
	bool evenRound;
	std::vector<boid*> boidsVec1;
	std::vector<boid*> boidsVec2;
	std::vector<group> groupsVec;
};

#endif