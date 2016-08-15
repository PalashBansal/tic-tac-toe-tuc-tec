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

void GameLoop();
GameState ProcessInput();
void drawTest();

GameWindow gw;

int main(int argc, char** argv)
{
	gw.CreateGameWindow();
	drawTest();
	GameLoop();
	return 0;
}

void drawTest()//test program to be removed
{
	unsigned int _vboIDxx=0;
	float x=-1.0f, y=-1.0f, width=1.0f, height=1.0f;
	if(_vboIDxx==0)
	{
	glGenBuffers(1, &_vboIDxx);// (unsigned int)vertex buffer object ID
	}
	float vertexDataxx[6*2];
	vertexDataxx[0]=x+width;
	vertexDataxx[1]=y+height;
	vertexDataxx[2]=x;
	vertexDataxx[3]=y+height;
	vertexDataxx[4]=x;
	vertexDataxx[5]=y;
	vertexDataxx[6]=x;
	vertexDataxx[7]=y;
	vertexDataxx[8]=x+width;
	vertexDataxx[9]=y;
	vertexDataxx[10]=x+width;
	vertexDataxx[11]=y+height;
	glBindBuffer(GL_ARRAY_BUFFER, _vboIDxx);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexDataxx), vertexDataxx, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &_vboIDxx);
	glBindBuffer(GL_ARRAY_BUFFER, _vboIDxx);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 6);//GL_QUADS not supported by many and if supported, its convertedto triangles so is slow.
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

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

void GameLoop()// to be modified
{
	GameState gameState=PLAY;
	while(gameState!=EXIT)
	{
		gameState = ProcessInput();
	}
}

GameState ProcessInput()// to be used with modifications
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