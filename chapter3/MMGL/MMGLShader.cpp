#include "MMGL.hpp"
#include <stdlib.h>
#include <stdio.h>

MMGLShader::MMGLShader(char* shaderStr, MMGLShaderType type)
{
	if (type == MMGLShaderType::MMGL_SHADER_VERTEX) {
		shader = glCreateShader(GL_VERTEX_SHADER);
	}
	else if(type == MMGLShaderType::MMGL_SHADER_FRAGMENT){
		shader = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else {
		shader = glCreateShader(GL_VERTEX_SHADER);
	}
	
	glShaderSource(shader, 1, &shaderStr, NULL);

	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	GLint logLen = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
	if (logLen > 0) {
		char* log = (char*)malloc(logLen);
		glGetShaderInfoLog(shader, logLen, NULL, log);

		printf("Shader Log:\n");
		printf("%s\n", log);

		free(log);
	}
}

MMGLShader::~MMGLShader()
{
	if (shader != 0) {
		glDeleteShader(shader);
		shader = 0;
	}
}