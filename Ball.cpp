#include "Ball.hpp"

Ball::Ball()
	:m_maxVectorUp(0.32f, -0.95f)
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

	checkHit(playerOne);
	checkHit(playerTwo);
	std::cout << m_direction.x << " " << m_direction.y << std::endl;
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

void Ball::checkHit(Player * player)
{
	
	if (this->getBounds().intersects(player->getBounds(), m_hitResult) && m_playerOneHit)
	{
		if (player->getPlayerId() == Player::PlayerOne)
		{
			m_relativeHit = m_hitResult.top - player->getBounds().top + m_sprite.getGlobalBounds().width / 2;

			if ((m_relativeHit <= (113.f / 5.f)) && (m_relativeHit >= 0) && m_playerOneHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(0.32f, -0.95f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerOneHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 2.f) && (m_relativeHit >= (113.f / 5.f)) && m_playerOneHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(0.55f, -0.83f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerOneHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 3.f) && (m_relativeHit >= (113.f / 5.f) * 2.f) && m_playerOneHit)
			{
				m_direction.x *= -1;
				//normalizeVector(m_direction);
				//m_direction *= m_speed;
				std::cout << "Hallo" << std::endl;
				m_playerOneHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 4.f) && (m_relativeHit >= (113.f / 5.f) * 3.f) && m_playerOneHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(-0.55f, 0.83f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerOneHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 5.f) && (m_relativeHit <= (113.f / 5.f) * 4.f) && m_playerOneHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(-0.32f, 0.95f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerOneHit = false;
			}
			m_playerTwoHit = true;
		}
		
	}
	

	
	if (this->getBounds().intersects(player->getBounds(), m_hitResult) && m_playerTwoHit)
	{
		if (player->getPlayerId() == Player::PlayerTwo)
		{
			m_relativeHit = m_hitResult.top - player->getBounds().top + m_sprite.getGlobalBounds().width / 2;

			if ((m_relativeHit <= (113.f / 5.f)) && (m_relativeHit >= 0) && m_playerTwoHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(0.32f, -0.95f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerTwoHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 2.f) && (m_relativeHit >= (113.f / 5.f)) && m_playerTwoHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(0.55f, -0.83f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerTwoHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 3.f) && (m_relativeHit >= (113.f / 5.f) * 2.f) && m_playerTwoHit)
			{
				std::cout << m_direction.x << " " << m_direction.y << std::endl;
				m_direction.x *= -1.f;
				//normalizeVector(m_direction);
				//m_direction *= m_speed;
				std::cout << m_direction.x << " " << m_direction.y << std::endl;
				m_playerTwoHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 4.f) && (m_relativeHit >= (113.f / 5.f) * 3.f) && m_playerTwoHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(-0.55f, 0.83f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerTwoHit = false;
			}
			if ((m_relativeHit <= (113.f / 5.f) * 5.f) && (m_relativeHit <= (113.f / 5.f) * 4.f) && m_playerTwoHit)
			{
				m_direction.x *= -1;
				normalizeVector(m_direction);
				m_direction += sf::Vector2f(-0.32f, 0.95f);
				normalizeVector(m_direction);
				m_direction *= m_speed;
				m_playerTwoHit = false;
			}
			m_playerOneHit = true;
		}
			
	}
	
	
}


