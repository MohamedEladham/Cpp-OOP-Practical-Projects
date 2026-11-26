#include <iostream>
#include <iomanip>
#include <vector>
#include "clsBankClient.h"
#include "clsUtility.h"
using namespace std;

void PrintClientRecordBalanceLine(clsBankClient Client)
{
	cout << "| " << left << setw(19) << Client.AccountNumber();
	cout << "| " << left << setw(30) << Client.FullName();
	cout << "| " << left << setw(19) << Client.AccountBalance;
}

void ShowTotalBalances()
{
	vector <clsBankClient> vClient;
	vClient = clsBankClient::GetClientList();

	cout << "\n\n";
	cout << "\t\t\tBalances List [" << vClient.size() << "] Client(s). \n";
	cout << "_________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(19) << "Account Number";
	cout << "| " << left << setw(30) << "Client Name";
	cout << "| " << left << setw(19) << "Balance" << endl;
	cout << "_________________________________________________________________________________________\n\n";

	for (clsBankClient& C : vClient)
	{
		PrintClientRecordBalanceLine(C);
		cout << endl;
	}

	cout << "\n_________________________________________________________________________________________\n\n";

	float TotalBalances = clsBankClient::GetTotalBalances();

	cout << "\t\t\t\t" << "Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t" << clsUtility::NumberToText(TotalBalances) << endl;
}

int main()
{
	ShowTotalBalances();
	cout << "\n\n\n\n";
	return 0;
}
