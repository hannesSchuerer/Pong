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
	delete m_pvpScene;
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
	switch (m_sceneState)
	{
	case Scene::PvP:
		m_pvpScene->update(m_dt);
		break;
	case Scene::Menue:
		break;
	}
}

void Game::render()
{
	m_window->clear();

	switch (m_sceneState)
	{
	case Scene::PvP:
		m_pvpScene->draw(*m_window);
		break;
	case Scene::Menue:
		break;
	}

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
	m_pvpScene = new PvPScene(m_videoMode);
}
