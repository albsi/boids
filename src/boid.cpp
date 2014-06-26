#include <iostream>
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

void boid::rule1(position &massPos){
	pos += (massPos - pos) / 10.0f;
	//std::cout << "[" << pos.x << "," << pos.y << "] ";
}

void boid::rule2(boid &b2){
	boid * bp = this;
	if(*bp != b2){
		if((pos - b2.pos) < 10.0f){
			vel = 0.0f - (pos - b2.pos);
		}
	}
	//std::cout << "[" << vel.x << "," << vel.y << "] ";
}

void boid::rule3(position &massVel){
	pos += (massVel - pos) / 8.0f;
	//std::cout << "[" << pos.x << "," << pos.y << "] ";
}

void boid::move(){
	//std::cout << pos <<  " " << vel;
	pos += vel;
	std::cout << pos << "\n";
}

boid::~boid(){

}

