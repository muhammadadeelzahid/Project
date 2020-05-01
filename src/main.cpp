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
int main()
{
	//this is the main files
	int sizeScreen = 780 ;
	int sizeOfObject  =  15 ;
	Interface game(sizeScreen,sizeOfObject) ;
	sf::RenderWindow window(sf::VideoMode(sizeScreen,sizeScreen), "Game");
	game.drawMaze() ;

	while (window.isOpen())
    {
		sf::Color background (220,220,220) ;
	 	window.clear(background);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
            	cout<<"FIRE TANK 01"<<endl ;
            	game.fire(0) ;
            }
        }

        game.display(window) ;
    }
	return 0;
}

