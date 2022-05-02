#include "Date.h"

Date::Date(const unsigned short day, const unsigned short month, const unsigned year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

bool Date::isYearLeap()
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool Date::isNewDateValid(const unsigned short day, const unsigned short month, const unsigned year)
{
    if (month > 12 || month == 0)
        return false;

    const unsigned short daysInMonth[] = { 31, (unsigned short)(isYearLeap() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day > daysInMonth[month + 1])
        return false;

    return true;
}

bool Date::isDateValid()
{
    return isNewDateValid(day, month, year);
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

void Date::setDay(const unsigned short day)
{
    if (isNewDateValid(day, month, year))
        this->day = day;
    else
        this->day = DEFAULT_DAY;
}

void Date::setMonth(const unsigned short month)
{
    if (isNewDateValid(day, month, year))
        this->month = month;
    else
        this->month = DEFAULT_MONTH;
}

void Date::setYear(const unsigned year)
{
    if (isNewDateValid(day, month, year))
        this->year = year;
    else
        this->year = DEFAULT_YEAR;
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
