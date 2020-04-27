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
        game.display(window) ;
        window.display();



    }



    return 0;
}
