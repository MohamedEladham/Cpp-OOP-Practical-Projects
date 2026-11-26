#include <iostream>
#include <iomanip>
#include <vector>
#include "clsBankClient.h"
using namespace std;

void PrintClientRecordLine(clsBankClient Client)
{
	cout << "| " << left << setw(16) << Client.AccountNumber();
	cout << "| " << left << setw(19) << Client.FullName();
	cout << "| " << left << setw(13) << Client.Phone;
	cout << "| " << left << setw(18) << Client.Email;
	cout << "| " << left << setw(11) << Client.Password;
	cout << "| " << left << setw(9) << Client.AccountBalance;
}

void ShowClientsList()
{
	vector <clsBankClient> vClient;
	vClient = clsBankClient::GetClientList();

	cout << "\n\n";
	cout << "\t\t\t\t Client List [" << vClient.size() << "] Client(s). \n\n";
	cout << "___________________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(16) << "Account Number";
	cout << "| " << left << setw(19) << "Client Name";
	cout << "| " << left << setw(13) << "Phone";
	cout << "| " << left << setw(18) << "Email";
	cout << "| " << left << setw(11) << "Password";
	cout << "| " << left << setw(9) << "Balance" << endl;
	cout << "___________________________________________________________________________________________________\n\n";

	for (clsBankClient& C : vClient)
	{
		PrintClientRecordLine(C);
		cout << endl;
	}

	cout << "\n___________________________________________________________________________________________________\n\n";
}

int main()
{
	ShowClientsList();
	cout << "\n\n\n\n";
	return 0;
}
