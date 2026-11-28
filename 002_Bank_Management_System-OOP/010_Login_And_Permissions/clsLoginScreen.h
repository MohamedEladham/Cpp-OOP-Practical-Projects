#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
	static void _Login()
	{
		system("Cls");

		string Title = "* * * Login Screen * * *";
		clsScreen::_DrawScreenHeader(Title);

		bool IsLoginValid = false;

		do
		{
			string UserName, Password;

			if (!IsLoginValid && LoginTrials < 3)
			{
				cout << "\n\n";
				cout << setw(40) << left << ""
					<< "\t Invalid UserName/Password. \n";

				cout << setw(40) << left << ""
					<< "\t You Have " << LoginTrials
					<< " Trials To Login. \n\n";
			}

			if (LoginTrials == 0)
			{
				return;
			}

			cout << setw(40) << left << ""
				<< "\t Enter User Name: ";
			UserName = clsInputValidate::ReadString();
			

			cout << setw(40) << left << ""
				<< "\t Enter Password: ";

			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			IsLoginValid = CurrentUser.IsUserExists(UserName, Password);

			if (!IsLoginValid)
			{
				LoginTrials--;
			}

		} while (!IsLoginValid);

		CurrentUser.SaveUsersLoginRegisterToFile();

		clsMainScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen()
	{
		_Login();
	}
};
