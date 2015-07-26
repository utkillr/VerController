#ifndef FILECHECKING
#define FILECHECKING

#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"
#include <vector>
#include "outputs.h"
#include "PermChecking.h"

using namespace std;

//Check if strings are the same
bool stringChange(diffString olds, diffString news);
//Diff between two vectors of diffStrings (files). Returns diff result
vector<diffString> diff(vector<diffString> oldf, vector<diffString> newf);
//File checking function for main()
bool checkFileChanges(string fileName, string owner);

#endif
