#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

class Scene;

class SceneData
{
public:
	sf::RenderWindow* window;
	std::stack<Scene*>* scene;
};

class Scene
{
public:

	enum ID
	{
		Menue,
		PvP
	};
	
	Scene(SceneData* sceneData);

	SceneData* sceneData;

	virtual void update(const float& dt) = 0;
	virtual void draw() = 0;

	std::stack<Scene*>* scene;
	sf::RenderWindow* window;
};

