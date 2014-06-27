#ifndef __MAIN_CLASS_HPP__
#define __MAIN_CLASS_HPP__

#include <vector>
#include "boid.hpp"
#include "group.hpp"

class mainClass{
public:
	mainClass();
	void run();
	int boids;
	int threads;
	int rounds;
private:
	bool evenRound;
	std::vector<boid*> boidsVec1;
	std::vector<boid*> boidsVec2;
	std::vector<group> groupsVec;
};

#endif