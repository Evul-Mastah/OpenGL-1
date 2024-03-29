#pragma once

#include "gl/glew.h"
#include "gl/freeglut.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <stdio.h>
#include "tga.h"
#include "shaderprogram.h"

#include "vector"
#include <ios>
#include <sstream>
#include "Scene.h"



using namespace std;


class DrawableObject
{
public:
	DrawableObject(ShaderProgram *shaderProgram);
	DrawableObject(ShaderProgram *shaderProgram, const char * filepath);
	DrawableObject(ShaderProgram *shaderProgram, const char * filepath, const char *texturepath);
	~DrawableObject();

	

	// Zmiana koloru modelu
	void changeColor(float r, float g, float b);

	//Procedura rysuj�ca model. Ustawia odpowiednie parametry dla vertex shadera i rysuje.
	void drawObject();

	// Natychmiastowa zmiana pozycje
	void instantMove(float xPosition, float yPosition, float zPosition);
	
	void move(float xPosition, float yPosition, float zPosition, int timeInMilis);

	void instantRotate(float xAngle, float yAngle, float zAngle);

	void rotate(float xAngle, float yAngle, float zAngle, int timeInMilis);

	void instantRotateAroundPoint(float xAngle, float yAngle, float zAngle, float xRadiusVectorCoord, float yRadiusVectorCoord, float zRadiusVectorCoord);

	void rotateAroundPoint(float xAngle, float yAngle, float zAngle, float xRadiusVectorCoord, float yRadiusVectorCoord, float zRadiusVectorCoord, int timeInMilis);

	void instantScale(float xScale, float yScale, float zScale);

	void scale(float xScale, float yScale, float zScale, int timeInMilis);

	void instantScaleNatural(float scalingValue);

	void scaleNatural(float value, int timeInMilis);

	void setAlternativeDrawing(bool alternativeDrawing);

	float getXCoordinate();

	float getYCoordinate();

	float getZCoordinate();

	float getXRotationAngle();

	float getYRotationAngle();

	float getZRotationAngle();

	float getZRotationAroundAngle();


protected:
	Scene &scene  = Scene::getInstance();

	float xPosition = 0, yPosition = 0, zPosition = 0, xAngle = 0, yAngle = 0, zAngle = 0, xAngleAround = 0, yAngleAround = 0, zAngleAround = 0, xRotCoord = 0, yRotCoord = 0, zRotCoord = 0, xScale = 1, yScale = 1, zScale = 1;
	
	bool alternateDrawing = false;

	ShaderProgram *shaderProgram;

	//Uchwyty na VAO i bufory wierzcho�k�w
	GLuint vao;
	GLuint bufVertices; //Uchwyt na bufor VBO przechowuj�cy tablic� wsp�rz�dnych wierzcho�k�w
	GLuint bufColors;  //Uchwyt na bufor VBO przechowuj�cy tablic� kolor�w
	GLuint bufNormals; //Uchwyt na bufor VBO przechowuj�cy tablic� wektor�w normalnych
	GLuint bufTextures; //Uchwyt na bufor VBO przechowujacy tablic� warto�ci tekstur
	GLuint bufElements; //Uchwyt na bufor VBO elementow - trojkatow o ile takowy bufor mozna utworzyc

	float *vertices;
	float *colors;
	float *normals;
	float *textures;
	GLushort *elements;
	int vertexCount;

	vector<float> suzanne_vertices;
	vector<float> suzanne_normals;
	vector<float> suzanne_colors;
	vector<float> suzanne_textures;
	vector<GLushort> suzanne_elements;

	GLuint tex0;
	bool isTexurable = false;

	
	//Ladowanie modelu w formacie .obj bez tekstur
	void loadObject(const char* filename, vector<float> &vertices, vector<float> &normals, vector<float> &textures, vector<float> &colors);

	//Ladowanie modelu w formacie .obj wraz z teksturami
	void loadObjectWithTextures(const char* filename, vector<float> &vertices, vector<float> &normals, vector<float> &textures, vector<float> &colors);

	//Ladowanie tekstur dla modelu
	GLuint loadTexture(const char *filepath);

	//Tworzy bufor na wierzcho�ki, kolory i normalne
	GLuint makeBuffer(void *data, int vertexCount, int vertexSize);

	//Procedura tworz�ca bufory VBO zawieraj�ce dane z tablic opisuj�cych rysowany obiekt.
	void setupVBO();

	//Przypisanie VBO do atrybut�w
	void assignVBOtoAttribute(char* attributeName, GLuint bufVBO, int variableSize);

	//Procedura tworz�ca VAO - "obiekt" OpenGL wi���cy numery slot�w atrybut�w z buforami VBO
	void setupVAO();

	//Uwolnij zasoby przypisane do VBO
	void freeVBO();

	//Uwolnij zasoby przypisane do VAO
	void freeVAO();
};

