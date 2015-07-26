#ifndef OUTPUTS
#define OUTPUTS

#include <iostream>
#include <fstream>
#include "vector"
#include "structures.h"
#include "Adding.h"

using namespace std;

//Print diff result
void showChangesVector(vector<diffString> vec);
//Print diff in file
void printDiffFile(string fileName, vector<diffString> difference);

//lol cats
void drawCats();

#endif;
