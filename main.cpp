#include <iostream>
#include <string>
#include <vector>
#include "Authorization.h"
#include "Adding.h"
#include "AddingPermissions.h"
#include "structures.h"
#include "outputs.h"
#include "Deleting.h"
#include "FileChecking.h"
#include "Help.h"

using namespace std;

/*ADD CHECKING FOR ADDRESS FILE!!!*/

int main() {
	string workingNickname = Authorization();
	string fileName;
	string filePath;
	string user;
	int check = -1;
	while (check == -1) {
		cout << "Enter number of option:" << endl;
		cout << "1. Add file" << endl;
		cout << "2. Add existing file" << endl;
		cout << "3. Add permission" << endl;
		cout << "4. Delete file" << endl;
		cout << "5. Check changes of file" << endl;
		cout << "6. Go to choosen version of file" << endl;
		cout << "7. Help" << endl;
		cout << endl << "0. Exit" << endl << endl;
		cin >> check;
		switch (check) {
		case 1:
			system("cls");
			cout << "Enter name of file: ";
			cin >> fileName;
			cout << "Enter full path to file: ";
			cin >> filePath;
			try {
				addNewFile(fileName, filePath, workingNickname);
			}
			catch (accessError error) {
				cout << endl << error.what() << endl;
				system("pause");
				check = -1;
				system("cls");
				break;
			}
			check = -1;
			system("cls");
			cout << "Done!" << endl;
			break;
		case 2:
			system("cls");
			cout << "Enter name of existing file: ";
			cin >> fileName;
			cout << "Enter full path to new file: ";
			cin >> filePath;
			try {
				addExistingFile(fileName, filePath, workingNickname);
			}
			catch (accessError error) {
				cout << endl << error.what() << endl;
				system("pause");
				check = -1;
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			check = -1;
			cout << "Done!" << endl;
			break;
		case 3:
			system("cls");
			cout << "Enter name of existing file: ";
			cin >> fileName;
			cout << "Enter new user: ";
			cin >> user;
			try {
				addPermission(fileName, workingNickname, user);
			}
			catch (accessError error) {
				cout << endl << error.what() << endl;
				system("pause");
				check = -1;
				system("cls");
				break;
			}
			check = -1;
			system("cls");
			cout << "Done!" << endl;
			break;
		case 4:
			system("cls");
			cout << "Enter name of existing file: ";
			cin >> fileName;
			try {
				deleteFileWithPermissions(fileName, workingNickname);
			}
			catch (accessError error) {
				cout << endl << error.what() << endl;
				system("pause");
				check = -1;
				system("cls");
				break;
			}
			check = -1;
			system("cls");
			cout << "Done!" << endl;
			break;
		case 5:
			system("cls");
			cout << "Enter name of existing file: ";
			cin >> fileName;
			try {
				checkFileChanges(fileName, workingNickname);
			}
			catch (accessError error) {
				cout << endl << error.what() << endl;
				system("pause");
				check = -1;
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			check = -1;
			break;
		case 6:
			system("cls");
			cout << "Enter name of existing file: ";
			cin >> fileName;
			try {
				changeFileVersion(fileName, workingNickname);
			}
			catch (accessError error) {
				cout << endl << error.what() << endl;
				system("pause");
				check = -1;
				system("cls");
				break;
			}
			check = -1;
			system("cls");
			cout << "Done!" << endl;
			break;
		case 7:
			system("cls");
			printHelp();
			check = -1;
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			break;
		default:
			system("cls");
			check = -1;
			break;
		}
	}
}
