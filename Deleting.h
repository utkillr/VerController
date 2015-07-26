#ifndef DELETING
#define DELETING

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include "Adding.h"
#include "PermChecking.h"

using namespace std;

//Delete file
bool deleteFile(string fileName);
//Delete file and permissions and diff files
bool deleteFileWithPermissions(string fileName, string nickname);

#endif
