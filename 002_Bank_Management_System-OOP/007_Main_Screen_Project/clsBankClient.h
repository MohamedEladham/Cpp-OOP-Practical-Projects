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
	enum enMode
	{
		EmptyMode = 0,
		UpdateMode = 1,
		AddNewMode = 2,
		DeleteMode = 3
	};

	enMode _Mode;
	string _AccountNumber;
	string _Password;
	float _AccountBalance;

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

	bool _Delete()
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientDataFromFile();

		fstream MyFile;
		MyFile.open(ClientsFile, ios::out);

		if (!MyFile.is_open())
			return false;

		string Line;

		for (clsBankClient& C : vClient)
		{
			if (C._AccountNumber != _AccountNumber)
			{
				Line = _ConvertClientObjectToLine(C);
				MyFile << Line << endl;
			}
		}

		MyFile.close();

		return !MyFile.fail();
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

	static clsBankClient _ConvertLineToClientObject(string Line)
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, "#//#");

		return clsBankClient(
			enMode::UpdateMode,
			vClientData[0],
			vClientData[1],
			vClientData[2],
			vClientData[3],
			vClientData[4],
			vClientData[5],
			stof(vClientData[6])
		);
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

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber,
		string Password, float AccountBalance) :
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
			return svFailedEmptyObject;
		}
		
		case enMode::AddNewMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return svFailedAddedObjectExists;
			}
			else
			{
				_AddNew();
				_Mode = UpdateMode;
				return svSucceeded;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();
			return svSucceeded;
		}

		case enMode::DeleteMode:
		{
			if (!IsClientExist(_AccountNumber))
			{
				return svFailedDeletedClientNotFound;
			}

			if (!_Delete())
			{
				return svFailedToDeleteClient;
			}

			*this = _GetEmptyClientObject();
			return svSucceeded;
		}
		}

		return svFailedEmptyObject;
	}

	static vector <clsBankClient> GetClientList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientDataFromFile();

		double TotalBalances = 0;

		for (clsBankClient& C : vClient)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	static clsBankClient GetAddNewClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static clsBankClient GetDeleteClient(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		
		return clsBankClient(enMode::DeleteMode, Client.FirstName, Client.LastName, Client.Email, Client.Phone, AccountNumber, Client.Password, Client.AccountBalance);
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

	static clsBankClient Find(string AccountNumber, string Password)
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientDataFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C._AccountNumber == AccountNumber && C.Password == Password)
			{
				return C;
			}
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return Client._Mode == UpdateMode;
	}
};
