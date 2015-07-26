#include "Help.h"

void printHelp() {
	int check = -1;
	while (check == -1) {
		cout << "Enter option you want to be helped with :)" << endl;
		cout << "1. Add file" << endl;
		cout << "2. Add existing file" << endl;
		cout << "3. Add permission" << endl;
		cout << "4. Delete file" << endl;
		cout << "5. Check changes of file" << endl;
		cout << "6. Go to choosen version of file" << endl;
		cout << endl << "0. Exit from Help" << endl << endl;
		cin >> check;
		switch (check) {
		case 1:
			system("cls");
			showAddingHelp();
			system("pause");
			system("cls");
			check = -1;
			break;
		case 2:
			system("cls");
			showAddingExistingHelp();
			system("pause");
			system("cls");
			check = -1;
			break;
		case 3:
			system("cls");
			showAddingPermissionsHelp();
			system("pause");
			system("cls");
			check = -1;
			break;
		case 4:
			system("cls");
			showDeletingHelp();
			system("pause");
			system("cls");
			check = -1;
			break;
		case 5:
			system("cls");
			showCheckingHelp();
			system("pause");
			system("cls");
			check = -1;
			break;
		case 6:
			system("cls");
			showGoToVersionHelp();
			system("pause");
			system("cls");
			check = -1;
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

void showAddingHelp() {
	cout << "Adding" << endl << endl;
	cout << "Firstly, you should choose the name for your file" << endl;
	cout << "This name will be kind of identifier for it" << endl;
	cout << "Try to choose correct, short, but unique name" << endl << endl;
	cout << "Secondly, you should enter correct path to file to upload" << endl;
	cout << "For instance, \'D:\\Files\\myfile.cpp\'" << endl << endl;
	cout << "If something goes wrong, you will get an error message" << endl << endl;
	cout << "If everything's ok you get the \'Done!\' message" << endl;
	cout << "Otherwise you get error message" << endl << endl;
}

void showAddingExistingHelp() {
	cout << "Adding existing file" << endl << endl;
	cout << "Firstly, you should choose what file to modernize" << endl;
	cout << "That's the name you have chosen when you were adding new file" << endl;
	cout << "Enter the name of saved file correctly" << endl << endl;
	cout << "Secondly, you should enter correct path to file to upload" << endl;
	cout << "For instance, \'D:\\Files\\myfile.cpp\'" << endl << endl;
	cout << "Old file will be replaced with new one, only diff tree will be saved" << endl;
	cout << "Remember, only owner and allowed users can modify files!" << endl;
	cout << "If something goes wrong, you will get an error message" << endl << endl;
	cout << "After that you should choose the limb of diff tree" << endl;
	cout << "You will see the whole tree and choose the limb you wish" << endl << endl;
	cout << "If everything's ok you get the \'Done!\' message" << endl;
	cout << "Otherwise you get error message" << endl << endl;
}

void showAddingPermissionsHelp() {
	cout << "Adding permissions" << endl << endl;
	cout << "Firstly, you should choose what file permissions to modernize" << endl;
	cout << "That's the name you have chosen when you were adding new file" << endl;
	cout << "Enter the name of saved file correctly" << endl << endl;
	cout << "Secondly, you should enter nickname of new user" << endl;
	cout << "This user will be able to modify file" << endl;
	cout << "Remember, only owner can add new users!" << endl;
	cout << "If everything's ok you get the \'Done!\' message" << endl;
	cout << "Otherwise you get error message" << endl << endl;
}

void showDeletingHelp() {
	cout << "Deleting" << endl << endl;
	cout << "Firstly, you should choose what file permissions to modernize" << endl;
	cout << "That's the name you have chosen when you were adding new file" << endl;
	cout << "Enter the name of saved file correctly" << endl << endl;
	cout << "This option will delete file, diff file and permissions file" << endl;
	cout << "You won\'t be able to return your file, so think twice before deleting" << endl;
	cout << "Remember, only owner can delete file!" << endl;
	cout << "If everything's ok you get the \'Done!\' message" << endl;
	cout << "Otherwise you get error message" << endl << endl;
}

void showCheckingHelp() {
	cout << "File checking" << endl << endl;
	cout << "Firstly, you should choose what file permissions to modernize" << endl;
	cout << "That's the name you have chosen when you were adding new file" << endl;
	cout << "Enter the name of saved file correctly" << endl << endl;
	cout << "This option will print whole diff tree and all the versions" << endl;
	cout << "diffNodes have the same IDs as the limbs at printed tree" << endl;
	cout << "Remember, only owner and allowed users can check changes!" << endl;
	cout << "If everything's ok you get the \'Done!\' message" << endl;
	cout << "Otherwise you get error message" << endl << endl;
}

void showGoToVersionHelp() {
	cout << "Go to choosen version" << endl << endl;
	cout << "Firstly, you should choose what file permissions to modernize" << endl;
	cout << "That's the name you have chosen when you were adding new file" << endl;
	cout << "Enter the name of saved file correctly" << endl << endl;
	cout << "After that you should choose the limb of diff tree" << endl;
	cout << "You will see the whole tree and choose the limb you wish" << endl;
	cout << "Your file will be modified as you wished" << endl << endl;
	cout << "Remember, only owner and allowed users can modify files!" << endl;
	cout << "If everything's ok you get the \'Done!\' message" << endl;
	cout << "Otherwise you get error message" << endl << endl;
}
