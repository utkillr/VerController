#include "PermChecking.h"

string getFilePath(string fileName) {
	char* path = new char[128];
	path = _getcwd(path, 128);
	string filePath = path;
	filePath = filePath + '\\' + fileName; // +'\\' + fileName;
	return filePath;
}

bool isOwner(string fileName, string nickname) {
	string fileDirectory = getFilePath(fileName);
	ifstream permFile(fileDirectory + '\\' + fileName + "-perm" + ".dat");
	string name;
	permFile >> name;
	if (nickname == name) return true;
	else return false;
}

bool isAccessable(string fileName, string nickname) {
	string fileDirectory = getFilePath(fileName);
	ifstream permFile(fileDirectory + '\\' + fileName + "-perm" + ".dat");
	string name;
	while (!permFile.eof()) {
		permFile >> name;
		if (name == nickname) return true;
		if (permFile.eof()) return false;
	}
}

bool isSaved(string fileName) {
	string fileDirectory = getFilePath(fileName);
	ifstream fileTest(fileDirectory + '\\' + fileName);
	if (fileTest) {
		fileTest.close();
		return true;													
	}
	else return false;
}

bool isExisting(string address) {
	ifstream fileTest(address);
	if (fileTest) {
		fileTest.close();
		return true;
	}
	else return false;
}
