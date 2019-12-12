#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:

	enum ID
	{
		Menue,
		PvP
	};
	
	virtual void update(const float& dt) = 0;
	virtual void draw(sf::RenderWindow& target) = 0;

};

