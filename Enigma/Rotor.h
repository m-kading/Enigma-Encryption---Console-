/********************************************************
*	Rotor Class											*		
*														*
*	stores the arrays for the rotor and step position	*
*														*
*	Author: Marcus Kading								*
*********************************************************/

#pragma once
#include <iostream>
#include <array>

class Rotor
{
public:
	Rotor()
	{

	}
	Rotor(char inRotor[26], char notch);	// Constructor
	void Step();							// Rotates rotor
	char Sub(char input);					// Initial substitution of letter
	char ReflectSub(char input);			// Reflected substitution of letter
	bool checkNotch();						// checks if notch position reached
private:
	char rotor[26];							// Holds current substitution pairs
	char step;								// Holds step notch position 
};