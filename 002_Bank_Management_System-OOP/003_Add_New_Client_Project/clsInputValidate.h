#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
private:

	static void _ValidationNumber(int& Num, string Message)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Num;
		}
	}

	static void _ValidationNumber(float& Num, string Message)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Num;
		}
	}

	static void _ValidationNumber(double& Num, string Message)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Num;
		}
	}

public:

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static string ReadString()
	{
		string S1;
		getline(cin, S1);
		return S1;
	}

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1BeforeDate2(DateTo, DateFrom))
			Swap(DateFrom, DateTo);

		return !(clsDate::CompareDate(Date, DateFrom) == clsDate::Before || clsDate::CompareDate(Date, DateTo) == clsDate::After);
	}

	static int ReadIntNumber(string Message = "Invalid Number, Enter Again: ")
	{
		int Num;
		cin >> Num;
		_ValidationNumber(Num, Message);
		return Num;
	}

	static float ReadFloatNumber(string Message = "Invalid Number, Enter Again: ")
	{
		float Num;
		cin >> Num;
		_ValidationNumber(Num, Message);
		return Num;
	}

	static double ReadDoubleNumber(string Message = "Invalid Number, Enter Again: ")
	{
		double Num;
		cin >> Num;
		_ValidationNumber(Num, Message);
		return Num;
	}

	static int ReadIntNumberBetween(int From, int To, string Message)
	{
		int Num = ReadIntNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << Message;
			Num = ReadIntNumber();
		}

		return Num;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};
