# CMakeList.txt: MMOpenGL 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

include_directories(../)
include_directories(../3rdpart/glfw/include/)
include_directories(../3rdpart/glad/include/)

link_directories(../3rdpart/glfw/lib/)

# 将源代码添加到此项目的可执行文件。
add_executable (
	MMOpenGL 
	"MMOpenGL.cpp" 
	"MMOpenGL.h"
	)

target_link_libraries(MMOpenGL glfw3)
target_link_libraries(MMOpenGL MMGL)

# TODO: 如有需要，请添加测试并安装目标。
