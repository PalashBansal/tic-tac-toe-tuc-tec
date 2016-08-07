/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file main.cpp
* @author BPalash
*/

#include<iostream>
#include<string>
#include<conio.h>

#include<SDL/SDL.h>
#include<GL/glew.h>

#include "graphics/GameWindow.hpp"

using namespace std;

enum GameState;

void console_msg(string);
int abort_main_app();
void GameLoop();
GameState ProcessInput();

int main(int argc, char** argv)
{
	GameWindow gw;
	bool _iswindowCreated = gw.CreateGameWindow();
	if(!_iswindowCreated)
	{
		console_msg("error: Main Game Window not able to create!");
		int abort_result=-1;
		//abort_result = abort_main_app();	// only used in Debug mode
		return abort_result;
	}
	else
	{
		console_msg("Main Game Window created!");
		//
		GameLoop();
		//
	}
	return 0;
}

enum GameState
{
	PLAY,
	EXIT
};

void GameLoop()
{
	GameState gameState=PLAY;
	while(gameState!=EXIT)
	{
		gameState = ProcessInput();
	}
}

GameState ProcessInput()
{
	GameState temp_gameState=PLAY;
	SDL_Event sdlEvent;	// takes input from window
	while(SDL_PollEvent(&sdlEvent))	// return from SDL_PollEvent is: 1 is true and 0 is false
	{
		switch(sdlEvent.type)
		{
		case SDL_QUIT:
			temp_gameState = EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << sdlEvent.motion.x << ", " << sdlEvent.motion.y << endl;
			break;
		}
	}
	return temp_gameState;
}

void console_msg(string msg)
{
	cout << msg << endl;
}

int abort_main_app()
{
	cout << "Press any key to quit app..." << endl;
	(void)getch();
	return -1;
}