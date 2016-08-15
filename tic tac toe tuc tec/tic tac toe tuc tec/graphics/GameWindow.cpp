/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file GameWindow.cpp
* @author BPalash
*/

#include<string>
#include<iostream>

#include "GameWindow.hpp"
#include "..\Utility.hpp"

using namespace std;

GameWindow::GameWindow(void)
:mSDLWindow(NULL),
mScreenWidth(1024/2),
mScreenHeight(768/2)
{
	//Screen width and height to be computed based on system screen resolution.
}

GameWindow::~GameWindow(void)
{
}

bool GameWindow::CreateGameWindow()
{
	return initSystems();
}

bool GameWindow::initSystems()
{
	Utility utility;
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	mSDLWindow = SDL_CreateWindow("tic tac toe tuc tec", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, SDL_WINDOW_OPENGL);	// Open Window
	if(mSDLWindow==nullptr)
	{
		utility.console_msg("error: Main Game Window could not be created!");
		SDL_Quit();
		return false;
	}
	utility.console_msg("status: Main Game Window created!");
	//	Create OpenGL context
	SDL_GLContext glContext =SDL_GL_CreateContext(mSDLWindow);
	if(glContext == nullptr)
	{
		utility.console_msg("error: SDL_GL Context could not be created!");
		return false;
	}
	utility.console_msg("status: SDL_GL Context created!");
	//	Initialize Glew
	GLenum error = glewInit();
	if(error != GLEW_OK)
	{
		utility.console_msg("error: Glew could not be initialized!");
		return false;
	}
	utility.console_msg("status: Glew initialized!");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);// double screen(write and clear) to avoid screen flickering
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);// set background color (r, g, b, alpha)
	return true;
}