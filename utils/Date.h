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

    bool isYearLeap();
    bool isNewDateValid(const unsigned short day, const unsigned short month, const unsigned year);

public:
    Date(const unsigned short day, const unsigned short month, const unsigned year);

    bool operator==(const Date& other);
    bool isDateValid();

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;

    void setDay(const unsigned short day);
    void setMonth(const unsigned short month);
    void setYear(const unsigned year);

    friend std::ostream& operator<<(std::ostream& os, const Date& other);
    friend std::istream& operator>>(std::istream& is, Date& other);
};

#endif
