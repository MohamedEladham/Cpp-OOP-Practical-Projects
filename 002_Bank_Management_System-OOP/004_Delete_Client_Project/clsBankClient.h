
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;

const string ClientsFile = "Clients.txt";

class clsBankClient : public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
	enMode _Mode;
	string _AccountNumber;
	string _Password;
	float  _AccountBalance;


	bool _Delete()
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientDataFromFile();

		fstream MyFile;
		MyFile.open(ClientsFile, ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClient)
			{
				string Line;

				if (C._AccountNumber != _AccountNumber)
				{
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
			return !MyFile.fail();
		}

		return false;
	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName + Separator;
		Line += Client.LastName + Separator;
		Line += Client.Email + Separator;
		Line += Client.Phone + Separator;
		Line += Client._AccountNumber + Separator;
		Line += Client.Password + Separator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	void _SaveClientDataToFile(vector <clsBankClient>& vClient)
	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out);

		if (MyFile.is_open())
		{
			string Line;

			for (clsBankClient& C : vClient)
			{
				Line = _ConvertClientObjectToLine(C);
				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientDataFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(vClient);
	}

	static clsBankClient _ConvertLineToClientObject(string S1)
	{
		vector <string> vClientData;
		vClientData = clsString::Split(S1, "#//#");

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		vector <clsBankClient> vClient;

		fstream MyFile;
		MyFile.open(ClientsFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClient.push_back(Client);
			}

			MyFile.close();
		}

		return vClient;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string Password, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_Password = Password;
		_AccountBalance = AccountBalance;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\n\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _Password;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	enum enSaveResults
	{
		svFailedEmptyObject = 0,
		svSucceeded = 1,
		svFailedAddedObjectExists = 2,
		svFailedDeletedClientNotFound = 3,
		svFailedToDeleteClient = 4
	};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFailedEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case enMode::AddNewMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAddedObjectExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}

		case enMode::DeleteMode:
		{
			if (!IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedDeletedClientNotFound;
			}

			if (!_Delete())
			{
				return enSaveResults::svFailedToDeleteClient;
			}

			*this = _GetEmptyClientObject();
			return enSaveResults::svSucceeded;
		}
		}

		return enSaveResults::svFailedToDeleteClient;
	}

	static clsBankClient GetDeleteClient(string AccountNumber)
	{
		return clsBankClient(enMode::DeleteMode, "", "", "", "", AccountNumber, "", 0);
	}

	static clsBankClient GetAddNewClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientDataFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C._AccountNumber == AccountNumber)
			{
				return C;
			}
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientDataFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C._AccountNumber == AccountNumber && C.Password == PinCode)
			{
				return C;
			}
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return Client._Mode == enMode::UpdateMode;
	}
};
