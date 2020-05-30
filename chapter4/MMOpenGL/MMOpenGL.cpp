#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>
#include <stdlib.h>

#include "MMGL/MMGL.hpp"



#define STRINGIZE(x)  #x
#define SHADER(shader) "" STRINGIZE(shader)



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

	char* vertexShader = SHADER(
		#version 330\n

		layout(location = 0) in vec3 pos;

		out vec3 outPos;

		void main()
		{
			outPos = pos;
			gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
		}
	);

	char* fragmentShader = SHADER(
		#version 330\n

		out vec4 rgbaColor;
		in vec3 outPos;

		void main()
		{
			rgbaColor = vec4(outPos, 1.0);
		}
	);

	float vertex[] =
	{
		0.0f,	1.0f,	0.0f,
		-1.0f, -1.0f,	0.0f,
		1.0f,  -1.0f,   0.0f
	};


	MMGLVAO* vao = new MMGLVAO();
	vao->AddVertex3D(vertex, 3, 0);
	
	MMGLProgram* program = new MMGLProgram(vertexShader, fragmentShader);

	while (!glfwWindowShouldClose(window)) {
		//TODO 绘制操作
		glClear(GL_COLOR_BUFFER_BIT);

		program->UseProgram();
		vao->BindVAO();

		glDrawArrays(GL_TRIANGLES, 0, 3);

		// TODO 
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	delete vao;
	delete program;

	glfwTerminate();

	return 0;
}
