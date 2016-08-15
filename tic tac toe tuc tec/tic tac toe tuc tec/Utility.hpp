/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* @file GameWindow.hpp
* @author BPalash
*/

#include<iostream>
#include<string>
using namespace std;

#pragma once
class Utility
{
public:
	Utility(void);
	~Utility(void);
	inline void console_msg(string msg)const{	cout << msg << endl; };
};

