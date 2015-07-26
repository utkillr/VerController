#include "outputs.h"

void showChangesVector(vector<diffString> vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].changes == ADDED)
			cout << "> " << vec[i].text << ' ' << vec[i].originalNumber << 'a' << vec[i].newNumber << endl;
		else
			cout << "< " << vec[i].text << ' ' << vec[i].originalNumber << 'd' << vec[i].newNumber << endl;
	}
}

void printDiffFile(string fileName, vector<diffString> difference) {
	string fileDirectory = getFilePath(fileName);
	fstream diffFile(fileDirectory + '\\' + fileName + "-diff.dat", ios::app);
	for (int i = 0; i < difference.size(); i++) {
		if (difference[i].changes == ADDED)
			diffFile << "> " << difference[i].text << ' ' << difference[i].originalNumber << 'a' << difference[i].newNumber << endl;
		else
			diffFile << "< " << difference[i].text << ' ' << difference[i].originalNumber << 'd' << difference[i].newNumber << endl;
	}
	diffFile << endl;
}

void drawCats() {
	cout << "             *     ,MMM8&&&.            *" << endl;
	cout << "                  MMMM88&&&&&    ." << endl;
	cout << "                 MMMM88&&&&&&&" << endl;
	cout << "     *           MMM88&&&&&&&&" << endl;
	cout << "                 MMM88&&&&&&&&" << endl;
	cout << "                 \'MMM88&&&&&&\'" << endl;
	cout << "                   \'MMM8&&&\'      *    " << endl;
	cout << "          |\\___/|     /\\___/\\" << endl;
	cout << "          )     (     )    ~( .              \'" << endl;
	cout << "         =\\     /=   =\\~    /=" << endl;
	cout << "           )===(       ) ~ (" << endl;
	cout << "          /     \\     /     \\" <<endl;
	cout << "          |     |     ) ~   (" << endl;
	cout << "         /       \\   /     ~ \\" <<endl;
	cout << "         \\       /   \\~     ~/" << endl;
	cout << "  _/\\_/\\_/\\__  _/_/\\_/\\__~__/_/\\_/\\_/\\_/\\_/\\_" << endl;
	cout << "  |  |  |  |( (  |  |  | ))  |  |  |  |  |  |" << endl;
	cout << "  |  |  |  | ) ) |  |  |/\/|  |  |  |  |  |  |" << endl;
	cout << "  |  |  |  |(_(  |  |  (( |  |  |  |  |  |  |" << endl;
	cout << "  |  |  |  |  |  |  |  |\\)|  |  |  |  |  |  |" << endl;
	cout << "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << endl << endl;
}
