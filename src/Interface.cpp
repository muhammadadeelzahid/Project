/*
 * Interface.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Interface.h"

Interface::Interface() {
	score = 0 ;
	this->sizeOfScreen = 25 ;
	coordinates = new int*[sizeOfScreen] ;
	for(int i = 0 ; i<sizeOfScreen ; i++)
	{
		coordinates[i] = new int[sizeOfScreen] ;
	}

}
Interface::Interface(int size)
{
	this->sizeOfScreen = size/10 ;
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
	return sizeOfScreen;
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

		for (int i = 0 ; i<this->sizeOfScreen; i++)
		{
			coordinates[0][i] = 1 ; // 1 is the  token for a brick
		}
		//left most coloumn

		for (int j = 0 ; j<this->sizeOfScreen; j++)
		{
			coordinates[j][0] = 1 ; // 1 is the  token for a brick
		}
		//bottom most row
		for (int k = 0 ; k<this->sizeOfScreen; k++)
		{
			coordinates[k][sizeOfScreen-1] = 1 ; // 1 is the  token for a brick
		}
		//right most coloum
		for (int l = 0 ; l<this->sizeOfScreen; l++)
		{
			coordinates[sizeOfScreen-1][l] = 1 ; // 1 is the  token for a brick
		}

}
void Interface::display(sf::RenderWindow &window)
{

	//for the bricks
	sf::RectangleShape *Brick = new sf::RectangleShape [sizeOfScreen*sizeOfScreen] ; // pointer to create the objects of Brick
 	sf::VertexArray *Bricks = new sf::VertexArray [sizeOfScreen*sizeOfScreen];

 	for(int i = 0 ; i<sizeOfScreen*sizeOfScreen ; i++)
 	{
 		Bricks[i].resize(4) ;
 		Bricks[i].setPrimitiveType(sf::Quads) ;
 		Bricks[i][0].color = sf::Color::Blue ;
 		Bricks[i][1].color = (sf::Color::Blue) ;
 		Bricks[i][2].color = (sf::Color::Blue) ;
 		Bricks[i][3].color=(sf::Color::Blue) ;
 	}

	int counter = 0  ;
	for (int i = 0 ; i<sizeOfScreen*sizeOfScreen; i++)
	{
		Brick[i].setSize(sf::Vector2f(10,10)); //10x10 box
		Brick[i].setFillColor(sf::Color::Black);
	}
	int xcordinate ; int ycordinate ;

	for (int i = 0 ; i<=sizeOfScreen ; i++)
	{
		for (int j = 0 ; j<=sizeOfScreen; j ++)
		{
			if (coordinates[i][j] == 1 )
			{

				xcordinate = i*10 ;  ycordinate = j*10;
				sf::Vector2f cord1  (xcordinate,ycordinate);
				sf::Vector2f cord2  (xcordinate+10,ycordinate);
				sf::Vector2f cord3  (xcordinate,ycordinate+10);
				sf::Vector2f cord4  (xcordinate+10,ycordinate+10);
				Bricks[counter][0].position=(cord1) ;
				Bricks[counter][1].position=(cord2) ;
				Bricks[counter][2].position=(cord3) ;
				Bricks[counter][3].position=(cord4) ;
				window.draw(Bricks[counter]) ;


//				Brick[counter].setPosition(xcordinate,ycordinate) ; // i*10 because the size of the box is of 10 units
				
//				window.draw(Brick[counter]) ;
				counter++ ;
				cout<<endl;
			}
		}
	}
	delete [] Bricks; delete [] Brick ;
}


