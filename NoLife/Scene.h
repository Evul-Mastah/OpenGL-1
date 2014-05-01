#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "shaderprogram.h"

class Scene
{
public:
	static Scene& getInstance();

	//ShaderProgram *shaderProgram; //Wskaźnik na obiekt reprezentujący program cieniujący.

	glm::mat4  matP;//rzutowania
	glm::mat4  matV;//widoku
	glm::mat4  matM;//modelu

protected:
	static Scene scene;

	Scene();

	Scene(Scene const&);
	void operator=(Scene const&);

};

