/*
 * Brick.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Wall.h"

Wall::Wall() {
	this->setObjectsize(30);
	this->setTokenValue(1) ;
	//brick = new sf::RectangleShape [NULL] ;
	sf::Color grey (112,128,144);
//

}

 sf::RectangleShape*& Wall::getBrick()  {
	return brick;
}


void Wall::initialise(int screensize)
{
	sf::Color grey (112,128,144);
 	brick = new sf::RectangleShape [screensize*screensize];
 	orientation = new string [screensize*screensize] ;
 	/*
 	//Creating the image for the Brick
	sf::Image img;
	int size = screensize ;
	img.create(size,size,grey);
	for (int i = 0; i<size ;i++)
	{
		for (int j = 0 ; j<3; j++)
		{
			img.setPixel(i,j,sf::Color::Black) ;
		}
	}
	for (int i = 0 ; i<size; i++)
	{
		for (int j = 0 ; j<3; j++)
		{
		img.setPixel(j,i,sf::Color::Black) ;
		}

	}
	for (int i = 0 ; i<size; i++)
	{
		for (int j = 1 ; j<=3; j++)
		{
		img.setPixel(i,size-j,sf::Color::Black) ;
		}
	}
	for (int i = 0 ; i<size; i++)
	{

		for (int j = 1 ; j<=3; j++)
		{		img.setPixel(size-j,i,sf::Color::Black) ;

		}
	}
	this->brickTexture.loadFromImage(img);
*/
 	for (int i = 0 ; i<screensize*screensize ; i++)
 	{
// 		brick[i].setTexture(brickTexture);

 		brick[i].setSize(sf::Vector2f (getObjectsize(),getObjectsize()));
 		brick[i].setFillColor(grey) ;
 		brick[i].setOutlineThickness(1.5) ;
 		brick[i].setOutlineColor(sf::Color::Black) ;
 	}
}
