#include "structures.h"
#include <algorithm>

diffTree::diffTree(string fileName) {
	string fileDirectory = getFilePath(fileName);
	ifstream diffFile(fileDirectory + '\\' + fileName + "-diff.dat");
	diffFile >> currentVersion;
	char c;
	diffFile.get(c);	//Pass through \n symbol
	top = recoursiveRead(diffFile);
	node = top;
	vector<int> versions;
	nextVersion = getVersion(versions);
}

diffNode* diffTree::readDiff(ifstream &diffFile, int &amount) {
	char c;
	diffFile.get(c);									//read 1st symbol
	int ver = 0;
	if (c == 'V') {										//if V, read version
		diffFile.get(c);
		while (c != '\n') {
			ver = ver * 10 + c - 48;
			diffFile.get(c);
		}
	}
	else {												//else error
		cout << "ERROR OCCURED" << endl;
		return NULL;
	}
	diffNode* mynode = new diffNode;
	mynode->version = ver;								//Version
	diffFile.get(c);									//skip < or >
	while (c != 'V' && !(c >= '0' && c <= '9')) {		//if nor begin neither end
		diffFile.get(c);								//skip space
		diffString buf;
		buf.text = new char[MAX];
		diffFile.getline(buf.text, MAX);
		buf.length = strlen(buf.text);
		findPosAndStatus(buf.text, buf.originalNumber, buf.newNumber, buf.changes);
		int i;
		for (i = buf.length; buf.text[i] != ' '; i--);
		buf.text[i] = '\0';
		mynode->diffLine.push_back(buf);
		diffFile >> c;									//skip < or >
	}
	int chld = c - 48;									//amount of children
	diffFile.get(c);									//go further
	while (c!='\n' && !diffFile.eof()) {				//and get whole number
		chld = chld * 10 + c - 48;
		diffFile >> c;
	}
	amount = chld;
	return mynode;
}

diffNode* diffTree::recoursiveRead(ifstream &diffFile) {
	int chld;
	diffNode* Node = readDiff(diffFile, chld);
	if (!Node) return NULL;
	if (Node->version == 0) Node->parent = NULL;
	diffNode* save = node;
	for (int i = 0; i < chld; i++) {
		Node->children.push_back(recoursiveRead(diffFile));
		Node->children[i]->parent = Node;
	}
	return Node;
}
void diffTree::findPosAndStatus(string s, int &originpos, int &newpos, changeStatus &status) {
	int i = s.length();
	while (s[i] != ' ') {
		i--;
	}
	int or = 0, nw = 0;
	i++;
	while (s[i] != 'a' && s[i] != 'd') {
		or = or * 10 + s[i] - 48;
		i++;
	}
	if (s[i] == 'a') status = ADDED;
	else status = DELETED;
	i++;
	while (i < s.length()) {
		nw = nw * 10 + s[i] - 48;
		i++;
	}
	originpos = or;
	newpos = nw;
}

void diffTree::printDiff(fstream &diffFile, diffNode *node) {
	diffFile << "V" << node->version << endl;
	for (int i = 0; i < node->diffLine.size(); i++) {
		if (node->diffLine[i].changes == ADDED)
			diffFile << "> " << node->diffLine[i].text << ' '
			<< node->diffLine[i].originalNumber << "a" 
			<< node->diffLine[i].newNumber << endl;
		else 
			diffFile << "< " << node->diffLine[i].text << ' '
			<< node->diffLine[i].originalNumber << "d"
			<< node->diffLine[i].newNumber << endl;
	}
	diffFile << node->children.size() << endl;
}

void diffTree::recoursivePrint(fstream &diffFile, diffNode *node) {
	printDiff(diffFile, node);
	for (int i = 0; i < node->children.size(); i++) {
		recoursivePrint(diffFile, node->children[i]);
	}
}

void diffTree::printDiffTreeFile(string fileName) {
	string fileDirectory = getFilePath(fileName);
	fstream diffFile(fileDirectory + '\\' + fileName + "-diff.dat");
	diffFile << currentVersion << endl;
	recoursivePrint(diffFile, node);
}

void diffTree::addNode(diffNode* parent, diffNode* child) {
	child->version = nextVersion;
	currentVersion = nextVersion;
	if (parent == NULL) {
		top = child;
		child->parent = NULL;
	}
	else {
		parent->children.push_back(child);
		child->parent = parent;
	}
	node = top;
}

diffNode* diffTree::getTreePath() {
	system("cls");
	int path;
	vector<bool> symbols;
	node = top;
	printTreeIDs(symbols);
	cout << endl;
	cout << "Enter number of version to modernize (0 is original file): ";
	cin >> path;
	if (path < 0 || path >= nextVersion) path = 0;
	system("cls");
	node = top;
	return getTreePathByID(path);
}

diffNode* diffTree::getTreePathByID(int path) {
	diffNode* save = node;
	diffNode* res = NULL;
	if (node->version == path) return node;
	for (int i = 0; i < node->children.size(); i++) {
		node = node->children[i];
		res = getTreePathByID(path);
		if (res) return res;
		node = save;
	}
	return NULL;
}

