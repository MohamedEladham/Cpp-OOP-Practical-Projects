#pragma once
#include <iostream>
#include <string>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositOperations.h"
#include "clsWithdrawOperations.h"
#include "clsTotalBalances.h"
#include "clsShowClientsListScreen.h"

using namespace std;

class clsTransactions : protected clsScreen
{
    enum enTransactionMenuOptions
    {
        ShowClientList = 1,
        Deposit = 2,
        Withdraw = 3,
        TotalBalances = 4,
        MainMenu = 5
    };

    static void _ShowClientListScreen()
    {
        clsShowClientsListScreen::ShowClientListScreen();
    }

    static void _DepositMenuScreen()
    {
        clsDepositOperations::ShowDepositMenuScreen();
    }

    static void _WithdrawMenuScreen()
    {
        clsWithdrawOperations::ShowWithdrawMenuScreen();
    }

    static void _TotalBalancesMenuScreen()
    {
        clsTotalBalances::ShowTotalBalancesMenuScreen();
    }

    static void _PerformTransactionsMenuOptions(enTransactionMenuOptions TransactionMenu)
    {
        system("cls");

        switch (TransactionMenu)
        {
        case enTransactionMenuOptions::ShowClientList:
        {
            _ShowClientListScreen();
            _GoBackToShowTransactionsScreen();
            break;
        }

        case enTransactionMenuOptions::Deposit:
        {
            _DepositMenuScreen();
            _GoBackToShowTransactionsScreen();
            break;
        }

        case enTransactionMenuOptions::Withdraw:
        {
            _WithdrawMenuScreen();
            _GoBackToShowTransactionsScreen();
            break;
        }

        case enTransactionMenuOptions::TotalBalances:
        {
            _TotalBalancesMenuScreen();
            _GoBackToShowTransactionsScreen();
            break;
        }

        case enTransactionMenuOptions::MainMenu:
        {

        }
        }
    }

    static void _GoBackToShowTransactionsScreen()
    {
        cout << "\n\n";
        cout << "\t\t\t\t\t Press Any Key To Go Back Transactions Menu.....\n";
        system("Pause >0");
        ShowTransactionsScreen();
    }

public:

    static void ShowTransactionsScreen()
    {
        system("cls");

        string Title = "* * * Transactions Screen * * *";
        clsScreen::_DrawScreenHeader(Title);

        cout << "\t\t\t\t\t===============================================================\n";
        cout << "\t\t\t\t\t                       Transactions Menu                       \n";
        cout << "\t\t\t\t\t===============================================================\n";
        cout << "\t\t\t\t\t   1).Show Client List. \n";
        cout << "\t\t\t\t\t   2).Deposit. \n";
        cout << "\t\t\t\t\t   3).Withdraw. \n";
        cout << "\t\t\t\t\t   4).Total Balances. \n";
        cout << "\t\t\t\t\t   5).Main Menu. \n";
        cout << "\t\t\t\t\t===============================================================\n";
        cout << "\t\t\t\t\t> Choose What Do You Want To Do [1 To 5]: ";

        _PerformTransactionsMenuOptions(
            (enTransactionMenuOptions)clsInputValidate::ReadIntNumberBetween(
                1, 5,
                "\t\t\t\t\t> Invalid Operation, Choose What Do You Want To Do [1 To 5]: "
            )
        );
    }
};

