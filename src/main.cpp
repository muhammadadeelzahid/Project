//============================================================================
// Name        : Adeel.cpp
// Author      : Adeel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cmath>
#include "Interface.h"
#include "Bullet.h"
#include "Tank.h"
#include "Wall.h" // most probably wont be used as it doesnt require any specialized function
void MoveBulletsTimed(sf::Clock &clock ,Interface &game) ;
int main()
{
	sf::Clock clock ;

	//this is the main files
	int sizeScreen = 780 ;
	int sizeOfObject  =  26 ;
	int mazeNumber = 3;
	int sizeForBar = 780 ;
	Interface game(sizeForBar,sizeOfObject) ;
	game.drawMaze(mazeNumber);

	sf::RenderWindow stats(sf::VideoMode(400,250), "Game Stats") ;
	stats.setPosition(sf::Vector2i(10,200)) ;

	sf::RenderWindow window(sf::VideoMode(sizeForBar,sizeScreen), "Game");
	window.setPosition(sf::Vector2i(window.getPosition().x+100,window.getPosition().y)) ;
	while (window.isOpen())
    {

		sf::Color background (220,220,220) ;
	 	window.clear(background);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if( event.type == sf::Event::KeyPressed)
            {
            	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            	{
            		game.fire(0) ;
            		cout<<"Fire tank 1"<<endl;
            	}
            	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            	{
            		game.fire(1) ;
            		cout<<"Fire Tank 2"<<endl;
            	}
        		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        		   {
        			game.moveTank("Up",1) ; // Move tank Number 1 upwards //index of arrays start from 0
        		   }
        		   if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        		   {
        			game.moveTank("Down",1) ; // Move tank Number 1 Down
        		   }
        		   if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        		   {
        			game.moveTank("Right",1) ; // Move tank Number 1 Right
        		   }
        		   if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        		   {
        			game.moveTank("Left",1) ; // Move tank Number 1 Left
        		   }

            }
            //logic for movement starts

        	//make changes here below to control the movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
            	game.moveTank("Up",0) ; // Move tank Number 1 upwards //index of arrays start from 0
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
            	game.moveTank("Down",0) ; // Move tank Number 1 Down
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
            	game.moveTank("Right",0) ; // Move tank Number 1 Right
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
            	game.moveTank("Left",0) ; // Move tank Number 1 Left
            }

        }

        MoveBulletsTimed(clock,game);
        game.BulletscollisionWithTank() ;
		game.StopGame() ;
        game.display(window) ;
        window.display();
    }
	return 0;
}
void MoveBulletsTimed(sf::Clock &clock ,Interface &game)
{
	if( clock.getElapsedTime() > sf::milliseconds(25)  )
	{
		game.moveBullets() ;
		clock.restart();
	}
}

