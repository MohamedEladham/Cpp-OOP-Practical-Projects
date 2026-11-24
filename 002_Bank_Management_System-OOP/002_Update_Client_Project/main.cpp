#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	cout << "\n\nClient Informations Updating: \n";
	cout << "________________________\n\n";

	cout << "\nFirst Name: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "Last Name: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "Email    : ";
	Client.Email = clsInputValidate::ReadString();

	cout << "Phone    : ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "Password  : ";
	Client.Password = clsInputValidate::ReadString();

	cout << "Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadfloatNumber();
}

void UpdateClient()
{
	string AccountNumber;

	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	clsBankClient Client = clsBankClient::Find(AccountNumber);

	while (Client.IsEmpty())
	{
		cout << "\nAccount Number Is Not Found, Choose Another One: ";
		AccountNumber = clsInputValidate::ReadString();

		Client = clsBankClient::Find(AccountNumber);
	}

	Client.Print();

	ReadClientInfo(Client);

	clsBankClient::enSaveResults SaveResult;

	SaveResult = Client.Save();

	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:
		cout << "\nAccount Updated Successfully...\n";
		Client.Print();
		break;

	case clsBankClient::enSaveResults::svFailedEmptyObject:
		cout << "\nError: Account Was Not Saved Because It's Empty.\n";
		break;
	}
}

int main()
{
	UpdateClient();
	cout << "\n\n\n";
	return 0;
}