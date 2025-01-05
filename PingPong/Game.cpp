#include "Game.h"

void Game::initVariables()
{
	this->bgColor = sf::Color(0, 0, 0);
	this->gameVideoMode.width = 800;
	this->gameVideoMode.height = 800;
}

void Game::initPlayers()
{
	float playerWidth = 20;
	float playerHeight = 120;

	player1.setFillColor(sf::Color(235, 64, 52));
	player1.setSize(sf::Vector2f(playerWidth, playerHeight));
	player1.setPosition(0, this->gameVideoMode.height / 2 - playerHeight / 2);


	player2.setFillColor(sf::Color(55, 52, 235));
	player2.setSize(sf::Vector2f(playerWidth, playerHeight));
	player2.setPosition(this->gameVideoMode.width - playerWidth, this->gameVideoMode.height / 2 - playerHeight / 2);
}

void Game::initWindow()
{
	this->gameWindow = new sf::RenderWindow(this->gameVideoMode, "Ping Pong", sf::Style::Titlebar | sf::Style::Close);

	this->gameWindow->setFramerateLimit(60);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayers();

}

Game::~Game()
{
	delete this->gameWindow;
}

const bool Game::getWindowIsOpen()
{
	return this->gameWindow->isOpen();
}

void Game::pullEvents()
{
	while (this->gameWindow->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->gameWindow->close();
			break;
		}
	}
}

void Game::update()
{
	this->dt = clock.restart().asSeconds();
	this->pullEvents();
}

void Game::render()
{
	this->gameWindow->clear(this->bgColor);
	this->gameWindow->draw(player1);
	this->gameWindow->draw(player2);
	this->gameWindow->display();
}

