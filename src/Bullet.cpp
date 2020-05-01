/*
 * Bullet.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Bullet.h"

Bullet::Bullet() {
	if (!t.loadFromFile("Bullet.png"))
	    {
	        std::cout << "Image Loading failed for bullet" << std::endl;
	        getchar() ;
	    }
	this->bullet.setTexture(t);
	RotationAngle = 0 ;
}

const sf::Sprite& Bullet::getBullet() const {
	return bullet;
}

void Bullet::setBullet(const sf::Sprite &bullet) {
	this->bullet = bullet;
}


int Bullet::getRotationAngle() const {
	return RotationAngle;
}

void Bullet::setRotationAngle(int rotationAngle) {
	RotationAngle = rotationAngle;
}
void Bullet::draw(sf::RenderWindow &window)
{
	window.draw(bullet);
}

