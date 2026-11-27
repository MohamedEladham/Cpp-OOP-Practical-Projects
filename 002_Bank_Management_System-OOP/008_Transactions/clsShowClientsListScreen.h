
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsShowClientsListScreen : protected clsScreen
{
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "\t" << "| " << left << setw(16) << Client.AccountNumber();
        cout << "\t" << "| " << left << setw(19) << Client.FullName();
        cout << "\t" << "| " << left << setw(13) << Client.Phone;
        cout << "\t" << "| " << left << setw(18) << Client.Email;
        cout << "\t" << "| " << left << setw(11) << Client.Password;
        cout << "\t" << "| " << left << setw(9) << Client.AccountBalance;
    }

public:

    static void ShowClientListScreen()
    {
        vector <clsBankClient> vClient;
        vClient = clsBankClient::GetClientList();

        string Title = "* * * Client List Screen * * *";
        string SubTitle = "        [" + to_string(vClient.size()) + "] Client(s). ";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << "\t" << "________________________________________________________________________________________________________________________\n\n";

        cout << "\t" << "| " << left << setw(16) << "Account Number";
        cout << "\t" << "| " << left << setw(19) << "Client Name";
        cout << "\t" << "| " << left << setw(13) << "Phone";
        cout << "\t" << "| " << left << setw(18) << "Email";
        cout << "\t" << "| " << left << setw(11) << "Password";
        cout << "\t" << "| " << left << setw(9) << "Balance" << endl;

        cout << "\t" << "________________________________________________________________________________________________________________________\n\n";

        for (clsBankClient& C : vClient)
        {
            _PrintClientRecordLine(C);
            cout << endl;
        }

        cout << "\n";
        cout << "\t" << "________________________________________________________________________________________________________________________\n\n";
    }
};
