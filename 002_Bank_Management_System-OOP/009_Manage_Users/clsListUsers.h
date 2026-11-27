#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsListUsers : protected clsScreen
{
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(18) << left << "";
        cout << "| " << left << setw(15) << User.UserName;
        cout << "| " << left << setw(23) << User.FullName();
        cout << "| " << left << setw(17) << User.Phone;
        cout << "| " << left << setw(22) << User.Email;
        cout << "| " << left << setw(15) << User.Password;
        cout << "| " << left << setw(10) << User.Permissions;
    }

public:

    static void ShowListUserScreen()
    {
        vector <clsUser> vUser;
        vUser = clsUser::GetUsersList();

        string Title = "* * * List User Screen * * *";
        string SubTitle = "\t [" + to_string(vUser.size()) + "] User(s). ";
        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(18) << left << "" << "____________________________________________________________________________________________________________________\n\n";
        cout << setw(18) << left << "";

        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(23) << "Full Name";
        cout << "| " << left << setw(17) << "Phone";
        cout << "| " << left << setw(22) << "Email";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(10) << "Permission" << endl;

        cout << setw(18) << left << "" << "____________________________________________________________________________________________________________________\n\n";

        for (clsUser& U : vUser)
        {
            _PrintUserRecordLine(U);
            cout << endl;
        }

        cout << setw(18) << left << "" << "______________________________________________________________________________________________________________________\n\n";
    }
};
