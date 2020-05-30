#include "MMGL.hpp"

#include <stdlib.h>
#include <stdio.h>

MMGLProgram::MMGLProgram(char* vertexShaderStr, char* fragmentShaderSrc)
{
	program = glCreateProgram();

	MMGLShader vertexShader(vertexShaderStr, MMGLShaderType::MMGL_SHADER_VERTEX);
	MMGLShader fragmentShader(fragmentShaderSrc, MMGLShaderType::MMGL_SHADER_FRAGMENT);

	glAttachShader(program, vertexShader.shader);
	glAttachShader(program, fragmentShader.shader);

	glLinkProgram(program);

	GLint logLen = 0;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);
	if (logLen > 0) {
		char* log = (char*)malloc(logLen);
		glGetProgramInfoLog(program, logLen, NULL, log);

		printf("Program Log:\n");
		printf("%s\n\n", log);

		free(log);
	}
}

MMGLProgram::~MMGLProgram()
{
	if (program != NULL) {
		glDeleteProgram(program);
		program = 0;
	}
}

int MMGLProgram::UseProgram()
{
	glUseProgram(program);
	return 0;
}