/*corner is false, mult is true*/ /*!!!REWRITE FOR 0 VERSION TO BE ACCESSABLE!!!*/
bool diffTree::printTreeIDs(vector<bool> symbols) {
	if (!node) return false;
	if (symbols.empty()) {
		if (node->version < 10) cout << "00" << node->version << endl;
		else if (node->version < 100) cout << '0' << node->version << endl;
		else cout << node->version << endl;
	}
	else {
		char c;
		for (int i = 0; i < symbols.size(); i++) {
			if (symbols[i] == true) {
				if (symbols.size() == i+1) {
					PTput(MULT);
					if (node->version < 10) cout << "00" << node->version << endl;
					else if (node->version < 100) cout << '0' << node->version << endl;
					else cout << node->version << endl;
				}
				else {
					PTput(LIMB);
				}
			}
			else {
				if (symbols.size() == i+1) {
					PTput(CORN);
					if (node->version < 10) cout << "00" << node->version << endl;
					else if (node->version < 100) cout << '0' << node->version << endl;
					else cout << node->version << endl;
				}
				else {
					PTput(SPACE);
				}
			}
		}
	}
	diffNode *save = node;
	for (int i = 0; i < node->children.size(); i++) {
		if (i == node->children.size()-1)
			symbols.push_back(false);
		else
			symbols.push_back(true);
		node = node->children[i];
		printTreeIDs(symbols);
		node = save;
		symbols.pop_back();
	}
}

void PTput(pstr s) {
	char c;
	switch (s) {
	case LIMB:
		c = LIMB;
		cout << c;
		c = ' ';
		for (int i = 0; i < 2; i++) cout << c;
		break;
	case MULT:
		c = MULT;
		cout << c;
		c = HORIZ;
		for (int i = 0; i < 2; i++) cout << c;
		break;
	case CORN:
		c = CORN;
		cout << c;
		c = HORIZ;
		for (int i = 0; i < 2; i++) cout << c;
		break;
	case SPACE:
		cout << "   ";
		break;
	default:
		break;
	}
}

int diffTree::getVersion(vector<int> &versions) {
	diffNode* save = node;
	versions.push_back(node->version);
	for (int i = 0; i < node->children.size(); i++) {
		node = node->children[i];
		getVersion(versions);
		node = save;
	}
	sort(versions.begin(), versions.end());
	for (int i = 0;; i++) {
		if (versions.size() == i) return i;
		if (versions[i] != i) return i;
	}
	return 0;
}

void diffTree::recoursiveDiffOutput() {
	cout << 'V' << node->version << endl;
	for (int i = 0; i < node->diffLine.size(); i++) {
		if (node->diffLine[i].changes == ADDED)
			cout << "> " << node->diffLine[i].text << ' ' << node->diffLine[i].originalNumber << 'a' << node->diffLine[i].newNumber << endl;
		else
			cout << "< " << node->diffLine[i].text << ' ' << node->diffLine[i].originalNumber << 'd' << node->diffLine[i].newNumber << endl;
	}
	cout << endl;
	diffNode* save = node;
	for (int i = 0; i < node->children.size(); i++) {
		node = node->children[i];
		recoursiveDiffOutput();
		node = save;
	}
}

vector<diffNode*> diffTree::getVersionsPath(diffNode* start, diffNode* finish) {
	vector<diffNode*> path;
	if (!start || !finish) return path;
	vector<int> versions;
	node = top;
	getVersionsVector(versions);
	sort(versions.begin(), versions.end());
	vector<bool> visited(versions[versions.size()-1]+1, false);	//+1 is for zero version that is not used
	recoursivePathGet(path, visited, start, finish);
	node = top;
	return path;
}

void diffTree::getVersionsVector(vector<int> &versions) {
	diffNode* save = node;
	versions.push_back(node->version);
	for (int i = 0; i < node->children.size(); i++) {
		node = node->children[i];
		getVersionsVector(versions);
		node = save;
	}
}

bool diffTree::recoursivePathGet(vector<diffNode*> &path, vector<bool> &visited, diffNode* start, diffNode* finish) {
	//need to improve for choosen version '0' (==Go to the top element and change it). That is exeption!
	path.push_back(start);
	visited[start->version] = true;
	if (start == finish) {
		if (!path.empty()) path.pop_back();
		return true;
	}
	if (start->parent && !visited[start->parent->version]) {
		if (recoursivePathGet(path, visited, start->parent, finish)) return true;
	}
	for (int i = 0; i < start->children.size(); i++) {
		if (start == finish) return true;
		if (!visited[start->children[i]->version]) {
			if (recoursivePathGet(path, visited, start->children[i], finish)) return true;
		}
	}
	path.pop_back();
}

const string accessError::what() {
	switch (errCode) {
	case SAVED:
		return "Error! File has already been saved\n";
	case NOT_OWNER:
		return "Error! You are not owner of file\n";
	case NOT_USER:
		return "Error! You don't have access to file\n";
	case NOT_SAVED:
		return "Error! File hasn't been saved yet\n";
	case NO_FILE:
		return "Error! Can't find file with such a path\n";
	case ERR_CR_DIR:
		return "Error! Unable to create a directory\n";
	case USER:
		return "Error! This user already has access to file\n";
	default:
		return "Unhandled error\n";
	}
}
