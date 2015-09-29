#include "date.h"

Date::Date() {
dateMonth = 0;
dateDay = 0;
dateYear = 0;
}
Date::Date(unsigned short month, unsigned short day, unsigned short year) {
    // TODO Auto-generated constructor stub
    dateMonth= month;
    dateDay = day;
    dateYear = year;

}

Date::~Date() {
    // TODO Auto-generated destructor stub
}




/*************************************************************************
 * used to set the date inside the class Date.
 * _______________________________________________________________________
 * month
 * day
 * year
 * _______________________________________________________________________
 * returns nothing
 *************************************************************************/
void Date::SetDate(unsigned short month, unsigned short day, unsigned short year)
{
    dateMonth = month;
    dateDay = day;
    dateYear = year;
}



/*************************************************************************
 *  used to get the date from the user and use the validate methods to
 *  check if the input is valid
 * _______________________________________________________________________
 * month
 * day
 * year
 * _______________________________________________________________________
 * returns nothing
 *************************************************************************/
void Date::GetDate(unsigned short &month, unsigned short &day, unsigned short &year)
{
//	cout << "enter the month: ";
//	cin >> month;
//	cin.ignore(1000,'\n');
//	cout << "enter the day: ";
//	cin >> day;
//	cin.ignore(1000,'\n');
//	cout << "enter the year: ";
//	cin >> year;
//	cin.ignore(1000,'\n');

    ValidateYear(year);
    ValidateMonth(month);
    ValidateDay(month, day, year);
    ValidateDate(month, day, year);


}

/*************************************************************************
 *  returns the month
 * _______________________________________________________________________
 * nothing
 * _______________________________________________________________________
 * returns the month
 *************************************************************************/
unsigned short Date::GetMonth() const
{
    return dateMonth;
}

/*************************************************************************
 *  returns the date
 * _______________________________________________________________________
 * nothing
 * _______________________________________________________________________
 * returns the date
 *************************************************************************/
unsigned short Date::GetDay() const
{
    return dateDay;
}

/*************************************************************************
 *  returns the year
 * _______________________________________________________________________
 * nothing
 * _______________________________________________________________________
 * returns the year
 *************************************************************************/
unsigned short Date::GetYear() const
{
    return dateYear;
}

/*************************************************************************
 *  used to display the output to the screen
 * _______________________________________________________________________
 * nothing
 * _______________________________________________________________________
 * returns nothing
 *************************************************************************/
void Date::DisplayDate() const
{
cout << dateMonth << "/" << dateDay << "/" << dateYear << endl;
}

/*************************************************************************
 *  returns weather the year is a leap year or not
 * _______________________________________________________________________
 * year
 * _______________________________________________________________________
 * returns nothing
 *************************************************************************/
bool Date::IsLeapYear(unsigned short year) const
{
    bool leap;
    leap = false;

    if(year %4 == 0 || year %400)
    {
      leap = true;
    }
    else if(year %100 == 0)
    {
        leap = false;
    }
    return leap;
}

/*************************************************************************
 *  used to get the number of days in each month of the year depending on
 *  the leap year and on the month
 * _______________________________________________________________________
 * month
 * year
 * _______________________________________________________________________
 * returns the number of days in the month
 *************************************************************************/
unsigned short Date::GetDaysInMonth(unsigned short month, unsigned short year)const
{
bool leap;
unsigned short daysMonth;
leap = IsLeapYear(year);

if ( month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month == 12)
        {
            daysMonth = 31;
        }
else if ( month !=2 )
{
    daysMonth = 30;
}
else
{
    if (leap == true)
    {
        daysMonth = 29;
    }
    else
    {
        daysMonth = 28;
    }
}

return daysMonth;
}

/*************************************************************************
 *  used to ensure the month inputed by the user is between 1 and 12
 * _______________________________________________________________________
 * month
 * _______________________________________________________________________
 * returns nothing
 *************************************************************************/
void Date::ValidateMonth(unsigned short &month)
{
    bool valid;
    do
    {
        valid = true;
    if(month < 1 || month > 12)
        {
            valid = false;

            cout << endl;
            cout << "Invalid month! Try again: ";
            cin >> month;

        }
    } while(!valid);

    cin.ignore(1000, '\n');
    cout << endl;

}

/*************************************************************************
 *  used to ensure that the day inputed by the user is less than the number
 *  of days in that month
 * _______________________________________________________________________
 * month
 * day
 * year
 * _______________________________________________________________________
 * returns nothing
 *************************************************************************/
void Date::ValidateDay(unsigned short month, unsigned short &day, unsigned short year)
{
    unsigned short valDay;
    valDay = GetDaysInMonth(month, year);
    bool isDayVal;

    do
    {
        isDayVal = true;
        if (day > valDay)
        {
            cout << "invalid Day please enter a valid day: ";
            cin >> day;
            cin.ignore(1000,'\n');
            isDayVal = false;
        }

    }while(!isDayVal);
}
/*************************************************************************
 *  used to ensure the year inputed by the user is between 1900-2015
 * _______________________________________________________________________
 * year
 * _______________________________________________________________________
 * returns nothing
 *************************************************************************/
void Date::ValidateYear(unsigned short &year)
{
    bool valYear;
    do
    {
        valYear = true;

if (year > 2015 || year < 1900)
{
    cout << "invalid year please input a year between 1900 & 2015: ";
    cin >> year;
    cin.ignore(1000,'\n');
    valYear = false;
}
    }while(!valYear);
}

/*************************************************************************
 *  used to ensure the date that the user inputed is not a date in the
 *  future
 * _______________________________________________________________________
 * month
 * day
 * year
 * _______________________________________________________________________
 * returns true of false
 *************************************************************************/
bool Date::ValidateDate(unsigned short month, unsigned short day,  unsigned short year)const
{
    time_t now;
    tm *currentTime;

    now = time(NULL);
    currentTime = localtime(&now);
    bool valid;
    valid = true;

    // Store time members into variables
    int currentYear;
    int currentMonth;
    int currentDay;
    currentYear = 1900 + currentTime->tm_year;
    currentMonth = currentTime->tm_mon + 1;
    currentDay = currentTime->tm_mday;

    if ( year > currentYear)
    {
        valid = false;
    }
    else if (year == currentYear && month > currentMonth)
    {
        valid = false;
    }
    else if ( year == currentYear && month == currentMonth && day > currentDay)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
return valid;
}


