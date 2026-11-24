
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "clsPerson.h"
#include "clsString.h"
using namespace std;

const string ClientsFile = "Clients.txt";

class clsBankClient : public clsPerson
{

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _AccountNumber;
    string _Password;
    float _AccountBalance;

    string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {
        string Line = "";

        Line += Client.FirstName + Separator;
        Line += Client.LastName + Separator;
        Line += Client.Email + Separator;
        Line += Client.Phone + Separator;
        Line += Client.AccountNumber() + Separator;
        Line += Client.Password + Separator;
        Line += to_string(Client.AccountBalance);

        return Line;
    }

    void _SaveClientsDataToFile(vector <clsBankClient> vClient)
    {
        fstream MyFile;
        MyFile.open(ClientsFile, ios::out);

        if (MyFile.is_open())
        {
            string Line;

            for (clsBankClient& C : vClient)
            {
                Line = _ConvertClientObjectToLine(C);

                MyFile << Line << endl;
            }

            MyFile.close();
        }
    }

    vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClient;

        fstream MyFile;
        MyFile.open(ClientsFile, ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                vClient.push_back(Client);
            }

            MyFile.close();
        }

        return vClient;
    }

    static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _Update()
    {
        vector <clsBankClient> _vClient;
        _vClient = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClient)
        {
            if (C._AccountNumber == _AccountNumber)
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDataToFile(_vClient);
    }


public:

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string Password, float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _Password = Password;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return _Mode == enMode::EmptyMode;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }
    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _Password;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }

    enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;

        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
        }
    }

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open(ClientsFile, ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client._AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open(ClientsFile, ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client._AccountNumber == AccountNumber && Client._Password == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        return !Client.IsEmpty();
    }
};
