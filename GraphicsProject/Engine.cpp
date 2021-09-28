#include "Engine.h"
#include <gl_core_4_4.h>
#include "GLFW/glfw3.h"
#include <iostream>

Engine::Engine() : Engine(1280, 720, "Window")
{
}

Engine::Engine(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

Engine::~Engine()
{
}

int Engine::run()
{
	int exitCode = 0;

	//Start
	exitCode = start();
	if (exitCode) {
		return exitCode;
	}

	//Update
	while (!getGameOver()) {
		exitCode = update();
	}

	//End
	exitCode = end();
	if (exitCode) {
		return exitCode;
	}

	return 0;
}

int Engine::start()
{
	//Initialize GLFW
	if (!glfwInit() == GLFW_FALSE) {
		return -1;
	}

	//Create a window
	GLFWwindow* window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(window);

	//Load OpenGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}
	int majorVersion = ogl_GetMajorVersion();
	int minorVersion = ogl_GetMinorVersion();
	printf("OpenGL version: %i.%i\n", majorVersion, minorVersion);
	return 0;
}

int Engine::update()
{
	if (!m_window) return -4;

	glfwPollEvents();
	return 0;
}

int Engine::draw()
{
	if (!m_window) return -5;
	glfwSwapBuffers(m_window);
	return 0;
}

int Engine::end()
{
	if (!m_window) return -6;

	glfwDestroyWindow(m_window);
	glfwTerminate();
	return 0;
}

bool Engine::getGameOver()
{
	if (!m_window) return true;

	bool gameIsOver = glfwWindowShouldClose(m_window);
	gameIsOver = gameIsOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
}
