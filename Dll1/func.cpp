#include "pch.h"
#include "funct.h"
#pragma warning(disable : 4996)

std::string MyFunc::GetTime()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	return dt;
}
