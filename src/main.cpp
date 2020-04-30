//============================================================================
// Name        : Adeel.cpp
// Author      : Adeel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Interface.h"
#include "Bullet.h"
#include "Tank.h"
#include "Wall.h" // most probably wont be used as it doesnt require any specialized function
int main()
{
	//this is the main files
	int sizeScreen = 780 ;
	int sizeOfObject  =  30 ;
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
        }
        //logic for movement starts
        int movementDistance = 1 ;
    	sf::Sprite *temp = &game.getTanks()[0].getTank() ;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
        	if (temp->getRotation() == 0 || temp->getRotation() == 180 ) {
        			temp->rotate(90) ;
        			if (game.collisionTankWall())
        			{
        				temp->rotate(-90) ;
        			}
        		}
        	else
        	{
        		temp->move(movementDistance,0) ;
    			if (game.collisionTankWall())
            		temp->move(-movementDistance,0) ;

        	}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
        	if (temp->getRotation() == 270 )
        	{
        			temp->rotate(-90) ;
        			if (game.collisionTankWall())
            			temp->rotate(+90) ;

        	}
        	else if ( temp->getRotation() == 90)
        	{
        			temp->rotate(90) ;
        			if (game.collisionTankWall())
            			temp->rotate(-90) ;

        	}
        	else{
        		temp->move(0,movementDistance) ;
    			if (game.collisionTankWall())
        			temp->move(0,-movementDistance) ;

        	}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
        	if (temp->getRotation() == 90 ){
        		temp->rotate(-90) ;
    			if (game.collisionTankWall())
        			temp->rotate(+90) ;

        	}else if (temp->getRotation() == 270){
        			temp->rotate(90) ;
        			if (game.collisionTankWall())
            			temp->rotate(-90) ;

        	}else
        		temp->move(0,-movementDistance) ;
				if (game.collisionTankWall())
					temp->move(0,movementDistance) ;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
        	if ( temp->getRotation() == 0 ){
        		temp->rotate(-90) ;
    			if (game.collisionTankWall())
        			temp->rotate(+90) ;

        	}else if ( temp->getRotation() == 180){
        			temp->rotate(90) ;
        			if (game.collisionTankWall())
            			temp->rotate(-90) ;

        	}else{
        		temp->move(-movementDistance,0) ;
    			if (game.collisionTankWall())
    				temp->move(movementDistance,0) ;
         	}
        }
        //logic for movement ends

        game.display(window) ;
    }
	return 0;
}
