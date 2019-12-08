#include "Game.hpp"

Game::Game()
{
	m_videoMode.width = 1400;
	m_videoMode.height = 800;
	m_window = new sf::RenderWindow(m_videoMode, "Pong");
	m_window->setFramerateLimit(60);

	initVariables();
}


Game::~Game()
{
	delete m_window;
	delete m_background;
	delete m_playerOne;
	delete m_playerTwo;
}

void Game::run()
{
	while (m_window->isOpen())
	{
		updateDeltaTime();
		updateEvent();
		update();
		render();
	}
}

void Game::update()
{
	m_playerOne->update(m_dt);
	m_playerTwo->update(m_dt);
}

void Game::render()
{
	m_window->clear();

	m_background->draw(*m_window);
	m_playerOne->draw(*m_window);
	m_playerTwo->draw(*m_window);

	m_window->display();
}

void Game::updateDeltaTime()
{
	m_dt = m_clock.restart().asSeconds();
}

void Game::updateEvent()
{
	while (m_window->pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window->close();
			break;
		}
	}
}

void Game::initVariables()
{
	m_background = new Background();
	m_playerOne = new Player();
	m_playerTwo = new Player();

	m_playerOne->setPlayerId(Player::ID::PlayerOne);
	m_playerOne->setPosition(sf::Vector2f(50.f, (m_videoMode.height/2)-(m_playerOne->getSize().height/2)));
	m_playerOne->setSpeed(500.f);

	m_playerTwo->setPlayerId(Player::ID::PlayerTwo);
	m_playerTwo->setPosition(sf::Vector2f(m_videoMode.width-50-m_playerTwo->getSize().width, (m_videoMode.height / 2) - (m_playerOne->getSize().height / 2)));
	m_playerTwo->setSpeed(500.f);
}
