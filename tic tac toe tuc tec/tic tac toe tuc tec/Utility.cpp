/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file Utility.hpp
* @author BPalash
*/

#include<string>
#include<iostream>
#include<conio.h>

#include<SDL\SDL.h>

#include "Utility.hpp"

using namespace std;

void _consoleStatusMsg(string msg)
{
	cout << "_status: " << msg << endl;
}

void _consoleErrorMsgAndQuit(string msg, string funcname, bool isQuit)
{
	cout << "_error: " << msg << endl;
	const char* funcname_cstr = funcname.c_str();
	perror(funcname_cstr);
	if(isQuit)
		_abort_main_appDebug();//change to abort_main_appRelease() in Release mode
}

void _abort_main_appDebug()
{
	cout << "Press any key to quit app(console)...";
	(void)_getch();
	_abort_main_appRelease();
}

void _abort_main_appRelease()
{
	SDL_Quit();
	exit(EXIT_FAILURE);
}