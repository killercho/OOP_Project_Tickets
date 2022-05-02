#include "Date.h"

const unsigned short Date::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(const unsigned short day, const unsigned short month, const unsigned year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void Date::setYear(const unsigned int year)
{
    this->year = year;
}

void Date::setMonth(unsigned short month)
{
    if (month == 0 || month > 12)
        month = DEFAULT_MONTH;
    this->month = month;
}

void Date::setDay(unsigned short day)
{
    if (isYearLeap() && month == 2) {
        if (day > daysInMonth[month - 1])
            day = DEFAULT_DAY;
    } else {
        if (day > daysInMonth[month - 1])
            day = DEFAULT_DAY;
    }
    this->day = day;
}

bool Date::isYearLeap()
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
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

bool Date::operator==(const Date& other)
{
    return (day == other.day && month == other.month && year == other.year);
}

std::ostream& operator<<(std::ostream& os, const Date& other)
{
    os.write((const char*)&other.day, sizeof(other.day));
    os.write((const char*)&other.month, sizeof(other.month));
    os.write((const char*)&other.year, sizeof(other.year));

    return os;
}

std::istream& operator>>(std::istream& is, Date& other)
{
    is.read((char*)&other.day, sizeof(other.day));
    is.read((char*)&other.month, sizeof(other.month));
    is.read((char*)&other.year, sizeof(other.year));

    return is;
}
