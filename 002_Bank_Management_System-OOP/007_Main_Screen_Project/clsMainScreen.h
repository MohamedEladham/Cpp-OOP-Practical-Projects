
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsAddNewClinet.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsInputValidate.h"
#include "clsShowClientsListScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
    enum enMainMenuOption
    {
        eShowClientList = 1, eAddNewClient = 2, eUpdateClient  = 3,
        eDeleteClient   = 4, eFindClient   = 5, eTotalBalances = 6,
        eTransactions = 7, eManageUsers = 8, eLogout = 9
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

    static void _TotalBalancesMenu()
    {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t\t\t Total Balances Screen Will Show Here.... \n";
    }

    static void _TransactionsMenu()
    {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t\t\t Transactions Menu Will Show Here.... \n";
    }

    static void _ManageUsersMenu()
    {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t\t\t Manage Users Will Show Here.... \n";
    }

    static void _LogoutMenu()
    {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t\t\t Logout Will Show Here.... \n";
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

        case enMainMenuOption::eTotalBalances:
        {
            _TotalBalancesMenu();
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

        case enMainMenuOption::eLogout:
        {
            _LogoutMenu();
            _GoBackToMainMenu();
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
        cout << "\t\t\t\t\t         6). Total Balances. \n";
        cout << "\t\t\t\t\t         7). Transactions. \n";
        cout << "\t\t\t\t\t         8). Manage Users. \n";
        cout << "\t\t\t\t\t         9). Logout. \n";
        cout << "\t\t\t\t\t    =====================================================\n";
        cout << "\t\t\t\t\t     > Choose What Do You Want To Do [1 To 9]: ";
        _PerformMainMenuOption((enMainMenuOption)_ReadMainMenuOption());
    }
};
