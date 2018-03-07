#include "Reflector.h"

Reflector::Reflector(int inputReflector[26])
{
	for (int i = 0; i < 26; i++)
	{
		pairs[i] = inputReflector[i];
	}
}
char Reflector::Reflect(char inputCurrent)
{
	char output;
	output = (int)inputCurrent-65;
	output = (char)(pairs[(int)output]);
	output += 64;
	return output;
}