#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n";
        cout << "\t\t\t\t\t  __________________________________________________________ \n\n";
        cout << "\t\t\t\t\t\t\t" << Title << "\n";
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t\t" << SubTitle << "\n";
        }
        cout << "\t\t\t\t\t       _______________________________________________         \n\n";
    }
};
