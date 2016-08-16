/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file GameWindow.hpp
* @author BPalash
*/

#pragma once

#include<string>

#include<SDL/SDL.h>
#include<GL/glew.h>

using namespace std;

//	Game window class creates instance of main game window using SDL
class GameWindow
{
public:
	GameWindow(void);
	~GameWindow(void);

	//	Function to be supplied to client(here main)
	void CreateGameWindow();
	//	Instance of SDL window
	SDL_Window *mSDLWindow;

private:
	//	Initialize main game window
	void initSystems();

	//	Main window width
	int mScreenWidth;
	//	Main window height
	int mScreenHeight;
	SDL_Event mEvent; /// to be used
};