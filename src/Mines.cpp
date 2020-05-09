/*
 * Mines.cpp
 *
 *  Created on: May 6, 2020
 *      Author: AdeelZahid
 */

#include "Mines.h"

Mines::Mines() {
	clock = new sf::Clock ;
	clock->restart() ;
	CollisionWithTank = false;
	this->resetMines = true ;
	if(!t.loadFromFile("mines 3.png"))
	{
		cout<<"Mine image not found"<<endl ;
	}
	srand(time(NULL));
	for (int i = 0 ; i<4 ; i++)
	{
		mine[i].setTexture(t);
		mine[i].setPosition(sf::Vector2f(-1000,-1000)) ;
	}


	/*mine[0].setTexture(t) ;
	mine[0].setPosition(sf::Vector2f(-1000,-1000)) ;
	mine[1].setTexture(t) ;
	mine[1].setPosition(sf::Vector2f(-1000,-1000)) ;
	*/
}

void Mines::draw(sf::RenderWindow &window)
{
	if (this->CollisionWithTank == false) {
		for ( int i = 0 ; i<4 ; i++)
		{
			window.draw(mine[i]);
		}
		/*
	window.draw(mine[0]);
	window.draw(mine[1]);
	*/
	}
	else
	{

		for ( int i = 0 ; i<4 ; i++)
		{
			mine[i].setPosition(sf::Vector2f(-1000,-1000)) ;
		}
	}

}

sf::Clock* Mines::getClock() const {
	return clock;
}


 sf::Sprite* Mines::getMine() 	 {
	return mine;
}

const sf::Texture& Mines::getT() const {
	return t;
}

void Mines::setT(const sf::Texture &t) {
	this->t = t;
}

Mines::~Mines() {
	// TODO Auto-generated destructor stub
}

bool Mines::isCollisionWithTank() const {
	return CollisionWithTank;
}

void Mines::setCollisionWithTank(bool collisionWithTank) {
	CollisionWithTank = collisionWithTank;
}

bool Mines::isResetMines() const {
	return resetMines;
}

void Mines::setResetMines(bool resetMines) {
	this->resetMines = resetMines;
}
