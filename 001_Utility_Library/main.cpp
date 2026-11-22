#include <iostream>
#include <vector>
#include <string>
#include "clsDate.h"
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtility.h"
using namespace std;

int main()
{
    cout << "\n\n==================== clsDate Library ====================\n\n";

    // >>
    // Create dates using different constructors.
    clsUtility::Srand();

    clsDate Date1;
    clsDate Date2("15/5/2022");
    clsDate Date3(20, 6, 2023);
    clsDate Date4(100, 2024);

    cout << "Default Constructor: " << Date1.DateToString() << endl;
    cout << "String Constructor: " << Date2.DateToString() << endl;
    cout << "Day, Month, Year Constructor: " << Date3.DateToString() << endl;
    cout << "Total Days Constructor: " << Date4.DateToString() << endl;


    
    // >>
    // Display date properties and format dates.
    cout << "\nDate Properties:\n";
    cout << "Day: " << Date2.Day << endl;
    cout << "Month: " << Date2.Month << endl;
    cout << "Year: " << Date2.Year << endl;

    cout << "Date To String: " << Date2.DateToString() << endl;
    cout << "Formatted Date: " << clsDate::FormattingDate(Date2, "dd/mm/yyyy") << endl;
    cout << "Another Format: " << clsDate::FormattingDate(Date2, "yyyy-mm-dd") << endl;



    // >>
    // Check leap year and calculate year information.
    cout << "\nYear Information:\n";
    cout << "Is Leap Year: " << clsDate::IsLeapYear(2024) << endl;
    cout << "Days In Year: " << clsDate::NumbersOfDaysInYear(2024) << endl;
    cout << "Hours In Year: " << clsDate::NumberOfHoursInYear(2024) << endl;
    cout << "Minutes In Year: " << clsDate::NumberOfMinutesInYear(2024) << endl;
    cout << "Seconds In Year: " << clsDate::NumberOfSecondsInYear(2024) << endl;

    cout << "Object Is Leap Year: " << Date2.IsLeapYear() << endl;
    cout << "Object Days In Year: " << Date2.NumbersOfDaysInYear() << endl;



    // >>
    // Calculate month information.
    cout << "\nMonth Information:\n";
    cout << "Days In February 2024: " << clsDate::NumberOfDaysInMonth(2, 2024) << endl;
    cout << "Hours In Month: " << clsDate::NumberOfHoursInMonth(2, 2024) << endl;
    cout << "Minutes In Month: " << clsDate::NumberOfMinutesInMonth(2, 2024) << endl;
    cout << "Seconds In Month: " << clsDate::NumberOfSecondsInMonth(2, 2024) << endl;
    cout << "Object Days In Month: " << Date2.NumberOfDaysInMonth() << endl;



    // >>
    // Get day and month names.
    cout << "\nDate Names:\n";
    cout << "Day Order: " << clsDate::DayOrderOfWeek(15, 5, 2022) << endl;
    cout << "Day Name: " << clsDate::DayShortName(15, 5, 2022) << endl;
    cout << "Object Day Name: " << Date2.DayShortName() << endl;
    cout << "Month Name: " << clsDate::MonthShortName(5) << endl;
    cout << "Object Month Name: " << Date2.MonthShortName() << endl;



    // >>
    // Print month and year calendars.
    cout << "\nCalendar Examples:\n";
    clsDate::PrintMonthCalendar(5, 2022);
    clsDate::PrintYearCalendar(2024);



    // >>
    // Get system date and calculate total days from the beginning of the year.
    clsDate SystemDate = clsDate::GetSystemDate();

    cout << "\nSystem Date: " << SystemDate.DateToString() << endl;
    cout << "Total Days From Beginning Of Year: " << Date2.TotalDaysFromBeginningOfYear() << endl;

    cout << "Total Days Static: "
        << clsDate::TotalDaysFromBeginningOfYear(15, 5, 2022) << endl;

    cout << "Convert Total Days To Date: "
        << clsDate::ConvertTotalDaysFromBeginningTheYearToDate(100, 2024).DateToString() << endl;



    //>>
    // Add days to a date.
    clsDate DateAfterDays(1, 1, 2024);

    cout << "\nDate After Adding Days:\n";
    cout << "Original Date: " << DateAfterDays.DateToString() << endl;

    DateAfterDays = clsDate::DateAfterAddedDays(DateAfterDays, 40);

    cout << "After Adding 40 Days: " << DateAfterDays.DateToString() << endl;



    // >>
    // Compare two dates.
    clsDate CompareDate1(10, 5, 2022);
    clsDate CompareDate2(15, 5, 2022);

    cout << "\nDate Comparison:\n";
    cout << "Date 1 Before Date 2: " << clsDate::IsDate1BeforeDate2(CompareDate1, CompareDate2) << endl;
    cout << "Date 1 Equal Date 2: " << clsDate::IsDate1EqualDate2(CompareDate1, CompareDate2) << endl;
    cout << "Date 1 After Date 2: " << clsDate::IsDate1AfterDate2(CompareDate1, CompareDate2) << endl;

    cout << "Compare Date Result: " << clsDate::CompareDate(CompareDate1, CompareDate2) << endl;
    cout << "Object Compare Result: " << CompareDate1.CompareDate(CompareDate2) << endl;



    // >>
    // Check last day and last month.
    clsDate LastDayDate(31, 12, 2024);

    cout << "\nLast Day And Month:\n";
    cout << "Is Last Day In Month: " << LastDayDate.IsLastDayInMonth() << endl;
    cout << "Is Last Month In Year: " << LastDayDate.IsLastMonthInYear() << endl;



    // >>
    // Increase dates by different time periods.
    cout << "\nIncrease Date Operations:\n";

    clsDate IncreaseDate(1, 1, 2024);

    cout << "Original Date: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByOneDay();
    cout << "After One Day: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByXDays(10);
    cout << "After 10 Days: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByOneWeek();
    cout << "After One Week: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByXWeeks(2);
    cout << "After 2 Weeks: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByOneMonth();
    cout << "After One Month: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByXMonth(2);
    cout << "After 2 Months: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByOneYear();
    cout << "After One Year: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByXYear(2);
    cout << "After 2 Years: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByOneDecade();
    cout << "After One Decade: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseDateByXDecade(2);
    cout << "After 2 Decades: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseOneCentury();
    cout << "After One Century: " << IncreaseDate.DateToString() << endl;

    IncreaseDate.IncreaseOneMillennium();
    cout << "After One Millennium: " << IncreaseDate.DateToString() << endl;


    

    // >>
    // Decrease dates by different time periods.
    cout << "\nDecrease Date Operations:\n";

    clsDate DecreaseDate(1, 1, 2025);

    cout << "Original Date: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByOneDay();
    cout << "After One Day: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByXDay(10);
    cout << "After 10 Days: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByOneWeek();
    cout << "After One Week: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByXWeek(2);
    cout << "After 2 Weeks: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByOneMonth();
    cout << "After One Month: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByXMonth(2);
    cout << "After 2 Months: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByOneYear();
    cout << "After One Year: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByXYear(2);
    cout << "After 2 Years: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByOneDecade();
    cout << "After One Decade: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByXDecades(2);
    cout << "After 2 Decades: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByOneCentury();
    cout << "After One Century: " << DecreaseDate.DateToString() << endl;

    DecreaseDate.DecreaseDateByOneMillennium();
    cout << "After One Millennium: " << DecreaseDate.DateToString() << endl;



    // >>
    // Swap two dates.
    clsDate SwapDate1(1, 1, 2022);
    clsDate SwapDate2(30, 12, 2022);

    cout << "\nBefore Swap: " << SwapDate1.DateToString() << " - " << SwapDate2.DateToString() << endl;

    clsDate::SwapDates(SwapDate1, SwapDate2);

    cout << "After Swap: " << SwapDate1.DateToString() << " - " << SwapDate2.DateToString() << endl;


    
    
    // >>
    // Calculate difference between two dates and calculate age in days.
    clsDate DifferenceDate1(1, 1, 2022);
    clsDate DifferenceDate2(10, 1, 2022);

    cout << "\nDate Difference:\n";
    cout << "Difference Without End Day: "
        << clsDate::GetDifferenceInDays(DifferenceDate1, DifferenceDate2) << endl;

    cout << "Difference With End Day: "
        << clsDate::GetDifferenceInDays(DifferenceDate1, DifferenceDate2, true) << endl;

    cout << "Object Difference: "
        << DifferenceDate1.GetDifferenceInDays(DifferenceDate2) << endl;

    cout << "Age In Days: "
        << clsDate::CalculateMyAgeInDays(clsDate(1, 1, 2000)) << endl;


    
    
    // >>
    // Check weekend, business day and remaining days.
    cout << "\nDay Information:\n";

    clsDate DayInfo(15, 5, 2022);

    cout << "Is End Of Week: " << DayInfo.IsEndOfWeek() << endl;
    cout << "Is Week End: " << DayInfo.IsWeekEnd() << endl;
    cout << "Is Business Day: " << DayInfo.IsBusinessDay() << endl;

    cout << "Days Until End Of Week: " << DayInfo.DayUntilEndOfWeek() << endl;
    cout << "Days Until End Of Month: " << DayInfo.DayUntilEndOfMonth() << endl;
    cout << "Days Until End Of Year: " << DayInfo.DayUntilEndOfYear() << endl;

    cout << "Business Days: "
        << clsDate::CalcualteBusinessDays(clsDate(1, 1, 2024), clsDate(10, 1, 2024)) << endl;

    cout << "Vacation Days: "
        << clsDate::CalcualteVacationDays(clsDate(1, 1, 2024), clsDate(10, 1, 2024)) << endl;


    
    
    // >>
    // Validate dates.
    cout << "\nDate Validation:\n";

    clsDate ValidDate(15, 5, 2022);

    cout << "Is Valid Day: " << ValidDate.IsValidDay() << endl;
    cout << "Is Valid Month: " << ValidDate.IsValidMonth() << endl;
    cout << "Is Valid Year: " << ValidDate.IsValidYear() << endl;
    cout << "Is Valid Date: " << ValidDate.IsValidDate() << endl;

    cout << "Convert String To Date: "
        << clsDate::ConvertStringDateToDate("25/12/2024").DateToString() << endl;



    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


    
    
    cout << "\n\n==================== clsPeriod Library ====================\n\n";


    // >>
    // Create two periods and print their dates.
    clsPeriod Period1(clsDate(1, 1, 2024), clsDate(10, 1, 2024));
    clsPeriod Period2(clsDate(5, 1, 2024), clsDate(15, 1, 2024));

    cout << "Period 1:\n";
    Period1.Print();

    cout << "\nPeriod 2:\n";
    Period2.Print();


    

    // >>
    // Calculate period length in days.
    cout << "\nPeriod Length:\n";
    cout << "Period 1 Length Without End Day: "
        << clsPeriod::PeriodLengthInDays(Period1) << endl;

    cout << "Period 1 Length With End Day: "
        << clsPeriod::PeriodLengthInDays(Period1, true) << endl;


    
    
    
    // >>
    // Check whether two periods overlap.
    cout << "\nPeriods Overlap:\n";
    cout << "Static Method: " << clsPeriod::IsOverlapPeriods(Period1, Period2) << endl;
    cout << "Object Method: " << Period1.IsOverlapWith(Period2) << endl;


    
    
    // >>
    // Check whether a date is within a period.
    cout << "\nDate Within Period:\n";

    clsDate CheckDate(7, 1, 2024);

    cout << "Check Date: " << CheckDate.DateToString() << endl;
    cout << "Is Date Within Period 1: "
        << clsPeriod::IsDateWithinPeriod(CheckDate, Period1) << endl;




    // >>
    // Check whether one period is completely within another period.
    clsPeriod InnerPeriod(clsDate(3, 1, 2024), clsDate(8, 1, 2024));

    cout << "\nIs Inner Period Within Period 1: "
        << Period1.IsDateWithinPeriod(InnerPeriod) << endl;



    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



    cout << "\n\n==================== clsString Library ====================\n\n";




    // >>
    // Create string objects and access their values.
    clsString String1("Hello World From C++");

    cout << "Original String: " << String1.Value << endl;
    cout << "String Length: " << String1.Length() << endl;
    cout << "Static Length: " << clsString::Length("Hello World") << endl;
    cout << "Word Count: " << String1.CountWords() << endl;


    
    
    // >>
    // Change the first letter of each word.
    string Text = "hello world from c++";

    cout << "\nUpper First Letter Of Each Word:\n";
    cout << clsString::UpperFirstLetterOfEachWord(Text) << endl;

    cout << "Lower First Letter Of Each Word:\n";
    cout << clsString::LowerFirstLetterOfEachWord("HELLO WORLD FROM C++") << endl;




    // >>
    // Convert all letters to upper and lower case.
    cout << "\nUpper All String:\n";
    cout << clsString::UpperAllString(Text) << endl;

    cout << "Lower All String:\n";
    cout << clsString::LowerAllString("HELLO WORLD FROM C++") << endl;




    // >>
    // Invert letter case.
    cout << "\nInvert Letter Case:\n";
    cout << clsString::InvertLetterCase('a') << endl;
    cout << clsString::InvertLetterCase('A') << endl;
    cout << clsString::InvertAllLettersCase("Hello World") << endl;



    // >>
    // Count letters by type.
    string LettersText = "Hello C++ World 123";

    cout << "\nCount Letters:\n";
    cout << "All Characters: "
        << clsString::CountLetters(LettersText, clsString::All) << endl;

    cout << "Capital Letters: "
        << clsString::CountLetters(LettersText, clsString::CapitalLetters) << endl;

    cout << "Small Letters: "
        << clsString::CountLetters(LettersText, clsString::SmallLetters) << endl;

    cout << "Count Capital Letters: "
        << clsString::CountCapitalLetters(LettersText) << endl;

    cout << "Count Small Letters: "
        << clsString::CountSmallLetters(LettersText) << endl;

    cout << "Count Specific Letter (l): "
        << clsString::CountSpecificLetter(LettersText, 'l') << endl;

    cout << "Count Specific Letter Without Match Case (l): "
        << clsString::CountSpecificLetter(LettersText, 'l', false) << endl;




    // >>
    // Check vowels and count vowels.
    cout << "\nVowels:\n";
    cout << "Is A Vowel: " << clsString::IsVowel('A') << endl;
    cout << "Is B Vowel: " << clsString::IsVowel('B') << endl;
    cout << "Count Vowels: " << clsString::CountVowels("Hello World") << endl;


    
    
    // >>
    // Split a string using a delimiter.
    cout << "\nSplit String:\n";

    vector<string> vString = clsString::Split("Ali#Ahmed#Fadi#Osama", "#");

    for (string& Word : vString)
    {
        cout << Word << endl;
    }


    
    
    
    // >>
    // Trim spaces from the left, right and both sides.
    string SpacesText = "     Hello World     ";

    cout << "\nTrim Operations:\n";
    cout << "Original: [" << SpacesText << "]" << endl;
    cout << "Trim Left: [" << clsString::TrimLeft(SpacesText) << "]" << endl;
    cout << "Trim Right: [" << clsString::TrimRight(SpacesText) << "]" << endl;
    cout << "Trim: [" << clsString::Trim(SpacesText) << "]" << endl;




    // >>
    // Join strings from a vector and an array.
    cout << "\nJoin Strings:\n";

    vector<string> JoinVector = { "Ali", "Ahmed", "Fadi" };

    string JoinArray[] = { "One", "Two", "Three" };

    cout << "Join Vector: "
        << clsString::JoinString(JoinVector, " - ") << endl;

    cout << "Join Array: "
        << clsString::JoinString(JoinArray, 3, " - ") << endl;




    // >>
    // Reverse words in a string.
    cout << "\nReverse Words:\n";
    cout << clsString::ReverseWordsInString("I Love Programming") << endl;




    // >>
    // Replace complete words in a string.
    cout << "\nReplace Word:\n";
    cout << clsString::ReplaceWord("I Love C++ And I Love Programming", "Love", "Enjoy") << endl;

    cout << "Replace Without Match Case:\n";
    cout << clsString::ReplaceWord("Hello hello HELLO", "hello", "Hi", false) << endl;





    // >>
    // Remove punctuation marks from a string.
    cout << "\nRemove Punctuations:\n";
    cout << clsString::RemovePunctuations("Hello, World! Welcome to C++.") << endl;




    // >>
    // Replace a specific text inside a string.
    cout << "\nReplace Text:\n";
    cout << clsString::ReplaceWordInString("I Love C++ Programming", "C++", "Object Oriented Programming") << endl;




    //>>
    // Use object methods to modify the stored string value.
    cout << "\nObject Methods:\n";

    clsString ObjectString("hello world from c++");

    cout << "Original: " << ObjectString.Value << endl;

    ObjectString.UpperFirstLetterOfEachWord();
    cout << "Upper First Letter: " << ObjectString.Value << endl;

    ObjectString.LowerFirstLetterOfEachWord();
    cout << "Lower First Letter: " << ObjectString.Value << endl;

    ObjectString.UpperAllString();
    cout << "Upper All: " << ObjectString.Value << endl;

    ObjectString.LowerAllString();
    cout << "Lower All: " << ObjectString.Value << endl;

    ObjectString.InvertAllLettersCase();
    cout << "Invert All: " << ObjectString.Value << endl;

    ObjectString.Trim();
    cout << "Trim: [" << ObjectString.Value << "]" << endl;

    ObjectString.ReverseWordsInString();
    cout << "Reverse Words: " << ObjectString.Value << endl;

    ObjectString.RemovePunctuations();
    cout << "Remove Punctuations: " << ObjectString.Value << endl;


    

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




    cout << "\n\n==================== clsUtility Library ====================\n\n";



    // >>
    // Generate random numbers and random characters.
    cout << "Random Number: " << clsUtility::RandomNumber(1, 1000) << endl;

    cout << "Random Capital Letter: "
        << clsUtility::GetRandomCharacter(clsUtility::CapitalLetter) << endl;

    cout << "Random Small Letter: "
        << clsUtility::GetRandomCharacter(clsUtility::SmallLetter) << endl;

    cout << "Random Digit: "
        << clsUtility::GetRandomCharacter(clsUtility::Digit) << endl;

    cout << "Random Mixed Character: "
        << clsUtility::GetRandomCharacter(clsUtility::Mix) << endl;




    // >>
    // Generate random words and keys.
    cout << "\nRandom Word: "
        << clsUtility::GenerateWord(clsUtility::Mix, 5) << endl;

    cout << "Random Key: "
        << clsUtility::GenerateKey(clsUtility::Mix, 5, 3) << endl;

    cout << "\nGenerate Multiple Keys:\n";
    clsUtility::GenerateKeys(clsUtility::Mix, 5, 3, 5);




    // >>
    // Swap values of different data types.
    cout << "\nSwap Operations:\n";

    short Num1 = 10, Num2 = 20;

    cout << "Before Swap: " << Num1 << " - " << Num2 << endl;
    clsUtility::Swap(Num1, Num2);
    cout << "After Swap: " << Num1 << " - " << Num2 << endl;

    int x = 100, y = 200;

    cout << "\nBefore Swap: " << x << " - " << y << endl;
    clsUtility::Swap(x, y);
    cout << "After Swap: " << x << " - " << y << endl;

    double a = 10.5, b = 20.5;

    cout << "\nBefore Swap: " << a << " - " << b << endl;
    clsUtility::Swap(a, b);
    cout << "After Swap: " << a << " - " << b << endl;

    string S1 = "Ali", S2 = "Ahmed";

    cout << "\nBefore Swap: " << S1 << " - " << S2 << endl;
    clsUtility::Swap(S1, S2);
    cout << "After Swap: " << S1 << " - " << S2 << endl;

    
    clsDate UtilityDate1(1, 1, 2022), UtilityDate2(30, 12, 2022);

    cout << "\nBefore Swap: "
        << UtilityDate1.DateToString() << " - " << UtilityDate2.DateToString() << endl;

    clsUtility::Swap(UtilityDate1, UtilityDate2);

    cout << "After Swap: "
        << UtilityDate1.DateToString() << " - " << UtilityDate2.DateToString() << endl;



    // >>
    // Shuffle elements of arrays.
    cout << "\nShuffle Arrays:\n";

    short Arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    short Arr1Length = sizeof(Arr1) / sizeof(Arr1[0]);

    clsUtility::ShuffleArray(Arr1, Arr1Length);

    cout << "Shuffled Numbers: ";

    for (short i = 0; i < Arr1Length; i++)
    {
        cout << Arr1[i] << " ";
    }

    cout << endl;

    string StringArray[] = { "Ali", "Fadi", "Ahmed", "Osama" };
    short StringArrayLength = sizeof(StringArray) / sizeof(StringArray[0]);

    clsUtility::ShuffleArray(StringArray, StringArrayLength);

    cout << "Shuffled Names: ";

    for (short i = 0; i < StringArrayLength; i++)
    {
        cout << StringArray[i] << " ";
    }

    cout << endl;





    // >>
    // Fill an array with random numbers.
    cout << "\nFill Array With Random Numbers:\n";

    short Arr2[10];
    short Arr2Length = sizeof(Arr2) / sizeof(Arr2[0]);

    clsUtility::FillArrayWithRandomNumber(Arr2, Arr2Length, 10, 100);

    for (short i = 0; i < Arr2Length; i++)
    {
        cout << Arr2[i] << " ";
    }

    cout << endl;



    // >>
    // Fill arrays with random words and keys.
    cout << "\nFill Array With Random Words:\n";

    string Arr3[5];
    short Arr3Length = sizeof(Arr3) / sizeof(Arr3[0]);

    clsUtility::FillArrayWithRandomWords(Arr3, Arr3Length, clsUtility::Mix, 5);

    for (short i = 0; i < Arr3Length; i++)
    {
        cout << Arr3[i] << endl;
    }
    

    cout << "\nFill Array With Random Keys:\n";

    string Arr4[5];
    short Arr4Length = sizeof(Arr4) / sizeof(Arr4[0]);

    clsUtility::FillArrayWithRandomKeys(Arr4, Arr4Length, clsUtility::Mix, 5, 3);

    for (short i = 0; i < Arr4Length; i++)
    {
        cout << Arr4[i] << endl;
    }




    // >>
    // Print tabs between two text values.
    cout << "\nTabs Example:\n";

    cout << "Text1";
    clsUtility::Tabs(2);
    cout << "Text2" << endl;




    // >>
    // Encrypt and decrypt a text using an encryption key.
    cout << "\nEncryption And Decryption:\n";

    string OriginalText = "Mohammed Nasr";

    string EncryptedText = clsUtility::EncryptText(OriginalText, 5);

    cout << "Original Text: " << OriginalText << endl;
    cout << "Encrypted Text: " << EncryptedText << endl;

    string DecryptedText = clsUtility::DecryptText(EncryptedText, 5);

    cout << "Decrypted Text: " << DecryptedText << endl;

    return 0;
}
