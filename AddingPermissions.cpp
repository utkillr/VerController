#include "AddingPermissions.h"

bool addPermission(string fileName, string owner, string op) {
	if (!isSaved(fileName)) throw accessError(NOT_SAVED);
	if (!isOwner(fileName, owner)) throw accessError(NOT_OWNER);
	if (isAccessable(fileName, op)) throw accessError(USER);

	string fileDirectory = getFilePath(fileName);
	fstream permissionsFile(fileDirectory + '\\' + fileName + "-perm.dat", ios::app);
	permissionsFile << op << " ";
	permissionsFile.close();
	return true;
}
