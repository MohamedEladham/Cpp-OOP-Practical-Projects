#pragma once
#include <iostream>
#include <string>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsers.h"
#include "clsAddNewUser.h"
#include "clsUpdateUser.h"
#include "clsDeleteUser.h"
#include "clsFindUser.h"

using namespace std;

class clsManageUsers : protected clsScreen
{
    enum enManageUsersOptions
    {
        ListUsers  = 1, AddNewUser = 2, UpdateUser = 3,
        DeleteUser = 4, FindUser   = 5, MainMenu   = 6
    };

    static void _ListUsersMenu()
    {
        clsListUsers::ShowListUserScreen();
    }

    static void _AddNewUserMenu()
    {
        clsAddNewUser::ShowAddNewUserScreen();
    }

    static void _UpdateUserMenu()
    {
        clsUpdateUser::ShowUpdateUsersScreen();
    }

    static void _DeleteUserMenu()
    {
        clsDeleteUser::ShowDeleteUsersScreen();
    }

    static void _FindUserMenu()
    {
        clsFindUser::ShowFindUserScreen();
    }

    static void _PerformManageUsersOptions(enManageUsersOptions ManageUsersOptions)
    {
        system("cls");

        switch (ManageUsersOptions)
        {
        case enManageUsersOptions::ListUsers:
        {
            _ListUsersMenu();
            _GoBackToShowManageUsersScreen();
            break;
        }

        case enManageUsersOptions::AddNewUser:
        {
            _AddNewUserMenu();
            _GoBackToShowManageUsersScreen();
            break;
        }

        case enManageUsersOptions::UpdateUser:
        {
            _UpdateUserMenu();
            _GoBackToShowManageUsersScreen();
            break;
        }

        case enManageUsersOptions::DeleteUser:
        {
            _DeleteUserMenu();
            _GoBackToShowManageUsersScreen();
            break;
        }

        case enManageUsersOptions::FindUser:
        {
            _FindUserMenu();
            _GoBackToShowManageUsersScreen();
            break;
        }

        case enManageUsersOptions::MainMenu:
        {

        }
        }
    }

    static void _GoBackToShowManageUsersScreen()
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Press Any Key To Go Back Manage Users Screen......";
        system("Pause >0");
        ShowManageUsersScreen();
    }

public:

    static void ShowManageUsersScreen()
    {
        system("cls");

        string Title = "* * Manage Users Screen * *";
        clsScreen::_DrawScreenHeader(Title);

        cout << "\t\t\t\t\t===============================================================\n";
        cout << "\t\t\t\t\t                     Manage Users Menu                         \n";
        cout << "\t\t\t\t\t===============================================================\n";
        cout << "\t\t\t\t\t   1).List Users. \n";
        cout << "\t\t\t\t\t   2).Add New User. \n";
        cout << "\t\t\t\t\t   3).Update User. \n";
        cout << "\t\t\t\t\t   4).Delete User. \n";
        cout << "\t\t\t\t\t   5).Find User. \n";
        cout << "\t\t\t\t\t   6).Main Menu. \n";
        cout << "\t\t\t\t\t===============================================================\n";
        cout << "\t\t\t\t\t> Choose What Do You Want To Do [1 To 6]: ";

        _PerformManageUsersOptions((enManageUsersOptions)clsInputValidate::ReadIntNumberBetween(1, 6, "\t\t\t\t\t> Choose What Do You Want To Do [1 To 6]: "));
    }
};
