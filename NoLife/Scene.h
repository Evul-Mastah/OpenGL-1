#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "shaderprogram.h"

class Scene
{
public:
	static Scene& getInstance();

	void initScene();

	bool isInitialized(void);

	//Uchwyty na shadery
	ShaderProgram *shaderProgram; //Wskaźnik na obiekt reprezentujący program cieniujący.
	ShaderProgram *shaderProgram2D; //Wskaźnik na obiekt reprezentujący program cieniujący w przestrzeni 2D - interfejs użytkownika.
	ShaderProgram *shaderProgramPro;
	ShaderProgram *shaderProgramProTex;

	//ShaderProgram *shaderProgram; //Wskaźnik na obiekt reprezentujący program cieniujący.

	glm::mat4  matP;//rzutowania
	glm::mat4  matV;//widoku
	glm::mat4  matM;//modelu


protected:
	static Scene scene;

	bool initialized = false;

	Scene();

	Scene(Scene const&);
	void operator=(Scene const&);

	
	void setupShaders();
	void cleanShaders();

};

