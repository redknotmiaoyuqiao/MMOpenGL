#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>
#include <stdlib.h>

#include "MMGL/MMGL.hpp"

int main()
{
	printf("Hello MMOpenGL\n");

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//TODO Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int windowWidth = 1280;
	int windowHeight = 720;
	GLFWwindow * window = glfwCreateWindow(windowWidth, windowHeight, "MMOpenGL", NULL, NULL);

	// OpenGL 运行模式--单线程
	// 多个线程同时调用不被允许
	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	char* shaderStr = (char *)"int main(){}";

	// MMGLShader * shader = new MMGLShader(shaderStr, MMGLShaderType::MMGL_SHADER_VERTEX);
	MMGLProgram* program = new MMGLProgram(shaderStr, shaderStr);

	while (!glfwWindowShouldClose(window)) {
		//TODO 绘制操作

		// TODO 
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// delete shader;
	delete program;

	glfwTerminate();

	return 0;
}
