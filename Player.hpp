#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	enum ID
	{
		PlayerOne,
		PlayerTwo
	};

	void draw(sf::RenderWindow& target);
	void setPosition(sf::Vector2f pos);
	void setSpeed(float speed);
	void update(float dt);
	void setPlayerId(ID id);
	sf::FloatRect getSize();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_speed;

	ID m_id;

};

