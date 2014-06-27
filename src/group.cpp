#include <iostream>
#include <vector>
#include <algorithm>
#include "group.hpp"

group::group(std::vector<boid*> &boidsGroup){
	this->boidsGroup = boidsGroup;
}

void group::calcNewPos(std::vector<boid*> &allBoids){
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule1(allBoids);
	});

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule2(allBoids);
	});

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->rule3(allBoids);
	});

	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		b1->move();
	});
}