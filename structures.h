#ifndef STRUCTURES
#define STRUCTURES

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <direct.h>
#include "PermChecking.h"

#define MAX 256

using namespace std;

//enum constants for changes checking
enum changeStatus { NOTCHECKED = 100, NOTCHANGED = 0, ADDED = 1, DELETED = -1 };

//diffString structure
struct diffString {
	//Actually, the text
	char* text;
	//Length
	int length;
	//Check if changed
	changeStatus changes;
	//Number of diffString in old file
	int originalNumber;
	//Number of diffString in new file
	int newNumber;
public:
	//Default constructor
	diffString() : length(0), changes(NOTCHECKED), originalNumber(0), newNumber(0) {
		text = NULL;
	};
	//Copy constructor
	diffString(const diffString &a) {
		length = a.length;
		changes = a.changes;
		text = new char[length + 1];
		strcpy(text, a.text);
		originalNumber = a.originalNumber;
		newNumber = a.newNumber;
	}
};

//diff structure
struct diffNode {
	vector<diffString> diffLine;
	vector<diffNode*> children;
	diffNode* parent;
	int version;
};

//diff tree class
class diffTree {
	diffNode* node;
	diffNode* top;
	//Helping funcs
	void printDiff(fstream &diffFile, diffNode *node);
	void recoursivePrint(fstream &diffFile, diffNode *node);
	void findPosAndStatus(string s, int &originpos, int &newpos, changeStatus &status);
	diffNode* recoursiveRead(ifstream &diffFile);
	diffNode* readDiff(ifstream &diffFile, int &amount);
	void getVersionsVector(vector<int> &versions);
	bool recoursivePathGet(vector<diffNode*> &path, vector<bool> &visited, diffNode* start, diffNode* finish);
public:
	int nextVersion;
	int currentVersion;
	//Default counstructor
	diffTree() : node(NULL), top(NULL), nextVersion(0), currentVersion(0) {};
	//Constructor by getting from file
	diffTree(string fileName);
	//Print diff tree in file
	void printDiffTreeFile(string fileName);
	//Add new node
	void addNode(diffNode* parent, diffNode* child);
	//get Path in tree
	diffNode* getTreePath();
	//get next version
	int getVersion(vector<int> &versions);
	//Printing tree of IDs
	bool printTreeIDs(vector<bool> symbols);
	//Recoursive print in console
	void recoursiveDiffOutput();
	//Get diffNode* by ID
	diffNode* getTreePathByID(int path);
	//Gets vector of nodes from start to finish
	vector<diffNode*> getVersionsPath(diffNode* start, diffNode* finish);
};

//enum for pseudotree
enum pstr { LIMB = 186, MULT = 204, CORN = 200, HORIZ = 205, SPACE = 32 };

void PTput(pstr s);

//enum constants for errors
enum err { SAVED = 1, NOT_OWNER = 2, NOT_USER = 3, NOT_SAVED = 4, NO_FILE = 5, ERR_CR_DIR = 6, USER = 7 };

class accessError : public exception {
	err errCode;
public:
	const string what();
	accessError(err _code) : errCode(_code) {};
};

#endif
