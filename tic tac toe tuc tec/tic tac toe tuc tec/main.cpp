/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file main.cpp
* @author BPalash
*/

#include<iostream>
#include<conio.h>
#include<string>

#include<SDL/SDL.h>
#include<GL/glew.h>

#include "graphics/GameWindow.hpp"
#include "Utility.hpp"

using namespace std;

enum GameState;

int abort_main_appDebug();
int abort_main_appRelease();
void GameLoop();
GameState ProcessInput();
void drawTest();

GameWindow gw;
Utility utility;

int main(int argc, char** argv)
{
	bool _iswindowCreated = gw.CreateGameWindow();
	if(!_iswindowCreated)
	{
		int abort_result;
		//abort_result = abort_main_appDebug();
		abort_result = abort_main_appRelease();
		return abort_result;
	}
	else
	{
		drawTest();
		GameLoop();
	}
	return 0;
}

void drawTest()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_COLOR_ARRAY);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glEnd();
	
	SDL_GL_SwapWindow(gw.mSDLWindow);
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


int abort_main_appDebug()
{
	utility.console_msg("Press any key to quit app(console)...");
	(void)_getch();
	SDL_Quit();
	return -1;
}

int abort_main_appRelease()
{
	SDL_Quit();
	return -1;
}