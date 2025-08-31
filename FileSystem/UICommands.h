#pragma once

#include "File.h"
#include "Folder.h"

#include <iostream>
#include <string>

#define EXIT_CODE 0

using namespace std;

class UICommands {
public:
	static FileSystemEntity* rootDirectory; // Pointer to the current directory
	static FileSystemEntity* currentDirectory; // Pointer to the current directory
public:
	static void displayMenu();
	static void handleUserInput(int choice);
	static void run();
	static string getPath();
};