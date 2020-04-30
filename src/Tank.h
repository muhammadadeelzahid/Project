/*
 * Tank.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef TANK_H_
#define TANK_H_
class Interface ;
#include "Shape.h"
#include <SFML/Graphics.hpp>
class Tank: public Shape {
	sf::Sprite tank ;

public:
	friend class Interface ;
	Tank() ;
	void setTexture(sf::Texture &texture) ;
	void initialiseTank(int) ;

	virtual ~Tank();
	 sf::Sprite& getTank() ;
};

#endif /* TANK_H_ */
