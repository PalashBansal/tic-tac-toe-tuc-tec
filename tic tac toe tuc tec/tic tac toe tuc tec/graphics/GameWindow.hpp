/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file GameWindow.hpp
* @author BPalash
*/

#pragma once

#include<SDL/SDL.h>
#include<GL/glew.h>

//	Game window class creates instance of main game window using SDL
class GameWindow
{
public:
	GameWindow(void);
	~GameWindow(void);

	bool CreateGameWindow(); // function to be supplied to client(here main)

private:
	bool initSystems();	// Initialize main game window

	SDL_Window *mSDLWindow;	// Instance of SDL window
	int mScreenWidth;	// Main window width
	int mScreenHeight;	// Main window height
	SDL_Event mEvent;
};