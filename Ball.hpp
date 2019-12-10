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
	void checkHit(Player* player);

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	bool m_playerOneHit = true;
	bool m_playerTwoHit = true;

	sf::Vector2f m_maxVectorUp;
	sf::Vector2f m_maxVectorDown;
	sf::FloatRect m_hitResult;

	sf::Vector2f m_direction;
	float m_speed = 400.f;
	float m_relativeHit;
};

