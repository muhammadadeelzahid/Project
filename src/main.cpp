//============================================================================
// Name        : Adeel.cpp
// Author      : Adeel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Interface.h"
#include "Brick.h" // most probably wont be used as it doesnt require any specialized function
#include "Bullet.h"
#include "Tank.h"
int main()
{
	//this is the main files
	int sizeScreen = 700 ;
	Interface game(sizeScreen) ;

	sf::RenderWindow window(sf::VideoMode(sizeScreen,sizeScreen), "Game");
	/*
	sf::RectangleShape shape  ;
	shape.setPosition(50,50);
    shape.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(10, 10)); //10x10 box
   */
	game.drawMaze() ;
    while (window.isOpen())
    {
      	window.clear(sf::Color::White);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    //    game.display(window) ;
        //temporary code below
    	//for the bricks
    	sf::RectangleShape *Brick = new sf::RectangleShape [game.getSize()*game.getSize()] ; // pointer to create the objects of Brick
    	int counter = 0  ;
    	for (int i = 0 ; i<game.getSize() ; i++)
    	{
    		Brick[i].setSize(sf::Vector2f(20, 20)); //10x10 box
    		Brick[i].setFillColor(sf::Color::Black);
    	}
    	/*
    	sf::RectangleShape Brick;
    	Brick.setSize(sf::Vector2f(10, 10)); //10x10 box
       	Brick.setFillColor(sf::Color::Black);
       	Brick.setPosition(0,0);
    	*/

    	for (int i = 0 ; i<=game.getSize() ; i++)
    	{
    		for (int j = 0 ; j<=game.getSize(); j ++)
    		{
    			if (game.getCoordinates()[i][j] == 1 )
    			{
    				Brick[counter].setPosition(i*10,j*10) ; // i*10 because the size of the box is of 10 units
    				window.draw(Brick[i]) ;
    				counter++ ;
    			}
    		}
    	}
    	window.display() ;
//temporary code ends
    }



    return 0;
}
