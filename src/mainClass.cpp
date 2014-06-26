#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h> 
#include "mainClass.hpp"

mainClass::mainClass(){}

void mainClass::run(){
	boids = 10;
	threads = 1;
	rounds = 10;
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
		boidsVec1.push_back(b1);
		boid b2(b1);
		boidsVec2.push_back(b2);
	}
	int groupSize = std::ceil((boids * 1.0) / threads);

	for(int k = 0; k < rounds; ++k){
		if(k%5==0){
			std::cout << "."; //TODO remove this im alive thing
		}
		for (int i = 0; i < threads; ++i){
			std::vector<boid*> vec;
			for (int j = 0; j < groupSize && (i * groupSize + j) < boids; ++j){
				boid * bp = new boid(evenRound?&boidsVec1.at(i * groupSize + j).pos,boidsVec1.at(i * groupSize + j).vel
					:boidsVec2.at(i * groupSize + j).pos,boidsVec2.at(i * groupSize + j).vel);
				vec.push_back(bp);
			}
			group g(vec);
			groupsVec.push_back(g);
		}
		
		for (int i = 0; i < threads;++i){
			groupsVec.at(i).calcNewPos();
		}
	}
}

int main(int argc, char **argv) {
	mainClass m;
	m.run();

}