#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"

using namespace std;

class clsUpdateClient : protected clsScreen
{
public:

    static void ShowUpdateClientScreen()
    {
        string Title = "* * * Update Client Screen * * *";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber;
        cout << "\t\t\t\t\t\t > Enter Account Number: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\t\t\t\t\t\t > Client Is Not Exists, Enter Another Account Number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        clsOutputValidate::PrintClientCard(Client);

        cout << "\n";
        char Answer;
        cout << "\t\t\t\t\t\t > Are You Sure Update This Client Y/N: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clsInputValidate::ReadClientInfo(Client);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t\t\t     Client Updated Successfully.... \n\n";
                clsOutputValidate::PrintClientCard(Client);
                break;
            }

            case clsBankClient::enSaveResults::svFailedEmptyObject:
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t\t\t  Invalid Operation, Client Is Empty. \n\n";
                break;
            }
            }
        }
    }
};
