#include "Player.hpp"

Player::Player()
{
	if (!m_texture.loadFromFile("Sprites/PongPlayer.png"))
	{
		std::cerr << "Cant load player" << std::endl;
	}
	else
	{
		m_sprite.setTexture(m_texture);
	}
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow & target)
{
	target.draw(m_sprite);
}

void Player::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

void Player::setSpeed(float speed)
{
	m_speed = speed;
}

void Player::update(const float& dt)
{
	if (m_id == ID::PlayerOne)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_sprite.getPosition().y >= 0)
			m_sprite.move(0, -m_speed*dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_sprite.getPosition().y <= 800 - m_sprite.getLocalBounds().height)
			m_sprite.move(0, m_speed*dt);
	}
	if (m_id == ID::PlayerTwo)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_sprite.getPosition().y >= 0)
			m_sprite.move(0, -m_speed*dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_sprite.getPosition().y <= 800 - m_sprite.getLocalBounds().height)
			m_sprite.move(0, m_speed*dt);
	}
}

void Player::setPlayerId(ID id)
{
	m_id = id;
}

sf::FloatRect Player::getBounds()
{
	return m_sprite.getGlobalBounds();
}
