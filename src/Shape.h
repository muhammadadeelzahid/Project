/*
 * Shape.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include "Coordinate.h"
#include <iostream>
using namespace std;
class Shape {
	int objectsize ;
	string name ;
	Coordinate position;
	int speedOfMovement ;
	int tokenValue ;

public:
	Shape();
	virtual ~Shape();
	const string& getName() const;
	void setName(const string &name);
	const Coordinate& getPosition() const;
	void setPosition(const Coordinate &position);
	int getSpeedOfMovement() const;
	void setSpeedOfMovement(int speedOfMovement);
	int getTokenValue() const;
	void setTokenValue(int tokenValue);
	int getObjectsize() const;
	void setObjectsize(int objectsize);
};

#endif /* SHAPE_H_ */
