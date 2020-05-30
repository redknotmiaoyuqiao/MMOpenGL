#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

enum MMGLShaderType
{
	MMGL_SHADER_VERTEX = 1,
	MMGL_SHADER_FRAGMENT = 2
};

class MMGLShader
{
public:
	MMGLShader(char * shaderStr, MMGLShaderType type);
	~MMGLShader();

public:
	GLuint shader = 0;
};

class MMGLProgram
{
public:
	MMGLProgram(char * vertexShaderStr, char * fragmentShaderSrc);
	~MMGLProgram();

	int UseProgram();

private:
	GLuint program = 0;
};

class MMGLVAO
{
public:
	MMGLVAO();
	~MMGLVAO();

	int AddVertex3D(float * data, int vertexCount, int layout);

	int BindVAO();
private:
	GLuint vao = 0;

	std::vector<GLuint> vboList;
};