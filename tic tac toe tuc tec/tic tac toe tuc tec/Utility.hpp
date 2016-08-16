/*******************************************************************************
* Project tic tac toe tuc tec
*******************************************************************************/
/**
* These functions mentioned here are for general purpose and can be used anywhere in the program.
* @file Utility.hpp
* @author BPalash
*/

#pragma once

#include<string>

#define S(x) (#x)
#define S_(x) S(x)
#define S__LINE__ S_(__LINE__)
#define WHEREERROR "FILE: "+(string)(__FILE__)+"\nFUNCTION: "+(string)(__FUNCTION__)+"\nLINE: "+S__LINE__

using namespace std;

//	 Just to print message on console. Status of application running.
void _consoleStatusMsg(string);

//	To print error messages iff there is any occuring in app. Writes to screen file/function name and line number where error occurred.
//	By default quits app.
void _consoleErrorMsgAndQuit(string, string, bool=true);

// Asks user before aborting. Calls abort of release mode.
void _abort_main_appDebug();

// Doesn't asks user, just quits app after releasing resources.
void _abort_main_appRelease();