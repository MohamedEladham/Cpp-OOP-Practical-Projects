#pragma once
#include<iostream>
#include "clsDate.h"
using namespace std;

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        return !(clsDate::CompareDate(Period2.EndDate, Period1.StartDate) == clsDate::enCompareDate::Before ||
            clsDate::CompareDate(Period2.StartDate, Period1.EndDate) == clsDate::enCompareDate::After);
    }

    static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
    {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
    }

    static bool IsDateWithinPeriod(clsDate Date, clsPeriod Period)
    {
        return !(clsDate::CompareDate(Date, Period.StartDate) == clsDate::enCompareDate::Before || clsDate::CompareDate(Date, Period.EndDate) == clsDate::enCompareDate::After);
    }

    bool IsDateWithinPeriod(clsPeriod Period)
    {
        return IsDateWithinPeriod(StartDate, Period) &&
            IsDateWithinPeriod(EndDate, Period);
    }

    bool IsOverlapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();

        cout << "Period End: ";
        EndDate.Print();
    }
};
