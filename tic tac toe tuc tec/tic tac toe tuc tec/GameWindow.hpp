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

class GameWindow
{
public:
	GameWindow(void);
	~GameWindow(void);

	bool initSystems();

private:
	SDL_Window* mSDLWindow;
	int mScreenWidth;
	int mScreenHeight;
};