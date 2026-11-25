#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	cout << "\nRead Client Information: \n";
	cout << "_____________________________\n";

	cout << "\nEnter First Name: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter Last Name: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter Password: ";
	Client.Password = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}


void AddNewClient()
{
	string AccountNumber;
	cout << "\nEnter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nClient Already Exists, Enter Another Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);

	ReadClientInfo(NewClient);

	clsBankClient::enSaveResults SaveResult;

	SaveResult = NewClient.Save();

	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:
	{
		cout << "\nAccount Added Successfully :-)\n";
		NewClient.Print();
		break;
	}

	case clsBankClient::enSaveResults::svFailedEmptyObject:
	{
		cout << "\nError: Account Was Not Saved Because It's Empty.\n";
		break;
	}

	case clsBankClient::enSaveResults::svFailedAccountNumberExists:
	{
		cout << "\nError: Account Was Not Saved Because Account Number Is Already Used!\n";
		break;
	}

	case clsBankClient::enSaveResults::svFailedToSaveData:
	{
		cout << "\nError: Failed To Save Client Data!\n";
		break;
	}
	}
}

int main()
{
	AddNewClient();
	cout << "\n\n\n\n";
	return 0;
}
