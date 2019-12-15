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
	bool quit = false;

	virtual void update(const float& dt) = 0;
	virtual void draw() = 0;
	virtual void endScene();
	virtual bool& getQuit();

	std::stack<Scene*>* scene;
	sf::RenderWindow* window;
};

