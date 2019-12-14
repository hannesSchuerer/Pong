#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.hpp"
#include "MenueScene.hpp"
#include <stack>

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
	void initSceneData();
	void initScene();

	float m_dt;
	sf::VideoMode m_videoMode;
	sf::Clock m_clock;
	sf::RenderWindow* m_window;
	sf::Event m_event;
	SceneData m_sceneData;
	std::stack<Scene*> m_scene;
};

