//============================================================================
// Name        : Adeel.cpp
// Author      : Adeel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "Brick.h"
#include "Bullet.h"
#include "Tank.h"
int main()
{
	cout << "Hello From the windows side" << endl;
	cout<<"Yes hello from the MAC side"<<endl ;
	cout<<"Game"<<endl ;
    sf::RenderWindow window(sf::VideoMode(200,200), "Hello World");
    sf::CircleShape shape(100.f);
    shape.setPointCount(128);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
