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
	delete [] this->coordinates ;
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
		}
	}
//	cout<<tanks[0].tank.getPosition().x<<","<<tanks[0].tank.getPosition().y<<endl ;
	for(int i = 0 ; i<this->tankcount ;i++)
	{
		this->tanks[i].draw(window) ;
	}
	//end of function
	window.display() ;
}
bool Interface::collisionTankWall(int tankNumber)
{
	for(int i = 0 ; i<brickcounter ;i++)
	{
		if ( tanks[tankNumber].tank.getGlobalBounds().intersects(bricks.getBrick()[i].getGlobalBounds() ))
		{
//			cout<<"COLLISION"<<endl ;
			return true ;
		}
	}
	//cout<<"No collision"<<endl ;
	return false ;
}
void Interface::moveTank(string direction,int tankNumber)
{
	sf::Sprite *temp = &this->tanks[tankNumber].getTank() ;
	 float distance = 10 ; //distance to be moved // controls the speed of movement
	 //the key factors for movement is the direction of the movement and the angle at which the tank is rotated
	 if (direction == "Up")
	 	 {
	 		 int angle = temp->getRotation() ;
	 		 switch (angle)
	 		 {
	 			 case 0:
	 					temp->move(+0,-distance) ;
	 					if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 						temp->move(0,+distance) ;
	 						break;
	 			 case 45:
	 						temp->move(+distance,-distance) ;
	 						if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 							temp->move(-distance,+distance) ;
	 						 break;
	 			 case 90:
	 				 temp->move(+distance, 0);
	 				 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(-distance, 0);
	 				 break;
	 			 case 135:
	 				 temp->move(+distance, distance);
	 				 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(-distance, -distance);
	 				 break;
	 			 case 180:
	 				 temp->move(0, distance);
	 				 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(0, -distance);
	 				 break;
	 			 case 225:
	 				 temp->move(-distance, distance);
	 				 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(distance, -distance);
	 				 break;
	 			 case 270:
	 				 temp->move(-distance, 0);
	 				 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(distance, 0);
	 				 break;
	 			 case 315:
	 				 temp->move(-distance, -distance);
	 				 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(distance, distance);
	 				 break;

	 		 }
	 	 }
	 	 else if (direction == "Down")
	 	 {
	 		 int angle = temp->getRotation();
	 		 switch (angle)
	 		 {
	 		 case 0:
	 			 temp->move(+0, distance);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(0, -distance);
	 			 break;
	 		 case 45:
	 			 temp->move(-distance, distance);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(distance, -distance);
	 			 break;
	 		 case 90:
	 			 temp->move(-distance, 0);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(distance, 0);
	 			 break;
	 		 case 135:
	 			 temp->move(-distance, -distance);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(distance, distance);
	 			 break;
	 		 case 180:
	 			 temp->move(0, -distance);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(0, distance);
	 			 break;
	 		 case 225:
	 			 temp->move(distance, -distance);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(-distance, distance);
	 			 break;
	 		 case 270:
	 			 temp->move(distance, 0);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(-distance, 0);
	 			 break;
	 		 case 315:
	 			 temp->move(distance, distance);
	 			 if (this->collisionTankWall(tankNumber)) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(-distance, -distance);
	 			 break;

	 		 }
	 	 }
	 else if ( direction == "Right")
	 {
		 temp->rotate(45) ;
		 if ((this->collisionTankWall(tankNumber)) )
			 temp->rotate(-45) ;
	 }
	 else if ( direction == "Left")
	 {
		 temp->rotate(-45) ;
		 if ((this->collisionTankWall(tankNumber)) )
			 temp->rotate(+45) ;
	 }

}


//function call is controlled by the timer in main.cpp
void Interface::	destroyBullet()
{
	// destroy a bullet based on its own timer
}

