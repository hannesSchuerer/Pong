#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Background.hpp"
#include "Player.hpp"
#include "Ball.hpp"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void update();
	void render();
	void updateDeltaTime();
	void updateEvent();
	void initVariables();

	float m_dt;
	sf::VideoMode m_videoMode;
	sf::Clock m_clock;
	sf::RenderWindow* m_window;
	sf::Event m_event;

	Background* m_background = nullptr;
	Player* m_playerOne = nullptr;
	Player* m_playerTwo = nullptr;
	Ball* m_ball = nullptr;
	
};

