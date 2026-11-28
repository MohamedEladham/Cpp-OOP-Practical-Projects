#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsAddNewClinet.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransactions.h"
#include "clsManageUsers.h"
#include "clsInputValidate.h"
#include "clsShowClientsListScreen.h"
#include "clsLoginRegisterUsers.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
    enum enMainMenuOption
    {
        eShowClientList = 1, eAddNewClient = 2, eUpdateClient  = 3,
        eDeleteClient   = 4, eFindClient   = 5, eTransactions  = 6,
        eManageUsers    = 7, eLoginRegister = 8, eLogout       = 9
    };

    static short _ReadMainMenuOption()
    {
        short Choose;
        Choose = clsInputValidate::ReadIntNumberBetween(1, 9, "\t\t\t\t\t     > Invalid Choose, Choose What Do You Want To Do [1 To 9]: ");
        return Choose;
    }

    static void _ShowClientMenu()
    {
        clsShowClientsListScreen::ShowClientListScreen();
    }

    static void _AddNewClientMenu()
    {
        clsAddNewClinet::ShowAddNewClientScreen();
    }

    static void _UpdateClientMenu()
    {
        clsUpdateClient::ShowUpdateClientScreen();
    }

    static void _DeleteClientMenu()
    {
        clsDeleteClient::ShowDeleteClientScreen();
    }

    static void _FindClientMenu()
    {
        clsFindClient::ShowFindClientScreen();
    }

    static void _TransactionsMenu()
    {
        clsTransactions::ShowTransactionsScreen();
    }

    static void _ManageUsersMenu()
    {
        clsManageUsers::ShowManageUsersScreen();
    }
    
    static void _LoginRegisterMenu()
    {
        clsLoginRegisterUsers::ShowLoginRegisterUsers();
    }

    static void _LogoutMenu()
    {
        CurrentUser = clsUser::GetEmptyUser(); 
    }

    static void _PerformMainMenuOption(enMainMenuOption OperationType)
    {
        system("cls");

        switch (OperationType)
        {
        case enMainMenuOption::eShowClientList:
        {
            _ShowClientMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eAddNewClient:
        {
            _AddNewClientMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eUpdateClient:
        {
            _UpdateClientMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eDeleteClient:
        {
            _DeleteClientMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eFindClient:
        {
            _FindClientMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eTransactions:
        {
            _TransactionsMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eManageUsers:
        {
            _ManageUsersMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eLoginRegister:
        {
            _LoginRegisterMenu();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOption::eLogout:
        {
            _LogoutMenu();
            break;
        }
        }
    }

    static void _GoBackToMainMenu()
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t    Press Any Key To Go Back Main Menu.....";
        system("Pause >0");
        ShowMainMenu();
    }

public:

    static void ShowMainMenu()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("\t Main Menu");
        cout << "\t\t\t\t\t     =====================================================\n";
        cout << "\t\t\t\t\t                         Main Menu                     \n";
        cout << "\t\t\t\t\t     =====================================================\n";
        cout << "\t\t\t\t\t         1). Show Client List. \n";
        cout << "\t\t\t\t\t         2). Add New Client. \n";
        cout << "\t\t\t\t\t         3). Update Client Info. \n";
        cout << "\t\t\t\t\t         4). Delete Client. \n";
        cout << "\t\t\t\t\t         5). Find Client. \n";
        cout << "\t\t\t\t\t         6). Transactions. \n";
        cout << "\t\t\t\t\t         7). Manage Users. \n";
        cout << "\t\t\t\t\t         8). Login Register. \n";
        cout << "\t\t\t\t\t         9). Logout. \n";
        cout << "\t\t\t\t\t    =====================================================\n";
        cout << "\t\t\t\t\t     > Choose What Do You Want To Do [1 To 9]: ";
        _PerformMainMenuOption((enMainMenuOption)_ReadMainMenuOption());
    }
};
