#pragma once

#include <GL/glew.h>

using namespace std;

class Sprite
{
private:
	float x, y;
	double width, height;
	float vertexData;

	GLuint vboID;

public:
	Sprite();
	~Sprite();

	void init(float x, float y, double width, double height);
	void draw();
};

