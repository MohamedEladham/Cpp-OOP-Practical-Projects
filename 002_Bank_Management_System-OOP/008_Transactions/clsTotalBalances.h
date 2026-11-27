#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtility.h"

using namespace std;

class clsTotalBalances : protected clsScreen
{
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "\t\t\t   ";
        cout << "| " << left << setw(25) << Client.AccountNumber();
        cout << "| " << left << setw(33) << Client.FullName();
        cout << "| " << left << setw(19) << Client.AccountBalance;
    }

public:

    static void ShowTotalBalancesMenuScreen()
    {
        string Title = "* * Total Balances Screen * *";
        clsScreen::_DrawScreenHeader(Title);

        vector <clsBankClient> vClient;
        vClient = clsBankClient::GetClientList();

        cout << "\n";
        cout << "\t\t\t\t\t\t\t";
        cout << "Balances List [" << vClient.size() << "] Client(s). \n";
        cout << "\t\t\t   ";
        cout << "_________________________________________________________________________________________\n\n";
        cout << "\t\t\t   ";
        cout << "| " << left << setw(25) << "Account Number";
        cout << "| " << left << setw(33) << "Client Name";
        cout << "| " << left << setw(19) << "Balance" << endl;
        cout << "\t\t\t   ";
        cout << "_________________________________________________________________________________________\n\n";

        if (vClient.size() == 0)
        {
            cout << "\t\t\t\t\t\t\t";
            cout << "No Client Available In The System. \n\n";
        }
        else
        {
            for (clsBankClient& C : vClient)
            {
                _PrintClientRecordBalanceLine(C);
                cout << endl;
            }
        }

        cout << "\t\t\t   ";
        cout << "_________________________________________________________________________________________\n\n";

        cout << "\t\t\t\t\t\t\t";

        float TotalBalances = clsBankClient::GetTotalBalances();

        cout << "Total Balances = " << TotalBalances << endl;

        cout << "\t\t\t\t\t\t\t";
        cout << clsUtility::NumberToText(TotalBalances) << "\n\n";
    }
};
