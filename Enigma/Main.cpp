#include <iostream>
#include <array>
#include <string>
#include "Rotor.h"
#include "Reflector.h"

bool available[5] = { true, true, true, true, true };

std::string settings[7];
std::string rotorNames[5] = {"I", "II" , "III", "IV", "V", };

Rotor rotor1;
Rotor rotor2;
Rotor rotor3;

Reflector reflector;

// Defining the rotor substitutions, that user can select from
char rotorI[26] = { 'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J' };
char rotorII[26] = { 'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E' };
char rotorIII[26] = { 'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O' };
char rotorIV[26] = { 'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B' };
char rotorV[26] = { 'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K' };

bool CheckAvailable(int rotorNum)
{
	if (available[rotorNum - 1] == true)
	{
		return true;
	}
	return false;
}

int main()
{

	// Defining the reflector pairs
	int reflectorB[26] = { 25,18,21,8,17,19,12,4,16,24,14,7,15,11,13,9,5,2,6,26,3,23,22,10,1,20 };
	int reflectorC[26] = { 6,22,16,10,9,1,15,25,5,4,18,26,24,23,7,3,20,11,21,17,19,2,14,13,8,12 };
	
	std::string cipher = "";

	// I:R II:F III:W IV:K V:A

	bool menuBool = false;
	int choice = 0;

	// Assign right rotor
	while (menuBool == false)
	{
		std::cout << "-------------------------\n";
		std::cout << "Select Right rotor (1-5)\n";
		std::cin >> choice;

		if (choice > 0 && choice < 6)
		{
			if (CheckAvailable(choice) == true)
			{
				available[choice - 1] = false;
				settings[0] = rotorNames[choice - 1];
				switch (choice)
				{
				case 1:
					rotor1 = Rotor(rotorI, 'R');
					break;
				case 2:
					rotor1 = Rotor(rotorII, 'F');
					break;
				case 3:
					rotor1 = Rotor(rotorIII, 'W');
					break;
				case 4:
					rotor1 = Rotor(rotorIV, 'K');
					break;
				case 5:
					rotor1 = Rotor(rotorV, 'A');
					break;
				}
				menuBool = true;
			}
			else
			{
				std::cout << "rotor already in use please pick another\n";
			}
		}
		else
		{
			std::cout << "Invalid Input\n";
		}
	};

	menuBool = false;
	choice = 0;

	// Assign middle rotor
	while (menuBool == false)
	{
		std::cout << "-------------------------\n";
		std::cout << "Select Middle rotor (1-5)\n";
		std::cin >> choice;

		if (choice > 0 && choice < 6)
		{
			if (CheckAvailable(choice) == true)
			{
				available[choice - 1] = false;
				settings[2] = rotorNames[choice - 1];
				switch (choice)
				{
				case 1:
					rotor2 = Rotor(rotorI, 'R');
					break;
				case 2:
					rotor2 = Rotor(rotorII, 'F');
					break;
				case 3:
					rotor2 = Rotor(rotorIII, 'W');
					break;
				case 4:
					rotor2 = Rotor(rotorIV, 'K');
					break;
				case 5:
					rotor2 = Rotor(rotorV, 'A');
					break;
				}
				menuBool = true;
			}
			else
			{
				std::cout << "rotor already in use please pick another\n";
			}
		}
		else
		{
			std::cout << "Invalid Input\n";
		}
	};

	menuBool = false;
	choice = 0;

	// Assign left rotor
	while (menuBool == false)
	{
		std::cout << "-------------------------\n";
		std::cout << "Select Left rotor (1-5)\n";
		std::cin >> choice;

		if (choice > 0 && choice < 6)
		{
			if (CheckAvailable(choice) == true)
			{
				available[choice - 1] = false;
				settings[4] = rotorNames[choice - 1];
				switch (choice)
				{
				case 1:
					rotor3 = Rotor(rotorI, 'R');
					break;
				case 2:
					rotor3 = Rotor(rotorII, 'F');
					break;
				case 3:
					rotor3 = Rotor(rotorIII, 'W');
					break;
				case 4:
					rotor3 = Rotor(rotorIV, 'K');
					break;
				case 5:
					rotor3 = Rotor(rotorV, 'A');
					break;
				}
				menuBool = true;
			}
			else
			{
				std::cout << "rotor already in use please pick another\n";
			}
		}
		else
		{
			std::cout << "Invalid Input\n";
		}
	};

	std::cout << "-------------------------\n";
	std::cout << "|L\t|M\t|R\t|\n";
	std::cout << "|" << settings[4] << "\t|" << settings[2] << "\t|" << settings[0] << "\t|\n";

	menuBool = false;
	choice = 0;
	// set right rotor numbers
	while (menuBool == false)
	{
		std::cout << "-------------------------\n";
		std::cout << "Set right rotor (1-26)\n";
		std::cin >> choice;
		if (choice > 0 && choice < 27)
		{
			settings[1] = std::to_string(choice);
			menuBool = true;
			for (int i = 0; i < choice; i++)
			{
				rotor1.Step();
			}
		}
	}

	menuBool = false;
	choice = 0;
	// set middle rotor numbers
	while (menuBool == false)
	{
		std::cout << "-------------------------\n";
		std::cout << "Set Middle rotor (1-26)\n";
		std::cin >> choice;
		if (choice > 0 && choice < 27)
		{
			settings[3] = std::to_string(choice);
			menuBool = true;

			for (int i = 0; i < choice; i++)
			{
				rotor2.Step();
			}
		}
	}

	menuBool = false;
	choice = 0;
	// set Left rotor numbers
	while (menuBool == false)
	{
		std::cout << "-------------------------\n";
		std::cout << "Set left rotor (1-26)\n";
		std::cin >> choice;
		if (choice > 0 && choice < 27)
		{
			settings[5] = std::to_string(choice);
			menuBool = true;

			for (int i = 0; i < choice; i++)
			{
				rotor3.Step();
			}
		}
	}

	std::cout << "-------------------------\n";
	std::cout << "|L\t|M\t|R\t|\n";
	std::cout << "|" << settings[4] << " " << settings[5];
	std::cout << "\t|" << settings[2] << " " << settings[3];
	std::cout << "\t|" << settings[0] << " " << settings[1] << "\t|\n";

	char reflSelect;
	menuBool = false;

	while (menuBool == false)
	{
		std::cout << "-------------------------\n";
		std::cout << "Select Reflector (B/C)\n";
		std::cin >> reflSelect;
		reflSelect = (char)toupper(reflSelect);

		if (reflSelect == 'B' || reflSelect == 'C')
		{
			switch (reflSelect)
			{
			case 'B':
				reflector = Reflector(reflectorB);
				settings[6] = "B";
				break;
			case 'C':
				reflector = Reflector(reflectorC);
				settings[6] = "C";
				break;
			}

			menuBool = true;
		}
		else
		{
			std::cout << "Invalid Input\n";
		}
	};
	system("cls");
	std::cout << "---------------------------------\n";
	std::cout << "|Ref\t|L\t|M\t|R\t|\n";
	std::cout << "|" << settings[6] <<"\t|" << settings[4] << " " << settings[5];
	std::cout << "\t|" << settings[2] << " " << settings[3];
	std::cout << "\t|" << settings[0] << " " << settings[1] << "\t|\n";
	std::cout << "---------------------------------\n";
	std::cout << "Cipher Started...\n---------------------------------\n";

	
	char current;

	while (true)
	{
		std::cin >> current;
		current = (char)toupper(current);

		rotor1.Step();
		settings[1] = std::to_string((std::stoi(settings[1]) + 1)%27);
		if (settings[1] == "0")  std::to_string(std::stoi(settings[1]) + 1);
		if (rotor1.checkNotch() == true)
		{
			rotor2.Step();
			settings[3] = std::to_string((std::stoi(settings[3]) + 1) % 27);
			if (settings[3] == "0")  std::to_string(std::stoi(settings[3]) + 1);
			if (rotor2.checkNotch() == true)
			{
				rotor3.Step();
				settings[5] = std::to_string((std::stoi(settings[5]) + 1) % 27);
				if (settings[5] == "0")  std::to_string(std::stoi(settings[5]) + 1);
			}
		}

		current = rotor1.Sub(current);
		current = rotor2.Sub(current);
		current = rotor3.Sub(current);

		current = reflector.Reflect(current);

		current = rotor3.ReflectSub(current);
		current = rotor2.ReflectSub(current);
		current = rotor1.ReflectSub(current);

		cipher = cipher + current;

		system("cls");
		std::cout << "---------------------------------\n";
		std::cout << "|\t|L\t|M\t|R\t|\n";
		std::cout << "|" << settings[6] << "\t|" << settings[4] << " " << settings[5];
		std::cout << "\t|" << settings[2] << " " << settings[3];
		std::cout << "\t|" << settings[0] << " " << settings[1] << "\t|";
		std::cout << "\n------------------------------------------------------------------\n";
		std::cout << "Output:" << "\n\n";
		std::cout << cipher;
		std::cout << "\n------------------------------------------------------------------\n";

	};
	

	

	std::cin.ignore();
	std::cin.ignore();
	return 0;
}

