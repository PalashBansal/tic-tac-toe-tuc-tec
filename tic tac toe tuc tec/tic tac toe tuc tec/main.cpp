/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file main.cpp
* @author BPalash
*/

#include<iostream>
#include<string>

#include "GameWindow.hpp"

using namespace std;

void error_msg(string errorMsg);
int abort_main_app();

int main(int argc, char** argv)
{
	GameWindow gm;
	bool _iswindowCreated = gm.initSystems();
	if(!_iswindowCreated)
	{
		error_msg("Main Game Window not able to create!");
		return abort_main_app();
	}
	else
	{
		char cHoldScreen;
		cin >> cHoldScreen;
	}
	return 0;
}

void error_msg(string errorMsg)
{
	cout << errorMsg << endl;
}

int abort_main_app()
{
	int dumpIntInput;
	cout << "Press any key to quit app..." << endl;
	cin >> dumpIntInput;
	return -1;
}