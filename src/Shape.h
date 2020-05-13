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

public:
	virtual void draw(sf::RenderWindow &window) = 0 ;
	void setObjectsize(int objectsize);

	int getObjectsize() const  ;
	Shape();
	virtual ~Shape() { ;}
};

#endif /* SHAPE_H_ */
