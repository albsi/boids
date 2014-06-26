#ifndef __BOID_HPP__
#define __BOID_HPP__

#include <vector>
#include <iostream>

struct position{
	float x;
	float y;
};

const position operator+(position const& p1, position const& p2);
const position operator-(position const& p1, position const& p2);
const position operator-(float const& f, position const& p1);
const position operator/(position const& p1, float const& f);
const position operator*(position const& p1, float const& f);
position& operator/=(position & p1, float const& f);
position& operator+=(position & p1, position const& p2);
bool operator!=(position const& p1, position const& p2);
bool operator<(position const& p1, float const& f);
std::ostream& operator<<(std::ostream& out, const position& p);

class boid{
public:
	boid(position, position);
	boid(const boid& other);
	void rule1(std::vector<boid*> &);
	void rule2(std::vector<boid*> &);
	void rule3(std::vector<boid*> &);
	void move();
	position pos;
	position vel;
	friend bool operator!=(boid const& b1, boid const& b2);
	~boid();
};

#endif