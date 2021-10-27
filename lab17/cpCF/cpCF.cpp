#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string>
using namespace std;
int main(int argc, LPTSTR argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc != 3)
	{
		printf("Using: cpCF file1 file2\n");
		return 1;
	}
	if (!CopyFile(argv[1], argv[2], FALSE))
	{
		printf("Error CopyFile : %x\n", GetLastError());
		return 2;
	}
	return 0;
}