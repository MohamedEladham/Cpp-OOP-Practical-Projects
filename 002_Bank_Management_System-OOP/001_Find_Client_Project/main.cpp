#include <iostream>
#include "clsBankClient.h"
using namespace std;

int main()
{
    // >>
    // Find Client By Account Number
    cout << "\nFind Client By Account Number:";
    
    clsBankClient Client1 = clsBankClient::Find("A101");

    if (!Client1.IsEmpty())
    {
        Client1.Print();
    }
    else
    {
        cout << "\nClient Not Found!";
    }


    
    // >>
    // Find Client By Account Number And Pin Code
    cout << "\n\nFind Client By Account Number And Pin Code:";
    
    clsBankClient Client2 = clsBankClient::Find("A101", "1234");

    if (!Client2.IsEmpty())
    {
        Client2.Print();
    }
    else
    {
        cout << "\nClient Not Found!";
    }


    
    // >>
    // Check If Client Exists
    cout << "\n\nCheck If Client Exists:";
    
    if (clsBankClient::IsClientExist("A101"))
    {
        cout << "\nClient Exists.";
    }
    else
    {
        cout << "\nClient Does Not Exist.";
    }



    // >>
    // Display Client Account Information
    cout << "\n\nDisplay Client Account Information:";

    if (!Client1.IsEmpty())
    {
        cout << "\nAccount Number : " << Client1.AccountNumber();
        cout << "\nPin Code       : " << Client1.PinCode;
        cout << "\nAccount Balance: " << Client1.AccountBalance;
    }

    return 0;
}
