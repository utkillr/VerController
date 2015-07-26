#include "Authorization.h"

bool inBase(string nickname) {
	string s;
	ifstream base("base.txt");
	if (!base) {
		base.close();
		ofstream newbase("base.txt");
		newbase.close();
		return false;
	}
	while (!base.eof()) {
		base >> s;
		if (s == nickname) {
			base.close();
			return true;
		}
		else base >> s;
	}
	base.close();
	return false;
}

bool passwordIsOk(string nickname, string password) {
	string nick, pass;
	ifstream base("base.txt");
	while (!base.eof()) {
		base >> nick;
		base >> pass;
		if (nick == nickname && pass == password) {
			base.close();
			return true;
		}
	}
	base.close();
	return false;
}

void createNewRecord(string nickname, string password) {
	string s;
	fstream base("base.txt", ios::app);
	base << nickname << " ";
	base << password << endl;
	base.close();
}

string Authorization() {
	bool done = false;
	string nickname;
	string password, confirmedpassword;

	while (!done) {
		cout << "Enter your nickname or register new one: ";
		cin >> nickname;
		if (inBase(nickname)) {
			system("cls");
			cout << "Registered!" << endl;
			cout << "Your nickname: " << nickname << endl;
			cout << "Enter password: ";
			cin >> password;
			if (passwordIsOk(nickname, password)) {
				system("cls");
				cout << "Successfully authorizated!" << endl;
				done = true;
			}
			else {
				system("cls");
				cout << "Wrong password! Try again" << endl;
			}
		}
		else {
			system("cls");
			cout << "Registration." << endl << "Your nickname: " << nickname << endl;
			cout << "Enter password: ";
			cin >> password;
			cout << "Confirm password: ";
			cin >> confirmedpassword;
			if (confirmedpassword == password) {
				createNewRecord(nickname, password);
				system("cls");
				cout << "Successfully registered!" << endl;
				done = true;
			}
			else {
				system("cls");
				cout << "Passwords are not the same! Try again" << endl;
			}
		}
	}
	return nickname;
}
