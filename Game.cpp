#include "Game.hpp"

Game::Game()
{
	m_videoMode.width = 1400;
	m_videoMode.height = 800;
	m_window = new sf::RenderWindow(m_videoMode, "Pong");
	m_window->setFramerateLimit(60);

	initVariables();
	initSceneData();
	initScene();
}


Game::~Game()
{
	delete m_window;
	
	while (!this->m_scene.empty())
	{
		delete this->m_scene.top();
		m_scene.pop();
	}

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
	if (!this->m_scene.empty())
	{
		this->m_scene.top()->update(m_dt);
	}
}

void Game::render()
{
	m_window->clear();

	if (!this->m_scene.empty())
	{
		this->m_scene.top()->draw();
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

}

void Game::initSceneData()
{
	m_sceneData.scene = &m_scene;
	m_sceneData.window = m_window;
}

void Game::initScene()
{
	m_scene.push(new MenueScene(&m_sceneData));
}