void Interface::fire(int tankNumber)
{
	if (tanks[tankNumber].firedbullets <=5 )
	{
		this->tanks[tankNumber].bullets[tanks[tankNumber].firedbullets].startTimer() ;

		tanks[tankNumber].bullets[tanks[tankNumber].firedbullets].bullet.setRotation(tanks[tankNumber].tank.getRotation()) ;//set same rotation as that of the tank

//		cout<<"Bullets Remaining"<<tanks[tankNumber].firedbullets <<endl;
		cout<<tanks[tankNumber].tank.getPosition().x<<","<<tanks[tankNumber].tank.getPosition().y<<endl ;
		tanks[tankNumber].bullets[tanks[tankNumber].firedbullets].bullet.setPosition(tanks[tankNumber].tank.getPosition()) ;// set the same position as that of tank
		cout<<tanks[tankNumber].bullets[tanks[tankNumber].firedbullets].bullet.getPosition().x<<","<<tanks[tankNumber].bullets[tanks[tankNumber].firedbullets].bullet.getPosition().x<<endl<<endl;
		tanks[tankNumber].setFiredbullets(tanks[tankNumber].getFiredbullets()+1);
	}
	else
		cout<<"All bullets used"<<endl ;
		//code to move the current bullet one step forward
}
//function call is controlled by the timer in main.cpp
void Interface::moveBullets()
{
		//	cout<<"Moving bullets"<<endl ;
			//move all bullets for all tanks
		for (int i = 0; i < this->tankcount; i++)
		{
			for (int j = 0; j < this->tanks[i].firedbullets; j++)
			{
				//				//code the logic for movement of bullets based on their rotation angle .. logic is same as that of movement of tank
				sf::CircleShape *temp = &this->tanks[i].bullets[j].getBullet();
				float distance = 10;
				int angle = temp->getRotation();

				cout << "Angle is" << temp->getRotation()<<endl;
				float x = 0, y = 0;
				switch (angle)
				{
				case 0:
					x = temp->getPosition().x ;
					y = temp->getPosition().y - distance;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				case 45:

					x = temp->getPosition().x + distance;
					y = temp->getPosition().y - distance;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				case 90:

					x = temp->getPosition().x + distance;
					y = temp->getPosition().y;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				case 135:

					x = temp->getPosition().x + distance;
					y = temp->getPosition().y + distance;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				case 180:

					x = temp->getPosition().x;
					y = temp->getPosition().y + distance;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				case 225:

					x = temp->getPosition().x - distance;
					y = temp->getPosition().y + distance;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				case 270:

					x = temp->getPosition().x - distance;
					y = temp->getPosition().y;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				case 315:

					x = temp->getPosition().x - distance;
					y = temp->getPosition().y - distance;
					temp->setPosition(sf::Vector2f(x, y));
					break;
				default:
					cout << "No Angle Matching " << endl;
				}
					//now check collision of the bullet with tanks
					BulletscollisionWithTank();

					//now check collision of the bullet with the walls
					BulletscollisionWithWalls();


					//why all the bullets disappear when one bullet timesout
					if (this->tanks[i].bullets[j].CheckBulletTimeout())
					{
						//				cout<<"Times up for bullet: "<<j<<endl ;
						for (int a = 1; a <= tanks[i].firedbullets; a++)
						{
							this->tanks[i].bullets[a - 1] = this->tanks[i].bullets[a];
						}
						tanks[i].firedbullets--;
					}
				}
		}
}
void Interface::BulletscollisionWithTank()
{
//	cout<<"Checking collision of bullets with Tank"<<endl ;
	for(int i =0 ; i<tankcount ; i++)
	{
		for (int j = 0 ; j <tanks[i].firedbullets; j++)
		{
			if (tanks[i].bullets[j].bullet.getGlobalBounds().intersects(tanks[i].tank.getGlobalBounds()))
			{
				tanks[i].status = 1 ;
				//cout<<"Bullets collision with tank"<<i<<endl ;
				//getchar() ;
			}
		}
	}
}
void Interface::BulletscollisionWithWalls()
{
	//cout<<"Checking collision of bullets with Walls"<<endl ;
	for(int i = 0 ; i<this->brickcounter ;i++)
	{
		for (int j = 0 ; j<tankcount ; j++)
		{
				for (int k  =0 ; k<tanks[j].firedbullets ; k++)
				{
					if ( tanks[j].bullets[k].bullet.getGlobalBounds().intersects(bricks.brick[i].getGlobalBounds()))
					{
						//code for reflection of bullet
						cout<<"Bullet reflected"<<endl ;
					}
				}

		}
	}
}





