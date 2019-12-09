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
	void update(const float & dt, Player& playerOne, Player& playerTwo);
	sf::FloatRect getBounds();

private:

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_speed;
};

