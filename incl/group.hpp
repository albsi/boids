#ifndef __GROUP_HPP__
#define __GROUP_HPP__

#include <vector>
#include "boid.hpp"

class group{
public:
	group(std::vector<boid*> &boidsGroupVec);
	void calcNewPos();
	std::vector<boid*> boidsGroup;
};

#endif