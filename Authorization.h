#ifndef AUTHORIZATION
#define AUTHORIZATION

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Check if user is in base
bool inBase(string nickname);
//Check if password is valid
bool passwordIsOk(string nickname, string password);
//Create new record (login + pass);
void createNewRecord(string nickname, string password);
//Authorization form, returns nickname
string Authorization();

#endif
