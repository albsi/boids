#include <iostream>
#include <vector>
#include <algorithm>
#include "boid.hpp"

const position operator+(position const& p1, position const& p2){ 
	position tmp; 
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	tmp.x = p1.x + p2.x;
	tmp.y = p1.y + p2.y;
	return tmp; 
}

const position operator-(position const& p1, position const& p2){ 
	position tmp; 
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	tmp.x = p1.x - p2.x;
 	tmp.y = p1.y - p2.y;
 	return tmp; 
}

const position operator-(float const& f, position const& p1){
	position tmp; 
 	tmp.x = 0.0f;
 	tmp.y = 0.0f;
 	tmp.x = f - p1.x;
 	tmp.y = f - p1.y;
 	return tmp; 
}

const position operator/(position const& p1, float const& f){ 
	position tmp; 
 	tmp.x = 0.0f;
 	tmp.y = 0.0f;
 	tmp.x = p1.x / f;
 	tmp.y = p1.y / f;
 	return tmp; 
}

const position operator*(position const& p1, float const& f){ 
	position tmp; 
 	tmp.x = 0.0f;
 	tmp.y = 0.0f;
 	tmp.x = p1.x * f;
 	tmp.y = p1.y * f;
 	return tmp; 
}
position& operator/=(position & p1, const float& f){
 	p1.x = p1.x / f;
 	p1.y = p1.y / f;
    return p1;
}

position& operator+=(position & p1, position const& p2){
 	p1.x = p1.x + p2.x;
 	p1.y = p1.y + p2.y;
    return p1;
}

bool operator!=(position const& p1, position const& p2){
    return !(p1.x == p2.x && p1.y == p2.y);
}

bool operator!=(boid const& b1, boid const& b2){
    return !(b1.pos.x == b2.pos.x && b1.pos.y == b2.pos.y);
}

bool operator<(position const& p1, const float& f){
    return (p1.x < f || p1.y < f);
}

std::ostream& operator<<(std::ostream& out, const position& p){
    out << "[" << p.x << " " << p.y << "]";
    return out;
}

boid::boid(position p, position v){
	pos = p;
	vel = v;
}

boid::boid( const boid& other ) :
     pos( other.pos ), vel( other.vel ){}

void boid::rule1(std::vector<boid*> &boidsGroup){
	boid * bp = this;
	position tmp;
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		if(*bp != *b1){
			tmp += b1->pos;
		}
	});
	tmp /= boidsGroup.size() - 1;
	pos += ((tmp - pos) * 0.1f);
}

void boid::rule2(std::vector<boid*> &boidsGroup){
	boid * bp = this;
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		if(*bp != *b1){
			if((pos - b1->pos) < 10.0f){
				vel = 0.0f - (pos - b1->pos);
			}
		}
	});
}

void boid::rule3(std::vector<boid*> &boidsGroup){
	boid * bp = this;
	position tmp;
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	for_each(boidsGroup.begin(), boidsGroup.end(), [&](boid * b1) {
		if(*bp != *b1){
			tmp += b1->vel;
		}
	});
	tmp /= boidsGroup.size() - 1;
	pos += (tmp - pos) / 8.0f;
}

void boid::move(){
	pos += vel;
	//std::cout << pos << "\n";
}

boid::~boid(){}

