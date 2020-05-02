/*
 * Bullet.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Bullet.h"

Bullet::Bullet() {
	bullet.setFillColor(sf::Color::Black) ;
	bullet.setRadius(5);
	bullet.setScale(1,1) ;
	/*
	if (!t.loadFromFile("BulletA.jpg"))
	    {
	        std::cout << "Image Loading failed for bullet" << std::endl;
	        getchar() ;
	    }
	    */
	//this->bullet.setTexture(t);


	RotationAngle = 0 ;
}

 sf::CircleShape & Bullet::getBullet()
 {
	 return bullet;
}

void Bullet::setBullet(const sf::CircleShape &bullet) {
	this->bullet = bullet;
}



void Bullet::draw(sf::RenderWindow &window)
{
	window.draw(bullet) ;
}
void Bullet::startTimer()
{
	this->clock.restart() ;
}
bool Bullet::CheckBulletTimeout()
{
	if (clock.getElapsedTime() > sf::seconds(5))
	{
		return true ;
	}
	return false ;
}
