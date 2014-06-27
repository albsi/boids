#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include <time.h>

#include "mainClass.hpp"

mainClass::mainClass(){}

void mainClass::run(){
	evenRound = false;
	srand (time(NULL));

	for (int i = 0; i < boids; ++i){
		position p = position();
		p.x = rand() % 100;
		p.y = rand() % 100;
		position v = position();
		v.x = rand() % 100;
		v.y = rand() % 100;
		boid b1(p,v);
		boidsVec1.push_back(&b1);
		boid b2(b1);
		boidsVec2.push_back(&b2);
	}
	int groupSize = std::ceil((boids * 1.0) / threads);

	for (int i = 0; i < threads; ++i){
		std::vector<boid*> vec;
		for (int j = 0; j < groupSize && (i * groupSize + j) < boids; ++j){
			boid * bp = new boid(evenRound?&boidsVec1.at(i * groupSize + j)->pos, boidsVec1.at(i * groupSize + j)->vel
				:boidsVec2.at(i * groupSize + j)->pos, boidsVec2.at(i * groupSize + j)->vel);
			vec.push_back(bp);
		}
		group g(vec);
		groupsVec.push_back(g);
	}

	for(int k = 0; k < rounds; ++k){
		std::cout << "*";
		for (int i = 0; i < threads; ++i){
			groupsVec.at(i).calcNewPos(!evenRound ? boidsVec1 : boidsVec2);
			
		}
		evenRound = !evenRound;
		std::cout << "*\n";
	}

	
}

int main(int argc, char **argv) {
	mainClass m;
	m.boids = 10;
	m.threads = 1;
	m.rounds = 10;

	if(argc == 3){
		m.boids = atoi(argv[1]);
		m.rounds = atoi(argv[2]);
	}else if(argc == 4){
		m.boids = atoi(argv[1]);
		m.rounds = atoi(argv[2]);
		m.threads = atoi(argv[3]);
	}else{
		std::cerr << "ERR: Please use command like this:\n\t./boids boids rounds [threads]\n\n";
        exit(1);
	}
	m.run();
}