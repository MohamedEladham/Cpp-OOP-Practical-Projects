#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "clsPerson.h"
#include "clsString.h"

#include "clsDate.h"
#include "clsUtility.h"

using namespace std;

const string UsersFile = "Users.txt";
const string LoginReguster = "LoginRegister.txt";

class clsUser : public clsPerson
{
    enum enMode { EmptyMde = 0, UpdateMode = 1, AddNewMode = 3 };

    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkForDelete = false;

    bool _Update()
    {
        vector <clsUser> vUser;
        vUser = _LoadUserDataFromFile();

        for (clsUser& U : vUser)
        {
            if (U._UserName == _UserName)
            {
                U = *this;
                U.Password = clsUtility::EncryptText(this->Password);
                return _SaveUsersDataToFile(vUser);
            }
        }

        return false;
    }

    bool _SaveUsersDataToFile(vector <clsUser>& vUser)
    {
        fstream MyFile;
        MyFile.open(UsersFile, ios::out);

        if (!MyFile.is_open())
            return false;

        string Line;

        for (clsUser& U : vUser)
        {
            if (U._MarkForDelete == false)
            {
                Line = _ConvertUserObjectToLine(U);
                MyFile << Line << endl;

                if (MyFile.fail())
                {
                    MyFile.close();
                    return false;
                }
            }
        }

        MyFile.close();

        return !MyFile.fail();
    }

    string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string Line = "";
        Line += User.FirstName + Seperator;
        Line += User.LastName + Seperator;
        Line += User.Email + Seperator;
        Line += User.Phone + Seperator;
        Line += User.UserName + Seperator;
        Line += User.Password + Seperator;
        
        Line += to_string(User.Permissions);

        return Line;
    }

    bool _AddUserDataToFile(string Line)
    {
        fstream MyFile;
        MyFile.open(UsersFile, ios::out | ios::app);

        if (!MyFile.is_open())
            return false;

        MyFile << Line << endl;

        bool IsSaved = !MyFile.fail();

        MyFile.close();

        return IsSaved && !MyFile.fail();
    }

    bool _AddNew()
    {
        this->Password = clsUtility::EncryptText(this->Password);
        return _AddUserDataToFile(_ConvertUserObjectToLine(*this));
    }

    static clsUser _ConvertLineToUserObject(string S1, string Seperator = "#//#")
    {
        vector <string> vUserData;
        vUserData = clsString::Split(S1, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
    }

    static vector <clsUser> _LoadUserDataFromFile()
    {
        vector <clsUser> vUser;

        fstream MyFile;
        MyFile.open(UsersFile, ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                vUser.push_back(User);
            }

            MyFile.close();
        }

        return vUser;
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMde, "", "", "", "", "", "", 0);
    }


    string _ConvertLoginRegisterToLine(string Seperator = "#//#")
    {
        string Line = "";

        Line += clsDate::DateToString(clsDate()) + " - " + clsDate::DateToStringByHoursMinutsSeconds() + Seperator;
        Line += UserName + Seperator;
        Line += clsUtility::EncryptText(Password) + Seperator;
        Line += to_string(Permissions);

        return Line;
    }

    struct stLoginRegisterRecord;

    static stLoginRegisterRecord _ConvertLoginRegisterToRecord(string S1, string Seperator = "#//#")
    {

        stLoginRegisterRecord LoginRegister;

        vector <string> vS1;
        vS1 = clsString::Split(S1, Seperator);

        LoginRegister.DateTime = vS1[0];
        LoginRegister.UserName = vS1[1];
        LoginRegister.Password = clsUtility::DecryptText(vS1[2]);
        LoginRegister.Permissions = stoi(vS1[3]);

        return LoginRegister;
    }

    static vector <stLoginRegisterRecord> _LoadLoginRegisterRecordFromFile()
    {
        vector <stLoginRegisterRecord> vLoginRegisters;

        fstream MyFile;
        MyFile.open(LoginReguster, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            stLoginRegisterRecord LoginRegister;

            while (getline(MyFile, Line))
            {
                LoginRegister = _ConvertLoginRegisterToRecord(Line);
                vLoginRegisters.push_back(LoginRegister);
            }

            MyFile.close();
        }

        return vLoginRegisters;
    }

   
