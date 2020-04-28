/*
 * Brick.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Wall.h"

Wall::Wall() {
	this->setObjectsize(15);
	this->setTokenValue(1) ;
	brick = new sf::RectangleShape [NULL] ;
}

 sf::RectangleShape*& Wall::getBrick()  {
	return brick;
}

Wall::~Wall() {
	// TODO Auto-generated destructor stub
}

void Wall::initialise(int screensize)
{
 	brick = new sf::RectangleShape [screensize*screensize];

 	for (int i = 0 ; i<screensize*screensize ; i++)
 	{
 		brick[i].setSize(sf::Vector2f (getObjectsize(),getObjectsize()));
 		sf::Color grey (112,128,144);
 		brick[i].setFillColor(grey) ;
 		brick[i].setOutlineThickness(1) ;
 		brick[i].setOutlineColor(sf::Color::Black) ;
 	}
}
