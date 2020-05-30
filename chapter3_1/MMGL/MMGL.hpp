#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

private:
	GLuint program = 0;
};