public:

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }
    

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string GetUserName()
    {
        return _UserName;
    }
    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;


    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;


    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


    static clsUser Find(string UserName)
    {
        vector <clsUser> vUser;
        vUser = _LoadUserDataFromFile();

        for (clsUser& U : vUser)
        {
            if (U._UserName == UserName)
            {
                return U;
            }
        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {
        vector <clsUser> vUser;
        vUser = _LoadUserDataFromFile();

        for (clsUser& U : vUser)
        {
            if (U._UserName == UserName && U._Password == clsUtility::EncryptText(Password))
            {
                return U;
            }
        }

        return _GetEmptyUserObject();
    }


    static clsUser AddNew(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    bool Delete(string UserName)
    {
        vector <clsUser> vUser;
        vUser = _LoadUserDataFromFile();

        for (clsUser& U : vUser)
        {
            if (U.UserName == UserName)
            {
                U._MarkForDelete = true;

                if (_SaveUsersDataToFile(vUser))
                {
                    *this = _GetEmptyUserObject();
                    return true;
                }

                return false;
            }
        }

        return false;
    }

    enum enUserData
    {
        All = -1,
        eFirstName = 1, eLastName = 2, eEmail        = 4,
        ePhone     = 8, ePassword = 16, ePermissions = 32
    };

    enum enPermissions
    {
        eFullAcess = -1,
        eShowClientList = 1, eAddNewClient  = 2, eDeleteClint = 4, eUpdateClient = 8,
        eFindClient     = 16, eTransactions = 32, eManageUser = 64, eShowLoginRegister = 128
    };
    
    enum enSaveResults
    {
        svInvalidEmptyObject = 0,
        svSuccsseded = 1,
        svInvalidObjectIsExists = 2,
        svInvalidObjectIsNotExists = 3,
        svFailedFileOperation = 4
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMde:
        {
            return enSaveResults::svInvalidEmptyObject;
        }

        case enMode::AddNewMode:
        {
            if (IsUserExists(_UserName))
            {
                return enSaveResults::svInvalidObjectIsExists;
            }
            else
            {
                if (_AddNew())
                {
                    _Mode = enMode::UpdateMode;
                    return enSaveResults::svSuccsseded;
                }

                return enSaveResults::svFailedFileOperation; 
            }
        }

        case enMode::UpdateMode:
        {
            if (IsUserExists(_UserName))
            {
                if (_Update())
                    return enSaveResults::svSuccsseded;

                return enSaveResults::svFailedFileOperation; 
            } 
            else
            {
                return enSaveResults::svInvalidObjectIsNotExists;
            }
        }
        }

        return enSaveResults::svInvalidEmptyObject;
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUserDataFromFile();
    }

    static clsUser GetAddNewUser(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static clsUser GetEmptyUser()
    {
        return _GetEmptyUserObject();
    }

    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        return _LoadLoginRegisterRecordFromFile();
    }

   
    static bool IsUserExists(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return User._Mode == enMode::UpdateMode;
    }

    static bool IsUserExists(string UserName, string Password)
    {
        clsUser User = clsUser::Find(UserName, Password);
        return User._Mode == enMode::UpdateMode;
    }

    bool CkeckPermissions(enPermissions Permissions)
    {
        if (_Permissions == enPermissions::eFullAcess)
        {
            return true;
        }

        if ((Permissions & _Permissions) == Permissions)
            return true;
        else
            return false;
    }

    void SaveUsersLoginRegisterToFile()
    {
        fstream MyFile;
        MyFile.open(LoginReguster, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << _ConvertLoginRegisterToLine() << endl;

            MyFile.close();
        }
    }
};

