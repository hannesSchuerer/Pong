#include "PvPScene.hpp"



PvPScene::PvPScene(sf::VideoMode videoMode)
{
	this->m_videoMode = videoMode;
	initScene();
}


PvPScene::~PvPScene()
{
	delete m_background;
	delete m_playerOne;
	delete m_playerTwo;
	delete m_ball;
}

void PvPScene::initScene()
{
	m_background = new Background();
	m_playerOne = new Player();
	m_playerTwo = new Player();
	m_ball = new Ball();

	m_playerOne->setPlayerId(Player::ID::PlayerOne);
	m_playerOne->setPosition(sf::Vector2f(50.f, (m_videoMode.height / 2) - (m_playerOne->getBounds().height / 2)));
	m_playerOne->setSpeed(500.f);

	m_playerTwo->setPlayerId(Player::ID::PlayerTwo);
	m_playerTwo->setPosition(sf::Vector2f(m_videoMode.width - 50 - m_playerTwo->getBounds().width, (m_videoMode.height / 2) - (m_playerOne->getBounds().height / 2)));
	m_playerTwo->setSpeed(500.f);

	m_ball->setPosition(sf::Vector2f(m_videoMode.width / 2.f, m_videoMode.height / 2.f));
}

void PvPScene::draw(sf::RenderWindow & target)
{
	m_background->draw(target);
	m_playerOne->draw(target);
	m_playerTwo->draw(target);
	m_ball->draw(target);
}

void PvPScene::update(const float & dt)
{
	m_playerOne->update(dt);
	m_playerTwo->update(dt);
	m_startTime += dt;
	if (m_startTime >= 3)
		m_ball->update(dt, m_playerOne, m_playerTwo);
}

Scene::ID PvPScene::getId()
{
	return id;
}
