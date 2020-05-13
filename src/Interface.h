/*
 * Interface.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 *///a

#ifndef INTERFACE_H_
#define INTERFACE_H_
//#include "Collision.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include "Wall.h"
#include "Tank.h"
#include "Mines.h"
#include "TankDestroyed.h"
using namespace std ;
class Interface {
	//basic array that identifies with each token of the object
	bool gameOver ;
	TankDestroyed destruction;	// this is for the flames and smoke effect when tanks are destroyed
	int **coordinates ;//set the size in the constructor
	int sizeofcoordinates ; // size of screen /screenFactor
	int screenFactor ; //Walls and spaces will be of 15x15
	int brickcounter ;
	//all the arrays of the Game objects we will use
	Wall bricks ;
	Tank *tanks ;
	int tankcount; //number of tanks
	sf::Texture texture1 ; //texture for tank1
	sf::Texture texture2 ;//texture for tank2
	int startDelay ;
	int currentMaze ;
	//temporary stuff
	sf::Image img ;
	sf::Sprite temp1 ;
	sf::Texture temp;
//for Maze Changing delays
	sf::Sprite s;
	sf::Texture t;
	int changeStateDelay ; //variable to give a delay after one maze ends and load the next maze

	Mines mine ;

	sf::Sprite pause;
	sf::Texture pauseMessage;

	Shape **drawables; //this is to benifit from polymorphic pointer to display overriden functions in one go
	int shapeCount ;
public:
	//functions involving movement and collision of Bullets
	void moveBullets() ;
	void maze1() ;
	void maze2() ;
	void maze3() ;
	void BulletscollisionWithWalls();
	void BulletscollisionWithTank();
	void BombscollisionWithTank();
	void fire(int tankNumber);
	void destroyBullet();
	void reset() ;

	//functions involving movement and collision of Bullets Ends
	void moveTank(string direction,int tankNumber) ;
	bool collisionTankWall(int tankNumber) ;

	//function for flames
	void increment(sf::Clock &clock2) ;

	//function for the mines
	void setMineCoordinates();

	Interface(int,int) ;
	void drawMaze() ;
	void display(sf::RenderWindow &window) ;
	virtual ~Interface();
	int** getCoordinates() ;
	int getScore() const;
	void setScore(int score);
	int getSize() const;
	 Tank*& getTanks() ;
	int getPause() const;
	void setPause(int pause);
	 TankDestroyed& getDestruction() ;
	 void DestroyBullet2();
	void setDestruction( TankDestroyed &destruction);
	void Maze_Change_And_Pause_Message(sf::RenderWindow &window) ;
	int getChangeStateDelay() const;
	void setChangeStateDelay(int changeStateDelay);



	bool isGameOver() const;
	void setGameOver(bool gameOver);
	void forcedReset() ;
	int getCurrentMaze() const;
	void setCurrentMaze(int currentMaze);

	//for rotation of the array of coordinates
private:
	void mirror (int **a, int **b, int x);
	void roteste90(int **a, int **b, int n, int m);
	void fix();


};

#endif /* INTERFACE_H_ */
