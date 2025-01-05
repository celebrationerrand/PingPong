#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game
{
private:
	sf::RenderWindow* gameWindow;
	sf::VideoMode gameVideoMode;
	sf::Event ev;

	sf::Color bgColor;

	sf::RectangleShape player1;
	sf::RectangleShape player2;

	sf::Clock clock;
	float dt;

	void initVariables();
	void initPlayers();
	void initWindow();
public:

	Game();
	virtual ~Game();

	const bool getWindowIsOpen();

	void pullEvents();
	void update();
	void render();

};

