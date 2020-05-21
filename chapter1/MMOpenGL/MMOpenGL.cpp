#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	printf("Hello MMOpenGL\n");
	return 0;
}
