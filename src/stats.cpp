/*
 * stats.cpp
 *
 *  Created on: May 7, 2020
 *      Author: AdeelZahid
 */

#include "stats.h"

stats::stats() {
	currentScreen = 1;
	if (!font.loadFromFile("font.ttf")) {
		cout << "Unable to load font" << endl;
	}
	text.setFont(font);

	if (!icons.loadFromFile("menue.jpg")) {
		cout << "Unable to load picture" << endl;
	}
	s.setTexture(icons);

}
void stats::setGame(Interface &game) {
	this->game = &game;
}

int stats::getCurrentScreen() const {
	return currentScreen;
}

void stats::updateCurrentScreen() {
	this->currentScreen = currentScreen + 1;
}
void stats::draw(sf::RenderWindow &window) {
	if (currentScreen == 1) {
		window.clear(sf::Color(120, 120, 120, 0));
		text.setString("Tank Attack Maze (N to start)");
		text.setColor(sf::Color::Black);
		text.setCharacterSize(50);
		text.setPosition(sf::Vector2f(50, 100));
//		window.draw(s) ;
		window.draw(text);
	}
	if (currentScreen == 4) {
		window.clear(sf::Color(120, 120, 120, 0));
		text.setString("Game Over R to reset");
		text.setColor(sf::Color::Black);
		text.setCharacterSize(50);
		text.setPosition(sf::Vector2f(100, 100));
//		window.draw(s) ;
		window.draw(text);

		text.setString("Previous Scores ") ;
		text.setPosition(sf::Vector2f(100,200));
		window.draw(text);

		text.setString("Team A: ") ;
		text.setPosition(sf::Vector2f(100,300));
		window.draw(text);

		text.setString(readScore1) ;
		text.setPosition(sf::Vector2f(400,300));
		window.draw(text);

		text.setString("Team B: ") ;
		text.setPosition(sf::Vector2f(100,400));
		window.draw(text);

		text.setString(readScore2) ;
		text.setPosition(sf::Vector2f(400,400));
		window.draw(text);

		text.setString("Press T to Reset") ;
		text.setPosition(sf::Vector2f(150,500));
		window.draw(text);

	}
}

void stats::draw2(sf::RenderWindow &window) {
	if (currentScreen == 3 || currentScreen == 1) {
		window.clear(sf::Color::White);

		text.setColor(sf::Color::Black);
		text.setCharacterSize(20);

		text.setString("Scores");
		text.setPosition(sf::Vector2f(150, 50));
		window.draw(text);

		text.setString("Team 1:");
		text.setPosition(sf::Vector2f(10, 80));
		window.draw(text);

		text.setString("Team 2:");
		text.setPosition(sf::Vector2f(250, 80));
		window.draw(text);

		text.setString(to_string(game->getTanks()[0].getScore())) ;;
		scoret1 = game->getTanks()[0].getScore() ;
		scoret2 = game->getTanks()[1].getScore() ;
		text.setColor(sf::Color::Red);
		text.setPosition(sf::Vector2f(100, 80));
		window.draw(text);

		text.setString(to_string(game->getTanks()[1].getScore())) ;;
		text.setColor(sf::Color::Red);
		text.setPosition(sf::Vector2f(350, 80));
		window.draw(text);
		if (game->isGameOver() == true && game->getChangeStateDelay() == 4) {
			//savetoFile() ;
			readFromFile() ;
		}
	}
}

stats::~stats() {
	// TODO Auto-generated destructor stub
}
void stats::savetoFile()
{
	ofstream file ;
	file.open("score.txt",ios::trunc);
	if (!file.is_open())
	{
		cout<<"Unable to open file to write"<<endl;
	}
	file<<to_string(scoret1)<<"-"<<to_string(scoret2)<<">\n" ;
	file.close() ;
}
void stats::readFromFile(){
	ifstream file;
	file.open("score.txt");
	if (!file.is_open())
		cout<<"Unable to open file to read"<<endl;
	string score1 ;
	string scoret;
	while (!file.eof())
	{
		getline(file,score1);
		cout<<"Length of this line : "<<score1.length()<<endl;
		if( score1.length() != 0 )
			scoret = score1 ;
	}
	readScore1 = "" ;
	readScore2 = "";
	for (int i = 0 ; i<scoret.length() ;i++)
	{
		if (scoret[i] == '-')
		{
			for (int j = 0 ; j<i ;j++)
			{
				readScore1 += scoret[j] ;
			}
			for (int j = i +1; j<scoret.length()-1 ; j++)
			{
				readScore2 += scoret[j] ;
			}
		}
	}
	cout<<"Score for team 1 previous : "<<readScore1<<endl;
	cout<<"Score for team 2 previous : "<<readScore2<<endl;
	file.close() ;
}

void stats::setCurrentScreen(int currentScreen) {
	this->currentScreen = currentScreen;
}
