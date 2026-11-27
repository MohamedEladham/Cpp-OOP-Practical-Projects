#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsDate.h"
#include "clsUser.h"
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

	static bool CheckAnswer(string Message = "\t\t\t\t\t\t > Invalid Answer Enter [Y/N]: ")
	{
		char Answer;
		cin >> Answer;

		while (toupper(Answer) != 'Y' && toupper(Answer) != 'N')
		{
			cout << Message;
			cin >> Answer;
		}

		return toupper(Answer) == 'Y' ? true : false;
	}

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

	static string ReadString2()
	{
		string S1;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

	// >>

	static int ReadPermissions()
	{
		int Permissions = 0;

		cout << "\n";
		cout << setw(40) << left << "" << "\t > Enter Permissions: \n";

		cout << setw(40) << left << "" << "\t Do You Want to Give Full Access Y/N: ";

		if (clsInputValidate::CheckAnswer())
		{
			return Permissions = clsUser::enPermissions::eFullAcess;
		}
		else
		{
			cout << "\n";
			cout << setw(40) << left << "" << "\t> Show Client List Y/N: ";
			if (clsInputValidate::CheckAnswer())
			{
				Permissions += clsUser::enPermissions::eShowClientList;
			}

			cout << setw(40) << left << "" << "\t> Add New Client Y/N: ";
			if (clsInputValidate::CheckAnswer())
			{
				Permissions += clsUser::enPermissions::eAddNewClient;
			}

			cout << setw(40) << left << "" << "\t> Delete Client Y/N: ";
			if (clsInputValidate::CheckAnswer())
			{
				Permissions += clsUser::enPermissions::eDeleteClint;
			}

			cout << setw(40) << left << "" << "\t> Update Client Y/N: ";
			if (clsInputValidate::CheckAnswer())
			{
				Permissions += clsUser::enPermissions::eUpdateClient;
			}

			cout << setw(40) << left << "" << "\t> Find Client Y/N: ";
			if (clsInputValidate::CheckAnswer())
			{
				Permissions += clsUser::enPermissions::eFindClient;
			}

			cout << setw(40) << left << "" << "\t> Transactions Y/N: ";
			if (clsInputValidate::CheckAnswer())
			{
				Permissions += clsUser::enPermissions::eTransactions;
			}

			cout << setw(40) << left << "" << "\t> Manage Users Y/N: ";
			if (clsInputValidate::CheckAnswer())
			{
				Permissions += clsUser::enPermissions::eManageUser;
			}
		}

		return Permissions;
	}

	static void ReadNewUserInfo(clsUser& NewUser)
	{
		cout << "\n\n";

		cout << setw(40) << left << "" << "\t Enter First Name: ";
		NewUser.FirstName = clsInputValidate::ReadString();

		cout << setw(40) << left << "" << "\t Enter Last Name : ";
		NewUser.LastName = clsInputValidate::ReadString();

		cout << setw(40) << left << "" << "\t Enter Email     : ";
		NewUser.Email = clsInputValidate::ReadString();

		cout << setw(40) << left << "" << "\t Enter Phone     : ";
		NewUser.Phone = clsInputValidate::ReadString();

		cout << setw(40) << left << "" << "\t Enter Password  : ";
		NewUser.Password = clsInputValidate::ReadString();

		NewUser.Permissions = ReadPermissions();
	}

	// >>

	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\n\n";
		cout << "\t\t\t\t\t\t ** Read Client Information ** \n";
		cout << "\t\t\t\t\t\t ______________________________\n";

		cout << "\n";
		cout << "\t\t\t\t\t\t > Enter First Name: ";
		Client.FirstName = ReadString();

		cout << "\t\t\t\t\t\t > Enter Last Name: ";
		Client.LastName = ReadString();

		cout << "\t\t\t\t\t\t > Enter Email: ";
		Client.Email = ReadString();

		cout << "\t\t\t\t\t\t > Enter Phone: ";
		Client.Phone = ReadString();

		cout << "\t\t\t\t\t\t > Enter Password: ";
		Client.Password = ReadString();

		cout << "\t\t\t\t\t\t > Enter Account Balance: ";
		Client.AccountBalance = ReadFloatNumber();
	}
};
