#include<stdio.h>
#include<Windows.h>
#define CHARBUFF 124
#define BUFFSIZE 1024

void getCurrentDirectory(char* currentDirectry) {
	GetCurrentDirectory(CHARBUFF, currentDirectry);
}

char* readChar(const char* section, const char* keyword, const char* filePath) {

	char* keyValue = NULL;
	keyValue = (char*)malloc(CHARBUFF);

	if (GetPrivateProfileString(section, keyword, "none", keyValue, CHARBUFF, filePath) != 0) {
		fprintf(stdout, "%s,%s\n", filePath, keyValue);
	}
	else {
		fprintf(stdout, "%s doesn't contain[$s] %s\n", filePath, section, keyword);
	}
	return keyValue;
}