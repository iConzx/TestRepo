#ifndef DATE_H
#define DATE_H


#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;




class Date{
public:
    Date();
    ~Date();

    //uses private utility method
    Date(unsigned short month,
         unsigned short day,
         unsigned short year);

    /****************
     *   MUTATORS   *
     ****************/
    //uses private utility method
    void SetDate(unsigned short month,
                 unsigned short day,
                 unsigned short year);

    /***************
     *  ACCESSORS  *
     ***************/
    void GetDate(unsigned short &month,
                 unsigned short &day,
                 unsigned short &year);

    unsigned short GetYear()  const;
    unsigned short GetMonth() const;
    unsigned short GetDay()   const;

    //Display in MM/DD/YYYY format
    void DisplayDate() const;

    /***********************
     *  UTILITIES METHODS  *
     ***********************/
private:
    // returns the number of days in each month of the year
    unsigned short GetDaysInMonth(unsigned short month,
                                  unsigned short year) const;

    // returns weather the year is a leap year
    bool IsLeapYear( unsigned short year) const;

    /************************
     *   VALIDATE METHODS   *
     ************************/

    //Validate the month
    void ValidateMonth(unsigned short &month);

    //Checks if a a day is valid takes leap year into consideration
    void ValidateDay( unsigned short month,
                      unsigned short &day,
                      unsigned short year);

    //Validate the year is between 1900 and the current year
    void ValidateYear(unsigned short &year);

    //uses methods above to validate a given date - checksagainst current day
    bool ValidateDate(unsigned short month,
                      unsigned short day,
                      unsigned short year) const;

    /***************
     *  ATTRIBUTES *
     ***************/
    unsigned short dateMonth;       //stores the month inputed by the user
    unsigned short dateDay;         //stores the day inputed by the user
    unsigned short dateYear;        //stores the year inputed by the user





};

#endif // DATE_H
