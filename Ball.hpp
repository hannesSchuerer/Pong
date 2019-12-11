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

	float m_maxVectorUp = -0.71f;
	float m_maxVectorDown = 0.71f;
	sf::FloatRect m_hitResult;

	sf::Vector2f m_direction;
	const float m_speed = 800.f;
	float m_relativeHit;
};

