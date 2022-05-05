#ifndef DATE_H
#define DATE_H

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
    static const unsigned short daysInMonth[12];

    bool isYearLeap();

public:
    Date(const unsigned short day = 1, const unsigned short month = 1, const unsigned year = 2022);

    bool operator==(const Date& other);
    bool isDateValid();

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;

    void setDay(unsigned short day);
    void setMonth(unsigned short month);
    void setYear(const unsigned year);

    friend std::ostream& operator<<(std::ostream& os, const Date& other);
    friend std::istream& operator>>(std::istream& is, Date& other);
};

#endif
