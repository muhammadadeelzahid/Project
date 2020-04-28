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
 		brick[i].setSize(sf::Vector2f (screenFactor,screenFactor));
 		sf::Color grey (112,128,144);
 		brick[i].setFillColor(grey) ;
 		brick[i].setOutlineThickness(1) ;
 		brick[i].setOutlineColor(sf::Color::Black) ;
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
	//draw all maze here

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
	//for first vertical line  from left
	for (int m = 0; m < this->screensize; m++) {
		if(m<this->screensize/3|| m>2*(this->screensize/3) )
		coordinates[screensize/4][m] = 1;
	}

	//for second vertical line from left
	for (int n = 0; n < this->screensize; n++) {
		if (n<this->screensize / 3)
			coordinates[screensize / 2][n] = 1;
		if ((n>this->screensize / 2) & n <(5*(this->screensize/6)))
		coordinates[screensize / 2][n] = 1;
	}
	//1st horizontal line from top
	for (int k = 0; k < this->screensize; k++) {
		if (k>3*(this->screensize / 4))
			coordinates[k][screensize/6] = 1;
	}
	//2nd horizontal line from top
	for (int k = 0; k < this->screensize; k++) {
		if (k>3 * (this->screensize / 4))
			coordinates[k][screensize / 3] = 1;
	}
	//3rd horizontal line from top
	for (int k = 0; k < this->screensize; k++) {
		if (k>3 * (this->screensize / 4))
			coordinates[k][screensize / 2] = 1;
	}
	//4th horizontal line from top
	for (int k = 0; k < this->screensize; k++) {
		if (k>3 * (this->screensize / 4))
			coordinates[k][2*(screensize /3) ] = 1;
	}
	//5th horizontal line from top
	for (int k = 0; k < this->screensize; k++) {
		if (k>3 * (this->screensize / 4) )
			coordinates[k][5*(screensize / 6)] = 1;
		if (k>this->screensize/4 && k<this->screensize*0.52)
			coordinates[k][5 * (screensize / 6)] = 1;
	}


}
void Interface::display(sf::RenderWindow &window)
{
	int counter = 0  ;
	int xcordinate ; int ycordinate ;
	for (int i = 0 ; i<=screensize ; i++)
	{
		for (int j = 0 ; j<=screensize; j ++)
		{
			if (coordinates[i][j] == 1 )
			{
					xcordinate = i*screenFactor ;  ycordinate = j*screenFactor;
					cout<<"xcordinate: "<<xcordinate<<" ycordinate: "<<ycordinate<<endl;

					brick[counter].setPosition(xcordinate,ycordinate) ;
					cout<<brick[counter].getPosition().x<<","<<brick[counter].getPosition().y<<endl ;

					window.draw(brick[counter]) ;
					counter++ ;
			}
		}
	}
}


