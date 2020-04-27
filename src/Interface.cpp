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

int Interface::getSize() const {
	return size;
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
		}
		//left most coloumn

		for (int j = 0 ; j<this->size; j++)
		{
			coordinates[j][0] = 1 ; // 1 is the  token for a brick
		}
		//bottom most row
		for (int k = 0 ; k<this->size; k++)
		{
			coordinates[k][size-1] = 1 ; // 1 is the  token for a brick
		}
		//right most coloum
		for (int l = 0 ; l<this->size; l++)
		{
			coordinates[size-1][l] = 1 ; // 1 is the  token for a brick
		}

}
void Interface::display(sf::RenderWindow &window)
{

	//for the bricks
	sf::RectangleShape *Brick = new sf::RectangleShape [size*size] ; // pointer to create the objects of Brick
	int counter = 0  ;
	for (int i = 0 ; i<size ; i++)
	{
		Brick[i].setSize(sf::Vector2f(10,10)); //10x10 box
		Brick[i].setFillColor(sf::Color::Black);
	}
	int xcordinate ; int ycordinate ;
	for (int i = 0 ; i<=size ; i++)
	{
		for (int j = 0 ; j<=size; j ++)
		{
			if (coordinates[i][j] == 1 )
			{
				xcordinate = i*10 ;  ycordinate = j*10;

				cout<<"setPosition( "<<xcordinate<<" j= "<<ycordinate<<")"<<endl ;

				Brick[counter].setPosition(xcordinate,ycordinate) ; // i*10 because the size of the box is of 10 units
				cout<<"GetPosition("<<(Brick[counter].getPosition().x)<<" , "<<(Brick[counter].getPosition().y)<<")"<<endl ;
				window.draw(Brick[counter]) ;
				counter++ ;
				cout<<endl;
			}
		}
	}

}


