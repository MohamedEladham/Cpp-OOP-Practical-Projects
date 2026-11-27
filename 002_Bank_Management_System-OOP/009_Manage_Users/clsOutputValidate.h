#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsBankClient.h"
using namespace std;

class clsOutputValidate
{
public:

    static void PrintUserCard(clsUser User)
    {
        cout << "\n";
        cout << "\t\t\t\t\t\t _____________________________________________________\n\n";
        cout << "\t\t\t\t\t\t                  * * * User Card * * *                 \n";
        cout << "\t\t\t\t\t\t _____________________________________________________\n\n";

        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Frist Name" << "| " << left << setw(23) << User.FirstName << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Last Name" << "| " << left << setw(23) << User.LastName << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Full Name" << "| " << left << setw(23) << User.FullName() << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Email" << "| " << left << setw(23) << User.Email << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Phone" << "| " << left << setw(23) << User.Phone << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "User Name" << "| " << left << setw(23) << User.UserName << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Pssword" << "| " << left << setw(23) << User.Password << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Permission " << "| " << left << setw(23) << User.Permissions << "| \n\n";
        cout << "\t\t\t\t\t\t _____________________________________________________\n\n";
    }

    static void PrintClientCard(clsBankClient Client)
    {
        cout << "\n";
        cout << "\t\t\t\t\t\t _____________________________________________________\n\n";
        cout << "\t\t\t\t\t\t                * * * Client Card * * *                 \n";
        cout << "\t\t\t\t\t\t _____________________________________________________\n\n";

        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "First Name" << "| " << left << setw(23) << Client.FirstName << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Last Name" << "| " << left << setw(23) << Client.LastName << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Full Name" << "| " << left << setw(23) << Client.FullName() << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Email" << "| " << left << setw(23) << Client.Email << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Phone" << "| " << left << setw(23) << Client.Phone << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Acc. Number" << "| " << left << setw(23) << Client.AccountNumber() << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Password" << "| " << left << setw(23) << Client.Password << "| \n\n";
        cout << "\t\t\t\t\t\t  | " << left << setw(23) << "Acc. Balance" << "| " << left << setw(23) << Client.AccountBalance << "| \n\n";
        cout << "\t\t\t\t\t\t _____________________________________________________\n\n";
    }
};

