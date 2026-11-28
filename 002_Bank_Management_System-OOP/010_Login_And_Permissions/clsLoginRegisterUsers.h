#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsLoginRegisterUsers : protected clsScreen
{
    static void _PrintLoginRegiserList(clsUser::stLoginRegisterRecord LoginRegisters)
    {
        cout << setw(15) << left << "";
        cout << "| " << setw(35) << left << LoginRegisters.DateTime;
        cout << "| " << setw(20) << left << LoginRegisters.UserName;
        cout << "| " << setw(25) << left << LoginRegisters.Password;
        cout << "| " << setw(20) << left << LoginRegisters.Permissions;
    }

public:

    static void ShowLoginRegisterUsers()
    {
        if (!clsScreen::CheckPermissionsRight(clsUser::enPermissions::eShowLoginRegister))
            return;

        vector <clsUser::stLoginRegisterRecord> vLoginRegister = clsUser::GetLoginRegisterList();

        string Title = "* * * Login Register Screen * * *";
        string SubTitle = " [" + to_string(vLoginRegister.size()) + "] Record(s). ";

        clsScreen::_DrawScreenHeader(Title, SubTitle);


        cout << setw(15) << left << "" << "________________________________________________________________________________________________________________\n\n";
        cout << setw(15) << left << "";
        cout << "| " << setw(35) << left << "Date - Time";
        cout << "| " << setw(20) << left << "UserName";
        cout << "| " << setw(25) << left << "Password";
        cout << "| " << setw(20) << left << "Permissions" << endl;
        cout << setw(15) << left << "" << "________________________________________________________________________________________________________________\n\n";

        for (clsUser::stLoginRegisterRecord& Record : vLoginRegister)
        {
            _PrintLoginRegiserList(Record);
            cout << endl;
        }

        cout << "\n";
        cout << setw(15) << left << "" << "________________________________________________________________________________________________________________\n\n";
    }
};

