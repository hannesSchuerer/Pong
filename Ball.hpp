#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"

class Ball
{
public:
	Ball();
	~Ball();
	void draw(sf::RenderWindow& target);
	void setPosition(sf::Vector2f pos);
	void update(const float & dt, Player* playerOne, Player* playerTwo);
	sf::FloatRect getBounds();

private:

	void normalizeVector(sf::Vector2f& vector);

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_maxVectorUp = sf::Vector2f(0.71f, -0.71f);
	sf::Vector2f m_maxVectorDown = sf::Vector2f(-0.71f, 0.71f);
	sf::FloatRect m_hitResult;

	sf::Vector2f m_direction;
	float m_speed = 400.f;
	float m_relativeHit;
};

