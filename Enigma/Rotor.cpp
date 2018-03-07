#include "Rotor.h"

Rotor::Rotor(char inRotor[26], char notch)
{
	for (int i = 0; i < 26; i++)
	{
		rotor[i] = inRotor[i];
	}
	step = notch;
}
void Rotor::Step()
{
	for (int i = 0; i < 26; i++)
	{
		rotor[i] = (int)rotor[i] - 65;
		rotor[i] = ((int)rotor[i] + 1) % 26;
		rotor[i] = (int)rotor[i] + 65;
	}
}
char Rotor::Sub(char input)
{
	return rotor[(int)input-65];
}
char Rotor::ReflectSub(char input)
{
	int position = 0;

	for (int i = 0; i < 26; i++)
	{
		if (input == rotor[i])
		{
			position = i;
			return (char)(position + 65);
		}
		
	}
}
bool Rotor::checkNotch()
{
	if (rotor[0] == step)
	{
		return true;
	}

	return false;
}
