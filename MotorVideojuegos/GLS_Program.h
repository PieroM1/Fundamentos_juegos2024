#pragma once

#include <GL/glew.h>
#include <string>

using namespace std;
class GLS_Program
{
private:
	GLuint programID;
	GLuint fragmentShaderID;
	GLuint vertexShaderID;
	int numAtribute;
	void compileShader(const string& shaderPath, GLint id);
public:
	GLS_Program();
	~GLS_Program();
	void compileShaders(const string& vertexShaderFilePath,
		const string& fragmentShaderFilePath);
	void linkShader();
	void addAtribute(const string atributename);
	void use();
	void unuse();
	GLuint getUniformLocation(const string& name);

};

