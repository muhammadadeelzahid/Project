/*
 * Bullet.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Bullet.h"

Bullet::Bullet() {
	//bullet.setFillColor(sf::Color::Black) ;
//	bullet.setRadius(5);
	float sizeofBullets = 0.05;
	bullet.setScale(sizeofBullets,sizeofBullets) ;


	if (!t.loadFromFile("circle.png"))
	    {
	        std::cout << "Image Loading failed for bullet" << std::endl;
	        getchar() ;
	    }
	bullet.setTexture(t);


	RotationAngle = 0 ;
}

 sf::Sprite & Bullet::getBullet()
 {
	 return bullet;
}

void Bullet::setBullet(const sf::Sprite &bullet) {
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
