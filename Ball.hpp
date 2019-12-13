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

	int scorePlayerOne = 0;
	int scorePlayerTwo = 0;

private:

	void normalizeVector(sf::Vector2f& vector);

	bool m_ballOut = false;
	float m_time = 0;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_maxVectorUp = -0.71f;
	float m_maxVectorDown = 0.71f;
	sf::FloatRect m_hitResult;
	sf::FloatRect m_middle = sf::FloatRect(sf::Vector2f(1400.f / 2.f, 800.f / 2.f), sf::Vector2f(1.f, 1.f));

	sf::Vector2f m_direction;
	const float m_speed = 800.f;
	float m_relativeHit;
};

