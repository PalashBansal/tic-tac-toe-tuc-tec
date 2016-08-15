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

	void CreateGameWindow(); //	Function to be supplied to client(here main)
	SDL_Window *mSDLWindow;	//	Instance of SDL window

private:
	void initSystems();	//	Initialize main game window

	int mScreenWidth;	//	Main window width
	int mScreenHeight;	//	Main window height
	SDL_Event mEvent; /// to be used
};