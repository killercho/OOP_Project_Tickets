#include "Date.h"
#include <iostream>

Date::Date(const unsigned short day, const unsigned short month, const unsigned year)
{
    setYear(year);
    setMonth(month);
    populateDaysInMonth();
    setDay(day);
}

void Date::setYear(const unsigned int year)
{
    this->year = year;
    if (year > 9999)
        isDateCorrect = false;
}

void Date::setMonth(unsigned short month)
{
    if (month == 0 || month > 12) {
        month = DEFAULT_MONTH;
        isDateCorrect = false;
    }
    this->month = month;
}

void Date::setDay(unsigned short day)
{
    if (day > daysInMonth[month - 1]) {
        day = DEFAULT_DAY;
        isDateCorrect = false;
    }
    this->day = day;
}

void Date::populateDaysInMonth()
{
    for (short i = 0; i < 7; ++i) {
        if (i % 2 == 0)
            daysInMonth[i] = 31;
        if (i % 2 == 1)
            daysInMonth[i] = 30;
        if (i == 1)
            isYearLeap();
    }
    for (short i = 7; i < 12; ++i) {
        if (i % 2 == 0)
            daysInMonth[i] = 30;
        else
            daysInMonth[i] = 31;
    }
}

void Date::isYearLeap()
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        daysInMonth[1] = 29;
    else
        daysInMonth[1] = 28;
}

bool Date::operator==(const Date& other) const
{
    return (day == other.day && month == other.month && year == other.year);
}

unsigned short Date::getDay() const
{
    return day;
}

unsigned short Date::getMonth() const
{
    return month;
}

unsigned Date::getYear() const
{
    return year;
}

bool Date::getIsDateCorrect() const
{
    return isDateCorrect;
}

std::ostream& operator<<(std::ostream& os, const Date& other)
{
    /*
    os.write((const char*)&other.day, sizeof(other.day));
    os.write((const char*)&other.month, sizeof(other.month));
    os.write((const char*)&other.year, sizeof(other.year));
*/
    os << other.day << "/" << other.month << "/" << other.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& other)
{
    is.read((char*)&other.day, sizeof(other.day));
    is.read((char*)&other.month, sizeof(other.month));
    is.read((char*)&other.year, sizeof(other.year));

    return is;
}

void Date::increaseDay()
{
    if (day + 1 > daysInMonth[month - 1]) {
        setDay(1);
        if (month + 1 > 12) {
            setMonth(1);
            setYear(year + 1);
        } else
            setMonth(month + 1);
    } else
        setDay(day + 1);
}

bool Date::operator>(const Date& other) const
{
    return (year > other.year && month > other.month && day > other.day);
}

String Date::getStringDay() const
{
    char result[2];
    result[0] = (day / 10 + '0');
    result[1] = (day % 10 + '0');

    return result;
}

String Date::getStringMonth() const
{
    char result[2];
    result[0] = (month / 10 + '0');
    result[1] = (month % 10 + '0');

    return result;
}

String Date::getStringYear() const
{
    char result[4];
    result[0] = (year / 1000 + '0');
    result[1] = ((year / 100) % 10 + '0');
    result[2] = ((year / 10) % 10 + '0');
    result[3] = (year % 10 + '0');

    return result;
}
