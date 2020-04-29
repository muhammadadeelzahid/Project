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
        game.display(window) ;
    }



    return 0;
}
