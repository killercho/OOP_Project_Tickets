#include "Date.h"
#include <cmath>

unsigned short Date::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(const unsigned short day, const unsigned short month, const unsigned year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void Date::setYear(const unsigned int year)
{
    this->year = year;
    isYearLeap();
}

void Date::setMonth(unsigned short month)
{
    if (month == 0 || month > 12)
        month = DEFAULT_MONTH;
    this->month = month;
}

void Date::setDay(unsigned short day)
{
    if (day > daysInMonth[month - 1])
        day = DEFAULT_DAY;
    this->day = day;
}

void Date::isYearLeap()
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        daysInMonth[1] = 29;
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
    if (day + 1 > daysInMonth[month]) {
        setDay(1);
        if (month + 1 > 12) {
            setMonth(1);
            setYear(year + 1);
        }
    }
}

bool Date::operator>(const Date& other) const
{
    return (year > other.year && month > other.month && day > other.day);
}

String Date::getStringDay() const
{
    unsigned short tmp = day;
    char helper[2];
    if (tmp < 10)
        helper[0] = ((tmp % 10) + '0');
    else {
        for (int i = 0; i < 2; ++i) {
            helper[i] = (tmp / (int)pow(10, 1 - i) % 10 + '0');
        }
    }

    String number = helper;
    return number;
}

String Date::getStringMonth() const
{
    unsigned short tmp = month;
    char helper[2];
    if (tmp < 10)
        helper[0] = ((tmp % 10) + '0');
    else {
        for (int i = 0; i < 2; ++i) {
            helper[i] = (tmp / (int)pow(10, 1 - i) % 10 + '0');
        }
    }

    String number = helper;
    return number;
}

String Date::getStringYear() const
{
    unsigned short tmp = year;
    char helper[4];
    for (int i = 0; i < 4; i++) {
        helper[i] = (tmp / (int)pow(10, 3 - i) % 10 + '0');
    }

    String number = helper;
    return number;
}
