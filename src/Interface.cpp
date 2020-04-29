/*
 * Interface.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Interface.h"
Interface::Interface(int size)
{
	this->sizeofcoordinates = size/screenFactor ;
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
	bricks.setObjectsize(screenFactor) ; // set the size of the bricks
	bricks.initialise(sizeofcoordinates) ;
}

int** Interface::getCoordinates()  {
	return coordinates;
}

int Interface::getScore() const {
	return score;
}

int Interface::getSize() const {
	return sizeofcoordinates;
}

void Interface::setScore(int score) {
	this->score = score;
}

Interface::~Interface() {
}
void Interface::drawMaze()
{
	//draw all maze here

	//top most row

	for (int i = 0 ; i<this->sizeofcoordinates; i++)
	{
		coordinates[0][i] = 1 ; // 1 is the  token for a brick
	}
	//left most coloumn

	for (int j = 0 ; j<this->sizeofcoordinates; j++)
	{
		coordinates[j][0] = 1 ; // 1 is the  token for a brick
	}
	//bottom most row
	for (int k = 0 ; k<this->sizeofcoordinates; k++)
	{
		coordinates[k][sizeofcoordinates-1] = 1 ; // 1 is the  token for a brick
	}
	//right most coloum
	for (int l = 0 ; l<this->sizeofcoordinates; l++)
	{
		coordinates[sizeofcoordinates-1][l] = 1 ; // 1 is the  token for a brick
	}
	//for first vertical line  from left
	for (int m = 0; m < this->sizeofcoordinates; m++) {
		if(m<this->sizeofcoordinates/3|| m>2*(this->sizeofcoordinates/3) )
		coordinates[sizeofcoordinates/4][m] = 1;
	}

	//for second vertical line from left
	for (int n = 0; n < this->sizeofcoordinates; n++) {
		if (n<this->sizeofcoordinates / 3)
			coordinates[sizeofcoordinates / 2][n] = 1;
		if ((n>this->sizeofcoordinates / 2) & n <(5*(this->sizeofcoordinates/6)))
		coordinates[sizeofcoordinates / 2][n] = 1;
	}
	//1st horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3*(this->sizeofcoordinates / 4))
			coordinates[k][sizeofcoordinates/6] = 1;
	}
	//2nd horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4))
			coordinates[k][sizeofcoordinates / 3] = 1;
	}
	//3rd horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4))
			coordinates[k][sizeofcoordinates / 2] = 1;
	}
	//4th horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4))
			coordinates[k][2*(sizeofcoordinates /3) ] = 1;
	}
	//5th horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4) )
			coordinates[k][5*(sizeofcoordinates / 6)] = 1;
		if (k>this->sizeofcoordinates/4 && k<this->sizeofcoordinates*0.52)
			coordinates[k][5 * (sizeofcoordinates / 6)] = 1;
	}


}
void Interface::display(sf::RenderWindow &window)
{
	//MAKE CHANGES FOR THE (X,Y) OF EVERY NEW OBJECT TO BE DRAWN
	int counter = 0  ;
	int xcordinate ; int ycordinate ;
	for (int i = 0 ; i<=sizeofcoordinates ; i++)
	{
		for (int j = 0 ; j<=sizeofcoordinates; j ++)
		{
			//xcordinate = 0 ; ycordinate = 0 ;
			xcordinate = i*screenFactor ; ycordinate=j*screenFactor ;
			//now draw that object
			if (coordinates[i][j] == 1 )
			{
				//1 is the token for a brick/wall
					cout<<"xcordinate: "<<(xcordinate)<<" ycordinate: "<<(ycordinate)<<endl;
					bricks.getBrick()[counter].setPosition(xcordinate,ycordinate) ;
					cout<<bricks.getBrick()[counter].getPosition().x<<","<<bricks.getBrick()[counter].getPosition().y<<endl ;

					window.draw(bricks.getBrick()[counter]) ;
					counter++ ;
			}

		}
	}


	//end of function
	window.display() ;

}


