#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Background
{
public:
	Background();
	~Background();

	void draw(sf::RenderWindow& target);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

