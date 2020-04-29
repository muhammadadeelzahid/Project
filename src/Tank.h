/*
 * Tank.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef TANK_H_
#define TANK_H_

#include "Shape.h"
#include <SFML/Graphics.hpp>
class Tank: public Shape {
	sf::Sprite *tank ;
	int tankcount;

public:
	Tank() ;
	virtual ~Tank();
};

#endif /* TANK_H_ */
