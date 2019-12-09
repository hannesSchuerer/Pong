#include "Ball.hpp"

Ball::Ball()
{
	if (!m_texture.loadFromFile("Sprites/PongBall.png"))
	{
		std::cerr << "Cant load player" << std::endl;
	}
	else
	{
		m_sprite.setTexture(m_texture);
	}
	m_sprite.setOrigin(m_sprite.getGlobalBounds().height / 2, m_sprite.getGlobalBounds().width / 2);
	
	m_speed = sf::Vector2f(400.f, 0);
	
}


Ball::~Ball()
{
}

void Ball::draw(sf::RenderWindow & target)
{
	target.draw(m_sprite);
}

void Ball::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

void Ball::update(const float & dt, Player& playerOne, Player& playerTwo)
{
	m_sprite.move(m_speed*dt);
	
	if (this->getBounds().intersects(playerOne.getBounds()) || this->getBounds().intersects(playerTwo.getBounds()))
	{
		std::cout << "Collision" << std::endl;
		m_speed.x *= -1;
		m_speed.y *= -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_speed.x = 0;
		m_speed.y = 0;
	}
}

sf::FloatRect Ball::getBounds()
{
	return m_sprite.getGlobalBounds();
}


