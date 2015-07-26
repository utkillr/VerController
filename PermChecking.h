#ifndef PERMCHECKING
#define PERMCHECKING

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <direct.h>
#include <exception>

using namespace std;

//Get path for file
string getFilePath(string fileName);
//Checks if user is owner
bool isOwner(string fileName, string nickname);
//Checks if user has permissions
bool isAccessable(string fileName, string nickname);
//checks if saved file exists
bool isSaved(string fileName);
//checks if new file exists
bool isExisting(string address);

#endif
