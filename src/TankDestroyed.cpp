/*
 * TankDestroyed.cpp
 *
 *  Created on: May 5, 2020
 *      Author: AdeelZahid
 */

#include "TankDestroyed.h"

TankDestroyed::TankDestroyed() {
	start = 0 ;
}
void TankDestroyed::draw(sf::RenderWindow &window)
{
	if (start == 1)
	{
		cout<<"Draw image 1"<<endl;
		if (!texture.loadFromFile("flames/Explosion_C.png"))
		{
			cout<<"Unable to load image Explosion_C"<<endl;
		}
	}
	else if (start ==2 )
	{
		cout<<"Image 2"<<endl;
		if (!texture.loadFromFile("flames/Explosion_C.png"))
		{
			cout<<"Unable to load image Explosion_C"<<endl;
		}

	}
	else if (start == 3 )
	{
		cout<<"Image 3"<<endl;
		if (!texture.loadFromFile("flames/Explosion_E.png"))
		{
			cout<<"Unable to load image Explosion_E"<<endl;
		}

	}
	else if (start == 4)
	{
		if (!texture.loadFromFile("flames/Explosion_F.png"))
		{
			cout<<"Unable to load image Explosion_F"<<endl;
		}

	}
	else if (start == 5 )
	{
		if (!texture.loadFromFile("flames/Explosion_G.png"))
		{
			cout<<"Unable to load image Explosion_G"<<endl;
		}

	}
	if (start != 0  && start < 6)
	{
		cout<<"Drawing image "<<start<<endl;
		flames.setTexture(texture) ;
		window.draw(flames) ;
		if( start == 1)
			start++ ;
	}

}

int TankDestroyed::getStart() const {
	return start;
}

void TankDestroyed::setStart(int start) {
	this->start = start;
}

TankDestroyed::~TankDestroyed() {
	// TODO Auto-generated destructor stub
}

