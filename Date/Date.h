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
    bool isDateCorrect = true; //!< Used to check whether the date is not correct during runtime.

    static const unsigned short DEFAULT_DAY = 1;   //!< Default value for the day, used in the default constructor.
    static const unsigned short DEFAULT_MONTH = 1; //!< Default value for the month, used in the default constructor.
    static const unsigned DEFAULT_YEAR = 2022;     //!< Default value for the year, used in the default constructor.
    unsigned short daysInMonth[12];

    void isYearLeap();          //!< Function used to change the 'february' value in daysInMonth array.
    void populateDaysInMonth(); //!< Function used to populate the array with days depending on whether the year is leap.

public:
    Date(const unsigned short day = DEFAULT_DAY, const unsigned short month = DEFAULT_MONTH, const unsigned year = DEFAULT_YEAR);

    void increaseDay(); //!< Increments the day with one.

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;
    bool getIsDateCorrect() const;

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
