#include <iostream>
#include <vector>
#include <algorithm>
#include "group.hpp"

group::group(std::vector<boid*> &boidsGroupVec){
	boidsGroup = boidsGroupVec;
}

void group::calcNewPos(){
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule1(boidsGroup);
	});

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule2(boidsGroup);
	});

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule3(boidsGroup);
	});

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->move();
	});
}