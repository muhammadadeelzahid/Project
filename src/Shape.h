/*
 * Shape.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Shape {
	int objectsize ;
	string name ;
	int speedOfMovement ;
	int tokenValue ;

public:
	virtual void draw(sf::RenderWindow &window) = 0 ;
	Shape();
	virtual ~Shape() { ;}
	const string& getName() const;
	void setName(const string &name);
	int getSpeedOfMovement() const;
	void setSpeedOfMovement(int speedOfMovement);
	int getTokenValue() const;
	void setTokenValue(int tokenValue);
	int getObjectsize() const;
	void setObjectsize(int objectsize);
};

#endif /* SHAPE_H_ */
