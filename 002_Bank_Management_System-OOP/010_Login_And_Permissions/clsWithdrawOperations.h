#pragma once
#include <iostream>
#include <string>
#include <cctype>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"

using namespace std;

class clsWithdrawOperations : protected clsScreen
{

public:

    static void ShowWithdrawMenuScreen()
    {
        string Title = "* * * Withdraw Screen * * *";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber;
        cout << "\n";
        cout << "\t\t\t\t\t\t > Enter Account Number: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        AccountNumber = clsInputValidate::ReadString();

        if (clsBankClient::IsClientExist(AccountNumber))
        {
            clsBankClient Client = clsBankClient::Find(AccountNumber);
            clsOutputValidate::PrintClientCard(Client);

            cout << "\n";
            cout << "\t\t\t\t\t\t Available Balance = " << Client.AccountBalance << "\n\n";

            float WithdrawAmount;
            cout << "\t\t\t\t\t\t > Enter Withdraw Amount: ";
            WithdrawAmount = clsInputValidate::ReadFloatNumber("\t\t\t\t\t\t > Please Try Again: ");

            while (WithdrawAmount <= 0)
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t\t Invalid Operation........\n\n";
                cout << "\t\t\t\t\t\t Please Enter A Positive Number: ";
                WithdrawAmount = clsInputValidate::ReadFloatNumber("\t\t\t\t\t\t > Please Try Again: ");
            }

            char Answer;
            cout << "\t\t\t\t\t\t Are You Sure You Want To Perform This Transaction Y/N: ";
            cin >> Answer;

            if (toupper(Answer) == 'Y')
            {
                if (Client.Withdraw(WithdrawAmount))
                {
                    cout << "\n\n";
                    cout << "\t\t\t\t\t\t Amount Withdrawn Successfully........\n\n";
                    cout << "\t\t\t\t\t\t > New Balance = " << Client.AccountBalance << "\n\n";
                }
                else
                {
                    cout << "\n\n";
                    cout << "\t\t\t\t\t\t Your Balance Is Insufficient........\n\n";
                }
            }
            else
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t\t Operation Was Cancelled........\n\n";
            }
        }
        else
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t\t Client Does Not Exist..... \n\n";
        }
    }
};
