#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"
using namespace std;

class clsAddNewClinet : protected clsScreen
{

public:

    static void ShowAddNewClientScreen()
    {
        string Title = "  * * * Add New Client * * *";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber;
        cout << "\n";
        cout << "\t\t\t\t\t\t > Enter Account Number: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\t\t\t\t\t\t > Client Is Exists, Enter Another Account Number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);
        clsInputValidate::ReadClientInfo(NewClient);

        char Answer;
        cout << "\n";
        cout << "\t\t\t\t\t\t > Are You Sure Do You Want Add This Client Y/N: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            clsBankClient::enSaveResults SaveResults;
            SaveResults = NewClient.Save();

            switch (SaveResults)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\n\n\n";
                cout << "\t\t\t\t\t\t\t    Client Added Successfully..... \n\n";
                clsOutputValidate::PrintClientCard(NewClient);
                break;
            }

            case clsBankClient::enSaveResults::svFailedEmptyObject:
            {
                cout << "\n\n\n";
                cout << "\t\t\t\t\t\t InValid Operation Client Is Empty..... \n\n\n";
                break;
            }

            case clsBankClient::enSaveResults::svFailedAddedObjectExists:
            {
                cout << "\n\n\n";
                cout << "\t\t\t\t\t\t InValid Operation Client Is Exists..... \n\n\n";
                break;
            }
            }
        }
    }
};
