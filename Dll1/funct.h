#pragma once
#include <ctime>
#include <string>
#include "pch.h"

#ifdef FUNCTION_EXPORTS
#define FUNCTION_API __declspec(dllexport)
#else
#define FUNCTION_API __declspec(dllimport)
#endif

using namespace std;

static class MyFunc
{
public:
	static __declspec(dllexport) std::string GetTime();
};