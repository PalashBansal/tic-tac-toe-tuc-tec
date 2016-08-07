/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file GameWindow.cpp
* @author BPalash
*/

#include "GameWindow.hpp"


GameWindow::GameWindow(void)
:mSDLWindow(NULL),
mScreenWidth(1024/2),
mScreenHeight(768/2)
{
}

GameWindow::~GameWindow(void)
{
}

bool GameWindow::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);	// Initialize SDL
	mSDLWindow = SDL_CreateWindow("tic tac toe tuc tec", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, SDL_WINDOW_OPENGL);	// Open Window
	return mSDLWindow;
}