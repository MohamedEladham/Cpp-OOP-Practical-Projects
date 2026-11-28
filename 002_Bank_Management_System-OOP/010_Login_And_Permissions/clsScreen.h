#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n";
        cout << "\t\t\t\t\t  __________________________________________________________ \n\n";
        cout << "\t\t\t\t\t\t\t" << Title << "\n";
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t\t" << SubTitle << "\n";
        }
        cout << "\t\t\t\t\t       _______________________________________________         \n\n";
    }

    static bool CheckPermissionsRight(clsUser::enPermissions Permissions)
    {
        if (CurrentUser.CkeckPermissions(Permissions))
        {
            return true;
        }
        else
        {
            cout << "\n\n";
            cout << setw(40) << left << "" << "___________________________________________________________________________________\n\n";
            cout << setw(40) << left << "" << "                       Access Denied! Contact Your Admin                           \n\n";

            cout << setw(40) << left << "" << "                       User: " << CurrentUser.UserName << endl; \
                cout << setw(40) << left << "" << "                       Date: " << clsDate::DateToString(clsDate::GetSystemDate()) << "\n";
            cout << setw(40) << left << "" << "___________________________________________________________________________________\n\n";
            return false;
        }
    }
};
