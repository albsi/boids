#include <iostream>
#include <vector>
#include <algorithm>
#include "group.hpp"

group::group(std::vector<boid*> &boidsGroupVec){
	boidsGroup = boidsGroupVec;
}

void group::calcNewPos(){
	massPos = massCenter();

	//std::cout << "R1 ";
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule1(massPos);
	});
	//std::cout << "\nR2 ";

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b2) {
			if(b1 != b2){
				b1->rule2(*b2);
			}
		});
	});
	//std::cout << "\n";

	massVel = massVelocity();

	//std::cout << "R3 ";
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule3(massVel);
	});
	//std::cout << "\n";

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->move();
		//std::cout << "[" << b1->pos.x << "," << b1->pos.y << "]\n";
	});
	//std::cout << "\n";
}

position group::massCenter(){
	position tmp;
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		tmp += b1->pos;
	});
	tmp /= boidsGroup.size() - 1;
	//std::cout << "cent " << tmp.x << "," << tmp.y << "\n";
	return tmp;
}

position group::massVelocity(){
	position tmp;
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		tmp += b1->vel;
	});
	tmp /= boidsGroup.size() - 1;
	//std::cout << "velo " << tmp.x << "," << tmp.y << "\n";
	return tmp;
}