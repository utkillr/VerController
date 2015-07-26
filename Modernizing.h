#ifndef MODERNIZING
#define MODERNIZING

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "structures.h"
#include "Deleting.h"
#include "outputs.h"
#include "FileChecking.h"
#include "PermChecking.h"

using namespace std;

//Modernize file to needed version by path
void modernizeFile(string fileName, vector<diffNode*> path);
//Modernize vector of diffLines using diffNode difference
vector<diffString> getDiffChanges(vector<diffString> fileStrings, diffNode* difference);
//Change function for main()
bool changeFileVersion(string fileName, string nickname);

#endif
