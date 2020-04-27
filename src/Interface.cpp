/*
 * Interface.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Interface.h"

Interface::Interface() {
	score = 0 ;
	this->size = 25 ;
	coordinates = new int*[size] ;
	for(int i = 0 ; i<size ; i++)
	{
		coordinates[i] = new int[size] ;
	}

}
Interface::Interface(int size)
{
	this->size = size/10 ;
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

}
int** Interface::getCoordinates()  {
	return coordinates;
}

int Interface::getScore() const {
	return score;
}

void Interface::setScore(int score) {
	this->score = score;
}

Interface::~Interface() {
	// TODO Auto-generated destructor stub
}
void Interface::drawMaze()
{
		//top most row

		for (int i = 0 ; i<this->size; i++)
		{
			coordinates[0][i] = 1 ; // 1 is the  token for a brick
			cout<<"0,"<<i<<endl ;
		}
		//left most coloumn

		for (int i = 0 ; i<this->size; i++)
		{
			coordinates[i][0] = 1 ; // 1 is the  token for a brick
		}
		//bottom most row
		for (int i = 0 ; i<this->size; i++)
		{
			coordinates[0][size-1] = 1 ; // 1 is the  token for a brick
		}
		//right most coloum
		for (int i = 0 ; i<this->size; i++)
		{
			coordinates[size-1][i] = 1 ; // 1 is the  token for a brick
		}

}
void Interface::display(sf::RenderWindow &window)
{
	drawMaze() ;
	//for the bricks
	sf::RectangleShape *Brick = new sf::RectangleShape [size*size] ; // pointer to create the objects of Brick
	int counter = 0  ;
	for (int i = 0 ; i<size ; i++)
	{
		Brick[i].setSize(sf::Vector2f(20, 20)); //10x10 box
		Brick[i].setFillColor(sf::Color::Black);
	}
	/*
	sf::RectangleShape Brick;
	Brick.setSize(sf::Vector2f(10, 10)); //10x10 box
   	Brick.setFillColor(sf::Color::Black);
   	Brick.setPosition(0,0);
	*/

	coordinates[40][40] = 1 ;
	Brick[200].setPosition(50,60) ;
	window.draw(Brick[200]) ;
	for (int i = 0 ; i<=size ; i++)
	{
		for (int j = 0 ; j<=size; j ++)
		{
			if (coordinates[i][j] == 1 )
			{
				Brick[counter].setPosition(i*10,j*10) ; // i*10 because the size of the box is of 10 units
				window.draw(Brick[i]) ;
				counter++ ;
			}
		}
	}
	window.display() ;

}

