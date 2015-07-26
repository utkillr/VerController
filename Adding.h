#ifndef ADDING
#define ADDING

#define MAX 256

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "structures.h"
#include "Deleting.h"
#include "outputs.h"
#include "FileChecking.h"
#include <direct.h>
#include "Modernizing.h"
#include "PermChecking.h"

using namespace std;

//Create permissions file (add owner)
void createPermFile(string fileName, string owner);
//Create empty diffs file
void createDiffFile(string fileName);
//Create just a new file
void addFile(string fileName, string address);
//Add new file (also create diff and perm files)
bool addNewFile(string fileName, string address, string owner);
//Add existing file (=modify diff file + add new file)
bool addExistingFile(string fileName, string address, string owner);

#endif
