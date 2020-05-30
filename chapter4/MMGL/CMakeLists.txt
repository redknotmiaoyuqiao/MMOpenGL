include_directories(../3rdpart/glfw/include/)
include_directories(../3rdpart/glad/include/)

link_directories(../3rdpart/glfw/lib/)

add_library (
	MMGL
	../3rdpart/glad/src/glad.c

	MMGL.hpp
	MMGLShader.cpp
	MMGLProgram.cpp
	MMGLVAO.cpp
	)

