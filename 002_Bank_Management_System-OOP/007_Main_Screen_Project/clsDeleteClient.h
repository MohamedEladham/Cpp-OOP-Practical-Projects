#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsOutputValidate.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteClient : protected clsScreen
{

public:

    static void ShowDeleteClientScreen()
    {
        string Title = "* * * Delete Client Screen * * *";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber;
        cout << "\t\t\t\t\t\t > Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString2();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\t\t\t\t\t\t > Client Is Not Found, Enter Another Account Number: ";
            AccountNumber = clsInputValidate::ReadString();
        }



        clsBankClient Client = clsBankClient::GetDeleteClient(AccountNumber);
        clsOutputValidate::PrintClientCard(Client);

        cout << "\n";
        char Answer;
        cout << "\t\t\t\t\t\t > Are You Sure Delete This Client Y/N: ";
        cin >> Answer;


        if (toupper(Answer) == 'Y')
        {

            clsBankClient::enSaveResults SaveResults;
            SaveResults = Client.Save(); 

            switch (SaveResults)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\n\n\n";
                cout << "\t\t\t\t\t\t\t    Client Deleted Successfully.... \n\n";
                break;
            }

            case clsBankClient::enSaveResults::svFailedToDeleteClient: 
            {
                cout << "\n\n\n";
                cout << "\t\t\t\t\t\t InValid Operation Client Is Empty..... \n\n\n";
                break;
            }

            case clsBankClient::enSaveResults::svFailedDeletedClientNotFound:
            {
                cout << "\n\n\n";
                cout << "\t\t\t\t\t\t InValid Operation Client Is Not Exists..... \n\n\n";
                break;
            }

           
            }
        }
    }
};
