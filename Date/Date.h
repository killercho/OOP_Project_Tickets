#ifndef DATE_H
#define DATE_H

#include "../String/String.h"
#include <cstring>
#include <iostream>

class Date {
private:
    unsigned short day;
    unsigned short month;
    unsigned year;

    static const unsigned short DEFAULT_DAY = 1;
    static const unsigned short DEFAULT_MONTH = 1;
    static const unsigned DEFAULT_YEAR = 2022;
    static unsigned short daysInMonth[12];

    void isYearLeap();

public:
    Date(const unsigned short day = DEFAULT_DAY, const unsigned short month = DEFAULT_MONTH, const unsigned year = DEFAULT_YEAR);

    bool operator==(const Date& other) const;
    bool isDateValid();

    void increaseDay();

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

    bool operator>(const Date& other) const;
};

#endif
