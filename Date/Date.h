#ifndef DATE_H
#define DATE_H

#include "../String/String.h"
#include <cstring>
#include <iostream>

/**
 * A Date class used to store information about the date in he rest of the project.
 * */
class Date {
private:
    unsigned short day;
    unsigned short month;
    unsigned year;

    static const unsigned short DEFAULT_DAY = 1;   //!< Default value for the day, used in the default constructor.
    static const unsigned short DEFAULT_MONTH = 1; //!< Default value for the month, used in the default constructor.
    static const unsigned DEFAULT_YEAR = 2022;     //!< Default value for the year, used in the default constructor.
    static unsigned short daysInMonth[12];         //!< Array filled with the number of days in a month. Used later in the project for easier check if the day is more than the avaluable days in that month.

    void isYearLeap(); //!< Function used to change the 'february' value in daysInMonth array.

public:
    Date(const unsigned short day = DEFAULT_DAY, const unsigned short month = DEFAULT_MONTH, const unsigned year = DEFAULT_YEAR);

    void increaseDay(); //!< Increments the day with one.

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;

    String getStringDay() const;
    String getStringMonth() const;
    String getStringYear() const;

    void setDay(unsigned short day);
    void setMonth(unsigned short month);
    void setYear(const unsigned year);

    friend std::ostream& operator<<(std::ostream& os, const Date& other);
    friend std::istream& operator>>(std::istream& is, Date& other);

    bool operator>(const Date& other) const;  //!< Operator '>' used to check if a date is bigger than another date.
    bool operator==(const Date& other) const; //!< Operator '==' used to check if a date is the same as another date.
};

#endif
