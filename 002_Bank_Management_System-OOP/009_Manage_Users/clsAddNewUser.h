#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"

using namespace std;

class clsAddNewUser : protected clsScreen
{

public:

	static void ShowAddNewUserScreen()
	{
		string Title = "* * * Add New User Screen * * *";
		clsScreen::_DrawScreenHeader(Title);

		cout << "\n";
		string UserName;
		cout << setw(40) << left << "" << "\t Enter User Name: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExists(UserName))
		{
			cout << setw(40) << left << "" << "\t User Already Exists, Enter Another User Name: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUser(UserName);
		clsInputValidate::ReadNewUserInfo(NewUser);

		cout << "\n\n";
		cout << setw(40) << left << "" << "\t Are You Sure You Want to Add This User Y/N: ";

		if (clsInputValidate::CheckAnswer())
		{
			clsUser::enSaveResults SaveResult;
			SaveResult = NewUser.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSuccsseded:
			{
				cout << "\n\n";
				cout << setw(40) << left << "" << "\t User Added Successfully...... \n\n";
				clsOutputValidate::PrintUserCard(NewUser);
				break;
			}

			case clsUser::enSaveResults::svInvalidEmptyObject:
			{
				cout << "\n\n";
				cout << setw(40) << left << "" << "\t Invalid Operation, User Is Empty. \n\n";
				break;
			}

			case clsUser::enSaveResults::svInvalidObjectIsExists:
			{
				cout << "\n\n";
				cout << setw(40) << left << "" << "\t Invalid Operation, User Already Exists. \n\n";
				break;
			}

			case clsUser::enSaveResults::svFailedFileOperation:
			{
				cout << "\n\n";
				cout << setw(40) << left << "" << "\t Failed to Save User Data to File. \n\n";
				break;
			}
			}
		}
		else
		{
			cout << "\n\n";
			cout << setw(40) << left << "" << "\t Operation Is Cancelled......  \n\n";
		}
	}
};
