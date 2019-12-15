#include "Scene.hpp"

Scene::Scene(SceneData * sceneData)
{
	this->window = sceneData->window;
	this->scene = sceneData->scene;
	this->sceneData = sceneData;
}

void Scene::endScene()
{
	this->quit = true;
}

bool & Scene::getQuit()
{
	return this->quit;
}

