/*
 * Brick.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef WALL_H_
#define WALL_H_
#include <SFML/Graphics.hpp>
#include "Shape.h"

class Wall: public Shape {
	sf::RectangleShape *brick ;
public:
	Wall();
	void initialise(int) ;
	virtual ~Wall();
	sf::RectangleShape*& getBrick() ;
};

#endif /* WALL_H_ */
