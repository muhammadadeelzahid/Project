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
	sf::RenderWindow window(sf::VideoMode(sizeScreen,sizeScreen), "Game");
	//    sf::CircleShape shape(100.f);
	//		shape.setPointCount(128);
    ///	shape.setFillColor(sf::Color::Green);
	Interface game(sizeScreen) ;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        game.drawMaze() ;
        game.display(window) ;
    }

    return 0;
}
