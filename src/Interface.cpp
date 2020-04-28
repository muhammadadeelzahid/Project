/*
 * Interface.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Interface.h"
Interface::Interface(int size)
{
	this->screensize = size/screenFactor ;
	score = 0 ;
	coordinates = new int*[size] ;
	for(int i = 0 ; i<size ; i++)
	{
		coordinates[i] = new int[size] ;
	}
	for (int i = 0 ; i<size ;i ++)
	{
		for ( int j = 0 ; j<size ; j++)
		{
			coordinates[i][j] = 0 ;
		}
	}
	BrickInitialise() ;
}
void Interface::BrickInitialise()
{
 	brick = new sf::RectangleShape [screensize*screensize];
 	for (int i = 0 ; i<screensize*screensize ; i++)
 	{
 		brick[i].setFillColor(sf::Color::Black) ;
 		brick[i].setOutlineThickness(1) ;
 		brick[i].setOutlineColor(sf::Color::White) ;
 	}



}
int** Interface::getCoordinates()  {
	return coordinates;
}

int Interface::getScore() const {
	return score;
}

int Interface::getSize() const {
	return screensize;
}

void Interface::setScore(int score) {
	this->score = score;
}

Interface::~Interface() {
	delete [] brick ;
}
void Interface::drawMaze()
{
		//top most row

		for (int i = 0 ; i<this->screensize; i++)
		{
			coordinates[0][i] = 1 ; // 1 is the  token for a brick
		}
		//left most coloumn

		for (int j = 0 ; j<this->screensize; j++)
		{
			coordinates[j][0] = 1 ; // 1 is the  token for a brick
		}
		//bottom most row
		for (int k = 0 ; k<this->screensize; k++)
		{
			coordinates[k][screensize-1] = 1 ; // 1 is the  token for a brick
		}
		//right most coloum
		for (int l = 0 ; l<this->screensize; l++)
		{
			coordinates[screensize-1][l] = 1 ; // 1 is the  token for a brick
		}

}
void Interface::display(sf::RenderWindow &window)
{
//
	int counter = 0  ;
	int xcordinate ; int ycordinate ;
	for (int i = 0 ; i<=screensize ; i++)
	{
		for (int j = 0 ; j<=screensize; j ++)
		{
			if (coordinates[i][j] == 1 )
			{
					xcordinate = i*screenFactor ;  ycordinate = j*screenFactor;
					cout<<"xcordinate: "<<xcordinate<<"ycordinate"<<ycordinate<<endl;
					brick[counter].setPosition(xcordinate,ycordinate) ;
					window.draw(brick[counter]) ;
					cout<<brick[counter].getPosition().x<<","<<brick[counter].getPosition().y<<endl ;
					counter++ ;
			}
		}
	}
}


