#include "Deleting.h"

bool deleteFile(string fileName) {
	string fileDirectory = getFilePath(fileName);
	if (remove((fileDirectory + '\\' + fileName).c_str()) != 0) return false;
	else return true;
}

bool deleteFileWithPermissions(string fileName, string nickname) {
	if (!isSaved(fileName)) throw accessError(NOT_SAVED);
	if (!isOwner(fileName, nickname)) throw accessError(NOT_OWNER);

	string fileDirectory = getFilePath(fileName);
	remove((fileDirectory + '\\' + fileName).c_str());
	string permFileName = fileDirectory + '\\' + fileName + "-perm.dat";
	remove(permFileName.c_str());
	string diffFileName = fileDirectory + '\\' + fileName + "-diff.dat";
	remove(diffFileName.c_str());
	_rmdir(fileDirectory.c_str());
	return true;
}
