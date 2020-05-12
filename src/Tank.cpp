/*
 * Tank.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Tank.h"

Tank::Tank() {
	status = 1;
	score = 0 ;
	lives = 2 ;
	this->setTokenValue(2) ;
	firedbullets = 0;
	//setting the texture ;
	for (int i = 0 ; i<50 ; i++)
	{
		bullets[i].getBullet().setPosition(-1,-1) ;
	}
}
void Tank::draw(sf::RenderWindow & window)
{

	if (status == 1 )
		window.draw(this->tank) ;

	//now for the bullets
	for (int i  = 0 ; i<this->firedbullets ;i++)
	{
		bullets[i].draw(window);
	}
}


void Tank::initialiseTank(int i)
{
    tank.setPosition(3,3);
//    tank[i].
 }


 sf::Sprite& Tank::getTank()  {
	return tank;
}

int Tank::getFiredbullets()  {
	return firedbullets;
}

void Tank::setFiredbullets(int firedbullets) {
	this->firedbullets = firedbullets;
	this->bullets[firedbullets].startTimer() ;
}

int Tank::getStatus() const {
	return status;
}

void Tank::setStatus(int status) {
	this->status = status;
}

int Tank::getLives() const {
	return lives;
}

void Tank::setLives(int lives) {
	this->lives = lives;
}

void Tank::setScore(int score) {
	this->score = score;
}

int Tank::getScore() const {
	return score;
}
