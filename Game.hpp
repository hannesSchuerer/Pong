#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.hpp"
#include "PvPScene.hpp"

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

	Scene::ID m_sceneState = Scene::PvP;

	Scene* m_pvpScene;
};

