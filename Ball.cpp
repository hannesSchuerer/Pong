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
	
	m_direction = sf::Vector2f(1.f, 0);
	m_direction *= m_speed;
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

void Ball::update(const float & dt, Player* playerOne, Player* playerTwo)
{
	m_sprite.move(m_direction*dt);
	
	if ((m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2 <= 0)|| (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2 >= 800))
	{
		m_direction.y *= -1;
	}	

	if (m_sprite.getGlobalBounds().intersects(playerOne->getBounds(), m_hitResult))
	{
		m_relativeHit = m_hitResult.top - playerOne->getBounds().top + m_sprite.getGlobalBounds().width / 2;
		if (m_relativeHit < (113.f / 5.f) * 3.f)
		{
			normalizeVector(m_direction);
			m_direction.x = 1.f;
			m_direction.y += m_maxVectorUp;
			normalizeVector(m_direction);
			m_direction *= m_speed;
		}
		else
		{
			normalizeVector(m_direction);
			m_direction.x = 1.f;
			m_direction.y += m_maxVectorDown;
			normalizeVector(m_direction);
			m_direction *= m_speed;
		}
	
	}
		

	if (m_sprite.getGlobalBounds().intersects(playerTwo->getBounds(), m_hitResult))
	{
		m_relativeHit = m_hitResult.top - playerTwo->getBounds().top + m_sprite.getGlobalBounds().width / 2;
		if (m_relativeHit < (113.f / 5.f) * 3.f)
		{
			normalizeVector(m_direction);
			m_direction.x = -1.f;
			m_direction.y += m_maxVectorUp;
			normalizeVector(m_direction);
			m_direction *= m_speed;
		}
		else
		{
			normalizeVector(m_direction);
			m_direction.x = -1.f;
			m_direction.y += m_maxVectorDown;
			normalizeVector(m_direction);
			m_direction *= m_speed;
		}
	}

}

sf::FloatRect Ball::getBounds()
{
	return m_sprite.getGlobalBounds();
}

void Ball::normalizeVector(sf::Vector2f & vector)
{
	float length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (length != 0)
		vector = sf::Vector2f(vector.x / length, vector.y / length);
}


