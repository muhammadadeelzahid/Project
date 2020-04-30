/*
 * Interface.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Interface.h"
Interface::Interface(int size,int ratio)
{
	screenFactor = ratio ;
	brickcounter =0 ;
	this->sizeofcoordinates = size/screenFactor ;
	score = 0 ;
	coordinates = new int*[sizeofcoordinates] ;
	for(int i = 0 ; i<sizeofcoordinates ; i++)
	{
		coordinates[i] = new int[sizeofcoordinates] ;
	}
	for (int i = 0 ; i<sizeofcoordinates ;i ++)
	{
		for ( int j = 0 ; j<sizeofcoordinates ; j++)
		{
			coordinates[i][j] = 0 ;
		}
	}
	bricks.setObjectsize(screenFactor) ; // set the size of the bricks
	bricks.initialise(sizeofcoordinates) ;

	tankcount = 1 ;
	tanks = new Tank[tankcount] ;
	tanks[0].tank.setPosition(10*30,10*30) ;
	//coordinates[2][2] = 2;
	if (!texture1.loadFromFile("tank[0].png"))
	    {
	        std::cout << "Image Loading failed" << std::endl;
	        getchar() ;
	    }
	tanks[0].tank.setTexture(texture1) ;

}

int** Interface::getCoordinates()  {
	return coordinates;
}

int Interface::getScore() const {
	return score;
}

 Tank*& Interface::getTanks()  {
	return tanks;
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
		brickcounter++ ;
	}
	//left most coloumn

	for (int j = 0 ; j<this->sizeofcoordinates; j++)
	{
		coordinates[j][0] = 1 ; // 1 is the  token for a brick
		brickcounter++ ;

	}
	//bottom most row
	for (int k = 0 ; k<this->sizeofcoordinates; k++)
	{
		coordinates[k][sizeofcoordinates-1] = 1 ; // 1 is the  token for a brick
		brickcounter++ ;

	}
	//right most coloum
	for (int l = 0 ; l<this->sizeofcoordinates; l++)
	{
		coordinates[sizeofcoordinates-1][l] = 1 ; // 1 is the  token for a brick
		brickcounter++ ;

	}
	//for first vertical line  from left
	for (int m = 0; m < this->sizeofcoordinates; m++) {
		if(m<this->sizeofcoordinates/3|| m>2*(this->sizeofcoordinates/3) )
		{
			coordinates[sizeofcoordinates/4][m] = 1;
			brickcounter++ ;

		}
	}

	//for second vertical line from left
	for (int n = 0; n < this->sizeofcoordinates; n++) {
		if (n<this->sizeofcoordinates / 3)
		{
			coordinates[sizeofcoordinates / 2][n] = 1;
			brickcounter++ ;
		}
		if ((n>this->sizeofcoordinates / 2) & n <(5*(this->sizeofcoordinates/6)))
		{
			coordinates[sizeofcoordinates / 2][n] = 1;
			brickcounter++ ;

		}
	}
	//1st horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3*(this->sizeofcoordinates / 4))
		{
			coordinates[k][sizeofcoordinates/6] = 1; 		brickcounter++ ;
		}

	}
	//2nd horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4))
		{	coordinates[k][sizeofcoordinates / 3] = 1;		brickcounter++ ;
		}
	}
	//3rd horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4))
		{
			coordinates[k][sizeofcoordinates / 2] = 1;		brickcounter++ ;
		}
	}
	//4th horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4))
		{
			coordinates[k][2*(sizeofcoordinates /3) ] = 1;		brickcounter++ ;
		}
	}
	//5th horizontal line from top
	for (int k = 0; k < this->sizeofcoordinates; k++) {
		if (k>3 * (this->sizeofcoordinates / 4) )
		{
			coordinates[k][5*(sizeofcoordinates / 6)] = 1;		brickcounter++ ;
		}
		if (k>this->sizeofcoordinates/4 && k<this->sizeofcoordinates*0.52)
		{
			coordinates[k][5 * (sizeofcoordinates / 6)] = 1;		brickcounter++ ;
		}
	}
/*	for(int i = 0 ; i<sizeofcoordinates ; i++)
	{
		for (int j =0 ; j<sizeofcoordinates ;j++)
		{
			cout<<coordinates[i][j]<<" " ;
		}
		cout<<endl ;
	}
	getchar() ;	*/
}
void Interface::display(sf::RenderWindow &window)
{
	int counter = 0  ;
	int row ; int col ;
	for (int i = 0 ; i<sizeofcoordinates ; i++)
	{
		for (int j = 0 ; j<sizeofcoordinates; j ++)
		{
			row = i*screenFactor ; col = j*screenFactor ;
			if (coordinates[i][j] == 1 )
			{
				//1 is the token for a brick/wall
//					cout<<"row: "<<(i)<<" col: "<<(j)<<endl;
					bricks.getBrick()[counter].setPosition(row,col) ;
	//				cout<<bricks.getBrick()[counter].getPosition().x<<","<<bricks.getBrick()[counter].getPosition().y<<endl ;
					window.draw(bricks.getBrick()[counter]) ;
					counter++ ;
			}
			/*
			if (coordinates[i][j] == 2 )
			{
				tanks[0].tank.setPosition(i*this->screenFactor,j*screenFactor) ;
				cout<<tanks[0].tank.getPosition().x<<","<<tanks[0].tank.getPosition().y<<endl ;
				window.draw(tanks[0].tank) ;
			}
			*/
		}
	}
//	cout<<tanks[0].tank.getPosition().x<<","<<tanks[0].tank.getPosition().y<<endl ;
	window.draw(this->tanks[0].tank);
	//end of function
	window.display() ;
}
bool Interface::collisionTankWall()
{
	for(int i = 0 ; i<brickcounter ;i++)
	{
		if ( tanks[0].tank.getGlobalBounds().intersects(bricks.getBrick()[i].getGlobalBounds() ))
		{
			cout<<"COLLISION"<<endl ;
			/*
			cout<<tanks[0].tank.getPosition().x<<"=="<<bricks.getBrick()[i].getPosition().x<<"----" ;
			cout<<tanks[0].tank.getPosition().y<<"=="<<bricks.getBrick()[i].getPosition().y<<"----"<<endl ;

			cout<<"Height"<<bricks.getBrick()[i].getGlobalBounds().height<<endl ;
			cout<<"Width"<<bricks.getBrick()[i].getGlobalBounds().width<<endl ;
			cout<<"Top"<<bricks.getBrick()[i].getGlobalBounds().top<<endl ;
			cout<<"Left"<<bricks.getBrick()[i].getGlobalBounds().left<<endl ;

			cout<<endl ;
			cout<<"Height "<<tanks[0].tank.getGlobalBounds().height<<endl ;
			cout<<"Width "<<tanks[0].tank.getGlobalBounds().width<<endl ;
			cout<<"Top "<<tanks[0].tank.getGlobalBounds().top<<endl ;
			cout<<"Left "<<tanks[0].tank.getGlobalBounds().left<<endl ;
			*/
			return true ;
		}
	}
	return false ;

}


