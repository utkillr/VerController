#include "Modernizing.h"

void modernizeFile(string fileName, vector<diffNode*> path) {
	if (path.size() == 0) return;
	string fileDirectory = getFilePath(fileName);
	ifstream myFile(fileDirectory + '\\' + fileName);
	vector<diffString> fileStrings;
	while (!myFile.eof()) {
		diffString buf;
		buf.text = new char[MAX];
		myFile.getline(buf.text, MAX);
		buf.length = strlen(buf.text);
		fileStrings.push_back(buf);
	}
	for (int i = 0; i < path.size(); i++) {
		fileStrings = getDiffChanges(fileStrings, path[i]);
	}
	myFile.close();
	deleteFile(fileName);
	ofstream newFile(fileDirectory + '\\' + fileName);
	for (int i = 0; i < fileStrings.size(); i++) {
		newFile << fileStrings[i].text;
		if (i < fileStrings.size() - 1) newFile << endl;
	}
	newFile.close();
}

vector<diffString> getDiffChanges(vector<diffString> fileStrings, diffNode* difference) {
	vector <diffString> diff(difference->diffLine);
	for (int i = 0; i < diff.size(); i++) {
		if (diff[i].changes == ADDED) {
			fileStrings.erase(fileStrings.begin() + diff[i].newNumber - 1);
			for (int j = i; j < diff.size(); j++)
				diff[j].newNumber--;
		}
		else {
			fileStrings.insert(fileStrings.begin() + diff[i].newNumber, diff[i]);
			for (int j = i; j < diff.size(); j++)
				diff[j].newNumber++;
		}
	}
	return fileStrings;
}

bool changeFileVersion(string fileName, string nickname) {
	if (!isSaved(fileName)) throw accessError(NOT_SAVED);
	if (!isAccessable(fileName, nickname)) throw accessError(NOT_USER);

	diffTree tree(fileName);

	diffNode* start = tree.getTreePathByID(tree.currentVersion);
	diffNode* finish = tree.getTreePath();

	modernizeFile(fileName, tree.getVersionsPath(start, finish));
}
