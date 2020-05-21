/*
 * Brick.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef WALL_H_
#define WALL_H_
#include "Shape.h"
class Wall: public Shape {
	sf::RectangleShape *brick ;
	sf::Image img ;
	sf::Texture brickTexture ;
	string *orientation ;
	int brickCounter ;
public:
	Wall();
	friend class Interface;
	void draw(sf::RenderWindow &window) ;
	void initialise(int) ;
	~Wall() { delete [] brick ;} ;
	sf::RectangleShape*& getBrick() ;
	int getBrickCounter() const;
	void setBrickCounter(int brickCounter);
};

#endif /* WALL_H_ */
