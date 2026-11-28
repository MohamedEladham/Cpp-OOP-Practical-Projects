#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include "clsString.h"
using namespace std;

class clsDate
{
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{
		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short TotalDays, short Year)
	{
		clsDate Date = ConvertTotalDaysFromBeginningTheYearToDate(TotalDays, Year);

		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	// >
	static void Print(clsDate Date)
	{
		cout << DateToString(Date) << endl;
	}

	void Print()
	{
		Print(*this);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	static string DateToStringByHoursMinutsSeconds()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		return to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsLeapYear(short Year)
	{
		return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumbersOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumbersOfDaysInYear()
	{
		return NumbersOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{
		return NumbersOfDaysInYear(Year) * 24;
	}

	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfMinutesInYear()
	{
		return  NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	// >

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short NumOfDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return (IsLeapYear(Year) && Month == 2) ? Month = 29 : NumOfDays[Month];
	}

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}

	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}

	static int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}

	// >

	static short DayOrderOfWeek(short Day, short Month, short Year)
	{
		int a, m, y, d;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOrderOfWeek()
	{
		return DayOrderOfWeek(_Day, _Month, _Year);
	}

	static string DayShortName(short DayOrderOfWeek)
	{
		string DayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return DayName[DayOrderOfWeek];
	}

	static string DayShortName(short Day, short Month, short Year)
	{
		string DayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return DayName[DayOrderOfWeek(Day, Month, Year)];
	}

	string DayShortName()
	{
		string DayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return DayName[DayOrderOfWeek(_Day, _Month, _Year)];
	}

	static string MonthShortName(short MonthOrderOfYear)
	{
		string MonthName[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return MonthName[MonthOrderOfYear];
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{

		short DaysInMonth = NumberOfDaysInMonth(Month, Year);
		short DayOrder = DayOrderOfWeek(1, Month, Year);
		short Counter = DayOrder;

		cout << "\n\n";
		cout << "   _________________[" << MonthShortName(Month) << "]________________\n\n";

		cout << "   Sun   Mon   Tue   Wed   Thu   Fri   Sat   \n\n";


		for (short i = 1; i <= DayOrder; i++)
		{
			cout << "      ";
		}

		for (short i = 1; i <= DaysInMonth; i++)
		{

			cout << setw(6) << i;

			if (++Counter == 7)
			{
				Counter = 0;
				cout << endl;
			}
		}

		cout << "\n    _______________________________________\n";
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(short Year)
	{
		cout << "\n\n";
		cout << "   _______________________________________\n\n";
		cout << "                 Calendar - " << Year << "\n";
		cout << "   _______________________________________\n\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	// >

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;

		return clsDate(Day, Month, Year);
	}

	static short TotalDaysFromBeginningOfYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}

		return TotalDays + Day;
	}

	short TotalDaysFromBeginningOfYear()
	{
		return TotalDaysFromBeginningOfYear(_Day, _Month, _Year);
	}

	static clsDate ConvertTotalDaysFromBeginningTheYearToDate(short TotalDays, short Year)
	{
		clsDate Date;

		short Day;
		short Month = 1;

		while (true)
		{
			short DaysInMonth = NumberOfDaysInMonth(Month, Year);

			if (TotalDays > DaysInMonth)
			{
				TotalDays -= DaysInMonth;

				if (Month == 12)
				{
					Month = 1;
					Year++;
				}
				else
				{
					Month++;
				}
			}
			else
			{
				Day = TotalDays;
				break;
			}
		}

		Date.Day = Day, Date.Month = Month, Date.Year = Year;

		return Date;
	}

	static clsDate DateAfterAddedDays(clsDate Date, int AddedDays)
	{
		while (AddedDays > 0)
		{
			short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

			if (Date.Day == DaysInMonth)
			{
				if (Date.Month == 12)
				{
					Date.Day = 1;
					Date.Month = 1;
					Date.Year++;
				}
				else
				{
					Date.Day = 1;
					Date.Month++;
				}
			}
			else
			{
				Date.Day++;
			}

			AddedDays--;
		}

		return Date;
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ? true : (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day) ? true : false;
	}

	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	}

	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
	}

	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static clsDate IncreaseDateByOneDay(clsDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int DaysDifference = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Date1 = IncreaseDateByOneDay(Date1);
			DaysDifference++;
		}

		return IncludeEndDay ? ++DaysDifference * SwapFlagValue : DaysDifference * SwapFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), IncludeEndDay);
	}

	static clsDate IncreaseDateByXDays(clsDate& Date, short xDays)
	{
		for (short i = 1; i <= xDays; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByXDays(short xDays)
	{
		*this = IncreaseDateByXDays(*this, xDays);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{
		const short Week = 7;

		for (short i = 1; i <= Week; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate& Date, short xWeeks)
	{
		for (short i = 1; i <= xWeeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void IncreaseDateByXWeeks(short xWeeks)
	{
		*this = IncreaseDateByXWeeks(*this, xWeeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			Date.Day = DaysInMonth;

		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonth(clsDate& Date, short xMonth)
	{
		for (short i = 1; i <= xMonth; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void IncreaseDateByXMonth(short xMonth)
	{
		*this = IncreaseDateByXMonth(*this, xMonth);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date.Year++;

		short DaysOfMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysOfMonth)
		{
			Date.Day = DaysOfMonth;
		}

		return Date;
	}

	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYear(clsDate& Date, short xYear)
	{
		Date.Year += xYear;

		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			Date.Day = DaysInMonth;

		return Date;
	}

	void IncreaseDateByXYear(short xYear)
	{
		*this = IncreaseDateByXYear(*this, xYear);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		const short Decade = 10;
		Date.Year += Decade;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecade(clsDate& Date, short xDecade)
	{
		Date.Year += xDecade * 10;
		return Date;
	}

	void IncreaseDateByXDecade(short xDecade)
	{
		*this = IncreaseDateByXDecade(*this, xDecade);
	}

	static clsDate IncreaseOneCentury(clsDate& Date)
	{
		const short Century = 100;
		Date.Year += Century;
		return Date;
	}

	void IncreaseOneCentury()
	{
		*this = IncreaseOneCentury(*this);
	}

	static clsDate IncreaseOneMillennium(clsDate& Date)
	{
		const short Millennium = 1000;
		Date.Year += Millennium;
		return Date;
	}

	void IncreaseOneMillennium()
	{
		*this = IncreaseOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDay(clsDate& Date, short xDays)
	{
		for (short i = 1; i <= xDays; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByXDay(short xDays)
	{
		*this = DecreaseDateByXDay(*this, xDays);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeek(clsDate& Date, short xWeek)
	{
		for (short i = 1; i <= xWeek; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeek(short xWeek)
	{
		*this = DecreaseDateByXWeek(*this, xWeek);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			Date.Day = DaysInMonth;

		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonth(clsDate& Date, short xMonth)
	{
		for (short i = 1; i <= xMonth; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonth(short xMonth)
	{
		*this = DecreaseDateByXMonth(*this, xMonth);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date.Year--;

		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			Date.Day = DaysInMonth;

		return Date;
	}

	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYear(clsDate& Date, short xYear)
	{
		for (short i = 1; i <= xYear; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	void DecreaseDateByXYear(short xYear)
	{
		*this = DecreaseDateByXYear(*this, xYear);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		for (short i = 1; i <= 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate& Date, short xDecades)
	{
		for (short i = 1; i <= xDecades; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}

		return Date;
	}

	void DecreaseDateByXDecades(short xDecades)
	{
		DecreaseDateByXDecades(*this, xDecades);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		for (short i = 1; i <= 100; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		for (short i = 1; i <= 1000; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	enum enHolidays { FriDays = 5, SatrDay = 6 };

	static bool IsEndOfWeek(clsDate Date)
	{
		return (enHolidays)DayOrderOfWeek(Date.Day, Date.Month, Date.Year) == enHolidays::SatrDay;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		return (enHolidays)DayOrderOfWeek(Date.Day, Date.Month, Date.Year) == enHolidays::FriDays ||
			DayOrderOfWeek(Date.Day, Date.Month, Date.Year) == enHolidays::SatrDay;
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DayUntilEndOfWeek(clsDate Date)
	{
		return 6 - DayOrderOfWeek(Date.Day, Date.Month, Date.Year);
	}

	short DayUntilEndOfWeek()
	{
		return DayUntilEndOfWeek(*this);
	}

	static short DayUntilEndOfMonth(clsDate Date)
	{
		return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day + 1; // 1 = End Day
	}

	short DayUntilEndOfMonth()
	{
		return DayUntilEndOfMonth(*this);
	}

	static short DayUntilEndOfYear(clsDate Date)
	{
		short TotalDays = 0;

		for (short i = Date.Month; i <= 12; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Date.Year);
		}

		return TotalDays - Date.Day + 1; // 1 = End Day
	}

	short DayUntilEndOfYear()
	{
		return DayUntilEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
			{
				Days++;
			}

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return Days;
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	enum enCompareDate { Before = -1, Equal = 0, After = 1 };

	static enCompareDate CompareDate(clsDate Date1, clsDate Date2)
	{
		return IsDate1BeforeDate2(Date1, Date2) ? enCompareDate::Before : IsDate1EqualDate2(Date1, Date2) ? enCompareDate::Equal : enCompareDate::After;
	}

	enCompareDate CompareDate(clsDate Date2)
	{
		return CompareDate(*this, Date2);
	}

	static bool IsValidDay(clsDate Date)
	{
		return Date.Day >= 1 && Date.Day <= NumberOfDaysInMonth(Date.Month, Date.Year);
	}

	bool IsValidDay()
	{
		return IsValidDay(*this);
	}

	static bool IsValidMonth(short Month)
	{
		return Month >= 1 && Month <= 12;
	}

	bool IsValidMonth()
	{
		return IsValidMonth(_Month);
	}

	static bool IsValidYear(short Year)
	{
		return Year >= 1900;
	}

	bool IsValidYear()
	{
		return IsValidYear(_Year);
	}

	static bool IsValidDate(clsDate Date)
	{
		return IsValidDay(Date) && IsValidMonth(Date.Month) && IsValidYear(Date.Year);
	}

	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static clsDate ConvertStringDateToDate(string S1)
	{
		clsDate Date;

		vector <string> vS1;
		vS1 = clsString::Split(S1, "/");

		Date.Day = stoi(vS1[0]);
		Date.Month = stoi(vS1[1]);
		Date.Year = stoi(vS1[2]);

		return clsDate(Date.Day, Date.Month, Date.Year);
	}

	static string FormattingDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = clsString::ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = clsString::ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = clsString::ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;
	}
};