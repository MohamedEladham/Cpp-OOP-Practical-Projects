
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"

using namespace std;

class clsUpdateUser : protected clsScreen
{

public:

	static void ShowUpdateUsersScreen()
	{
		string Title = "* * * Update Users Screen * * *";
		clsScreen::_DrawScreenHeader(Title);

		cout << "\n";

		string UserName;
		cout << setw(40) << left << "" << "\t Enter User Name: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		UserName = clsInputValidate::ReadString();

		if (clsUser::IsUserExists(UserName))
		{
			clsUser User = clsUser::Find(UserName);
			clsOutputValidate::PrintUserCard(User);

			clsInputValidate::ReadNewUserInfo(User);

			cout << "\n";

			cout << setw(40) << left << "" << "\t Are You Sure You Want to Update This User Y/N: ";

			if (clsInputValidate::CheckAnswer())
			{
				clsUser::enSaveResults SaveResult;
				SaveResult = User.Save();

				switch (SaveResult)
				{
					case clsUser::enSaveResults::svSuccsseded:
					{
						cout << "\n\n";
						cout << setw(40) << left << "" << "\t User Updated Successfully...... \n\n";
						User = clsUser::Find(UserName);
						clsOutputValidate::PrintUserCard(User);
						break;
					}

					case clsUser::enSaveResults::svFailedFileOperation:
					{
						cout << "\n\n";
						cout << setw(40) << left << "" << "\t Failed to Update User Data in File. \n\n";
						break;
					}

					case clsUser::enSaveResults::svInvalidObjectIsNotExists:
					{
						cout << "\n\n";
						cout << setw(40) << left << "" << "\t Invalid Operation, User Does Not Exist.... \n\n";
						break;
					}
				}
			}
			else
			{
				cout << "\n\n";
				cout << setw(40) << left << "" << "\t Operation Is Cancelled..... \n\n";
			}
		}
		else
		{
			cout << "\n\n";
			cout << setw(40) << left << "" << "\t User Does Not Exist..... \n\n";
		}
	}
};

