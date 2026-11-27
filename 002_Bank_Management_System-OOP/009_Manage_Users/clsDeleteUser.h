#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"

using namespace std;

class clsDeleteUser : protected clsScreen
{

public:

	static void ShowDeleteUsersScreen()
	{
		string Title = "* * * Delete Users Screen * * *";
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

			cout << "\n";

			cout << setw(40) << left << "" << "\t Are You Sure You Want to Delete This User Y/N: ";

			if (clsInputValidate::CheckAnswer())
			{
				if (User.Delete(UserName))
				{
					cout << "\n\n";
					cout << setw(40) << left << "" << "\t Deleted Successfully..... \n\n";
				}
				else
				{
					cout << "\n\n";
					cout << setw(40) << left << "" << "\t Failed to Delete User Data. Please Try Again..... \n\n";
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
