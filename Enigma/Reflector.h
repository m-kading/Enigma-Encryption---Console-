#pragma once
#include <iostream>

class Reflector
{
public:
	Reflector()
	{}
	Reflector(int inputReflector[26]);
	char Reflect(char inputCurrent);
private:
	int pairs[26];
};
