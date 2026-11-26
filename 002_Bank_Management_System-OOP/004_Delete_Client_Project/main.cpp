#include <iostream>
#include <string>
#include <cctype>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void DeleteClient()
{
	string AccountNumber;

	cout << "\nEnter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nClient Is Not Found, Enter Another Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();

	char Answer;

	cout << "\nDelete This Client Y/N: ";
	cin >> Answer;

	if (toupper(Answer) == 'Y')
	{
		Client = clsBankClient::GetDeleteClient(AccountNumber);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Deleted Successfully :-)\n";
			break;
		}

		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError account was not Deleted because it's Empty";
			break;
		}

		case clsBankClient::enSaveResults::svFailedDeletedClientNotFound:
		{
			cout << "\nError account was not Deleted because account number is Not Found!\n";
			break;
		}

		case clsBankClient::enSaveResults::svFailedToDeleteClient:
		{
			cout << "\nError account was not Deleted because saving data to file failed!\n";
			break;
		}
		}
	}
}

int main()
{
	DeleteClient();
	cout << "\n\n\n\n\n";
	return 0;
}
