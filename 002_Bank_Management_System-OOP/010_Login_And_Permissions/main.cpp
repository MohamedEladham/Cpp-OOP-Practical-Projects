#include <iostream>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
using namespace std;

int main()
{
	do
	{
		LoginTrials = 3;
		clsLoginScreen::ShowLoginScreen();

		if (LoginTrials == 0)
		{
			cout << endl;
			cout << setw(40) << left << "" << "\t You Are Locked After 3 Faild Trails. ";
			break;
		}

		cout << "\n\n\n";
		cout << setw(40) << left << "" << "\t Are You Want Login Again Y/N: ";

	} while (clsInputValidate::CheckAnswer2());

	cout << "\n\n\n\n\n";
	return 0;
}