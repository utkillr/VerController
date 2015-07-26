#include "FileChecking.h"

bool stringChange(diffString olds, diffString news) {
	int res = strcmp(olds.text, news.text);
	if (res == 0) return true;
	else return false;
}

vector<diffString> diff(vector<diffString> oldf, vector<diffString> newf) {
	int position = 0;
	bool isSame;
	for (int i = 0; i < oldf.size(); i++) {
		if (position == newf.size()) {
			while (i < oldf.size()) {
				oldf[i].changes = DELETED;
				i++;
			}
		}
		for (int j = position; j < newf.size(); j++) {
			isSame = stringChange(oldf[i], newf[j]);
			if (isSame) {
				oldf[i].changes = NOTCHANGED;
				newf[j].changes = NOTCHANGED;
				position = j + 1;
				break;
			}
			else {
				newf[j].changes = ADDED;
			}
			if (j == newf.size() - 1) {
				oldf[i].changes = DELETED;
			}
		}

	}
	/*îáðàáîòêà*/
	vector<diffString> result;
	int iter1 = 0; int iter2 = 0;
	while (iter1 < oldf.size() && iter2 < newf.size()) {
		if (oldf[iter1].changes == NOTCHANGED && newf[iter2].changes == NOTCHANGED) {
			iter1++; iter2++;
		}
		else
			if (oldf[iter1].changes == NOTCHANGED && newf[iter2].changes == ADDED) {
				diffString buf(newf[iter2]);
				buf.originalNumber = iter1;
				buf.newNumber = ++iter2;
				result.push_back(buf);
			}
			else
				if (oldf[iter1].changes == DELETED) {
					diffString buf(oldf[iter1]);
					buf.originalNumber = ++iter1;
					buf.newNumber = iter2;
					result.push_back(buf);
				}
	}
	if (iter1 == oldf.size()) {
		while (iter2 < newf.size()) {
			diffString buf(newf[iter2]);
			buf.originalNumber = iter1;
			buf.newNumber = ++iter2;
			result.push_back(buf);
		}
	}
	else if (iter2 == newf.size()) {
		while (iter1 < oldf.size()) {
			diffString buf(oldf[iter1]);
			buf.originalNumber = ++iter1;
			buf.newNumber = iter2;
			result.push_back(buf);
		}
	}
	return result;
}

bool checkFileChanges(string fileName, string owner) {
	if (!isSaved(fileName)) throw accessError(NOT_SAVED);
	if (!isAccessable(fileName, owner)) throw accessError(NOT_USER);

	string fileDirectory = getFilePath(fileName);

	diffTree tree(fileName);
	vector<bool> symbols;
	tree.printTreeIDs(symbols);
	cout << endl;
	tree.recoursiveDiffOutput();

	cout << endl;
	system("pause");
	drawCats();
	return true;
}
