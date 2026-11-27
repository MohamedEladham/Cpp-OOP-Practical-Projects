
#pragma once
#include <iostream>
#include <string>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"

using namespace std;

class clsFindClient : protected clsScreen
{
public:

    static void ShowFindClientScreen()
    {
        string Title = "* * * Find Client Screen * * *";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber;
        cout << "\t\t\t\t\t\t > Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString2();

        if (clsBankClient::IsClientExist(AccountNumber))
        {
            clsBankClient Client = clsBankClient::Find(AccountNumber);
            clsOutputValidate::PrintClientCard(Client);
        }
        else
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t\t > Client Is Not Exists. \n";
        }
    }
};
