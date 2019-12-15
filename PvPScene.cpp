#include "PvPScene.hpp"



PvPScene::PvPScene(SceneData* sceneData)
	:Scene(sceneData)
{
	initScene();
}


PvPScene::~PvPScene()
{
	delete m_background;
	delete m_playerOne;
	delete m_playerTwo;
	delete m_ball;
	delete m_scorePlayerOne;
	delete m_scorePlayerTwo;
}

void PvPScene::initScene()
{
	m_background = new Background();
	m_playerOne = new Player();
	m_playerTwo = new Player();
	m_ball = new Ball();
	m_scorePlayerOne = new Text("Fonts/Pixeled.ttf", sf::Vector2f(350.f, 200.f), 50);
	m_scorePlayerTwo = new Text("Fonts/Pixeled.ttf", sf::Vector2f(1050.f, 200.f), 50);

	m_playerOne->setPlayerId(Player::ID::PlayerOne);
	m_playerOne->setPosition(sf::Vector2f(50.f, (window->getSize().y / 2) - (m_playerOne->getBounds().height / 2)));
	m_playerOne->setSpeed(500.f);

	m_playerTwo->setPlayerId(Player::ID::PlayerTwo);
	m_playerTwo->setPosition(sf::Vector2f(window->getSize().x - 50 - m_playerTwo->getBounds().width, (window->getSize().y / 2) - (m_playerOne->getBounds().height / 2)));
	m_playerTwo->setSpeed(500.f);

	m_ball->setPosition(sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f));
}


void PvPScene::draw()
{
	m_background->draw(*this->window);
	m_playerOne->draw(*this->window);
	m_playerTwo->draw(*this->window);
	m_ball->draw(*this->window);
	m_scorePlayerOne->draw(*this->window);
	m_scorePlayerTwo->draw(*this->window);
}

void PvPScene::update(const float & dt)
{
	m_playerOne->update(dt);
	m_playerTwo->update(dt);

	m_scorePlayerOne->update(std::to_string(m_ball->scorePlayerOne));
	m_scorePlayerTwo->update(std::to_string(m_ball->scorePlayerTwo));

	if (m_ball->scorePlayerTwo > 9 || m_ball->scorePlayerOne > 9)
	{
		quit = true;
	}

	if (m_firstStart)
	{
		m_startTime += dt;
		if (m_startTime >= 3)
		{
			m_firstStart = false;
		}
	}
	else
		m_ball->update(dt, m_playerOne, m_playerTwo);
	
}

