/*
 * Tank.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Tank.h"

Tank::Tank() {
	this->setTokenValue(2) ;

	//setting the texture ;
}


void Tank::initialiseTank(int i)
{
    tank.setPosition(3,3);
//    tank[i].
 }
Tank::~Tank() {
}

 sf::Sprite& Tank::getTank()  {
	return tank;
}
