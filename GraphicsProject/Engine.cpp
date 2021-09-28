#include "Engine.h"
#include "GLFW/glfw3.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

int Engine::run()
{
	int exitCode = 0;

	exitCode = start();
	if (exitCode) {
		return exitCode;
	}



	return 0;
}

int Engine::start()
{
	return 0;
}

int Engine::update()
{
	return 0;
}

int Engine::end()
{
	return 0;
}

bool Engine::getGameOver()
{

}
