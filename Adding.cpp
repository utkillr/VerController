#include "Adding.h"

void createPermFile(string fileName, string owner) {
	string fileDirectory = getFilePath(fileName);
	string perm = fileName + "-perm.dat";
	ofstream permissionsFile(fileDirectory + '\\' + perm);
	permissionsFile << owner << endl;
	permissionsFile.close();
}

void createDiffFile(string fileName) {
	string fileDirectory = getFilePath(fileName);
	string diff = fileName + "-diff.dat";
	ofstream diffFile(fileDirectory + '\\' + diff);
	diffFile << "0\nV0\n0";
	diffFile.close();
}

void addFile(string fileName, string address) {
	string fileDirectory = getFilePath(fileName);
	ifstream fileToCopy(address);
	ofstream fileToCreate(fileDirectory + '\\' + fileName);

	char c;
	while (true) {
		c = fileToCopy.get();
		if (!fileToCopy.eof())
			fileToCreate.put(c);
		else break;
	}

	fileToCopy.close();
	fileToCreate.close();
}

bool addNewFile(string fileName, string address, string owner) {
	if (isSaved(fileName)) throw accessError(SAVED);
	if (!isExisting(address)) throw accessError(NO_FILE);

	string fileDirectory = getFilePath(fileName);
	ifstream fileToCopy(address);

	char c;
	if (mkdir(fileDirectory.c_str())) throw accessError(ERR_CR_DIR);						//error creating directory
	ofstream fileToCreate(fileDirectory + '\\' + fileName);
	while (true) {
		c = fileToCopy.get();
		if (!fileToCopy.eof())
			fileToCreate.put(c);
		else break;
	}

	fileToCopy.close();
	fileToCreate.close();

	createPermFile(fileName, owner);
	createDiffFile(fileName);

	return true;
}

bool addExistingFile(string fileName, string address, string owner) {
	string fileDirectory = getFilePath(fileName);

	if (!isSaved(fileName)) throw accessError(NOT_SAVED);
	if (!isExisting(address)) throw accessError(NO_FILE);
	if (!isAccessable(fileName, owner)) throw accessError(NOT_USER);

	diffTree tree(fileName);

	diffNode* start = tree.getTreePathByID(tree.currentVersion);
	diffNode* finish = tree.getTreePath();

	modernizeFile(fileName, tree.getVersionsPath(start, finish));

	vector<diffString> exf;
	vector<diffString> newf;
	ifstream existingFile(fileDirectory + '\\' + fileName);
	ifstream newFile(address);
	while (!existingFile.eof()) {
		diffString buf;
		buf.text = new char[MAX];
		existingFile.getline(buf.text, MAX);
		buf.length = strlen(buf.text);
		exf.push_back(buf);
	}
	while (!newFile.eof()) {
		diffString buf;
		buf.text = new char[MAX];
		newFile.getline(buf.text, MAX);
		buf.length = strlen(buf.text);
		newf.push_back(buf);
	}
	vector<diffString> difference = diff(exf, newf);
	showChangesVector(difference);
	diffNode* child = new diffNode;
	child->diffLine = difference;
	tree.addNode(finish, child);

	ofstream diffFile(fileDirectory + '\\' + fileName + "-diff.dat");
	diffFile.close();

	tree.printDiffTreeFile(fileName);

	deleteFile(fileName);
	addFile(fileName, address);

	return true;
}
