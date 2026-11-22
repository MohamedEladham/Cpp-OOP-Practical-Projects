
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "clsDate.h"
using namespace std;

class clsUtility
{
public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		if (From > To)
		{
			int Temp = From;
			From = To;
			To = Temp;
		}

		int RandNum = rand() % (To - From + 1) + From;

		return RandNum;
	}

	enum enRandomCharacter { CapitalLetter = 1, SmallLetter = 2, Digit = 3, Mix = 4 };

	static char GetRandomCharacter(enRandomCharacter RandomCharacter)
	{
		if (RandomCharacter == enRandomCharacter::Mix)
		{
			RandomCharacter = (enRandomCharacter)RandomNumber(1, 3);
		}

		switch (RandomCharacter)
		{
		case enRandomCharacter::CapitalLetter:
			return char(RandomNumber(65, 90));

		case enRandomCharacter::SmallLetter:
			return char(RandomNumber(97, 122));

		case enRandomCharacter::Digit:
			return (char)RandomNumber(48, 57);

		default:
			return '\0';
		}
	}

	static string GenerateWord(enRandomCharacter RandomCharacter, short Length)
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
			Word += GetRandomCharacter(RandomCharacter);

		return Word;
	}

	static string GenerateKey(enRandomCharacter RandomCharacter, short WordLength, short KeyLength)
	{
		string Key = "";

		for (int i = 0; i < KeyLength; i++)
		{
			Key += GenerateWord(RandomCharacter, WordLength);
			if (i < KeyLength - 1)
				Key += "-";
		}

		return Key;
	}

	static void GenerateKeys(enRandomCharacter RandomCharacter, short WordLength, short KeyLength, short KeysLength)
	{
		for (int i = 1; i <= KeysLength; i++)
		{
			cout << "> Key [" << i << "] : " << GenerateKey(RandomCharacter, WordLength, KeyLength) << endl;
		}
	}


	// >>

	static void Swap(short& Num1, short& Num2)
	{
		short Temp;

		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(int& Num1, int& Num2)
	{
		int Temp;

		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(double& Num1, double& Num2)
	{
		double Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(string& S1, string& S2)
	{
		string Temp;
		Temp = S1;
		S1 = S2;
		S2 = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	// >>

	static void ShuffleArray(short Arr1[], short Arr1Length)
	{
		if (Arr1Length <= 0)
			return;

		for (short i = 0; i < Arr1Length; i++)
		{
			Swap(Arr1[RandomNumber(1, Arr1Length) - 1], Arr1[RandomNumber(1, Arr1Length) - 1]);
		}
	}

	static void ShuffleArray(string Arr1[], short Arr1Length)
	{
		if (Arr1Length <= 0)
			return;

		for (short i = 0; i < Arr1Length; i++)
		{
			Swap(Arr1[RandomNumber(1, Arr1Length) - 1], Arr1[RandomNumber(1, Arr1Length) - 1]);
		}
	}

	// >>

	static void FillArrayWithRandomNumber(short Arr1[], short Arr1Length, short From, short To)
	{
		for (short i = 0; i < Arr1Length; i++)
		{
			Arr1[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string Arr1[], short Arr1Length, enRandomCharacter RandomCharacter, short WordLength)
	{
		for (short i = 0; i < Arr1Length; i++)
		{
			Arr1[i] = GenerateWord(RandomCharacter, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string Arr1[], short Arr1Length, enRandomCharacter RandomCharacter, short WordLength, short KeyLength)
	{
		for (short i = 0; i < Arr1Length; i++)
		{
			Arr1[i] = GenerateKey(RandomCharacter, WordLength, KeyLength);
		}
	}

	static string Tabs(short Num)
	{
		string T = "";

		for (short i = 0; i < Num; i++)
		{
			T += "\t";
			cout << "\t";
		}

		return T;
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (size_t i = 0; i < Text.length(); i++)
			Text[i] = char((int)Text[i] + EncryptionKey);

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (size_t i = 0; i < Text.length(); i++)
			Text[i] = char((int)Text[i] - EncryptionKey);

		return Text;
	}
};
