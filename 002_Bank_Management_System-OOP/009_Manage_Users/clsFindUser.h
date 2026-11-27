#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsOutputValidate.h"

using namespace std;

class clsFindUser : protected clsScreen
{
public:

	static void ShowFindUserScreen()
	{
		string Title = "* * * Find User Screen * * *";
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
		}
		else
		{
			cout << "\n\n";
			cout << setw(40) << left << "" << "\t User Does Not Exist..... \n\n";
		}
	}
};
