#include "String.h"
#include <cstring>

void String::copy(const char* str)
{
    size = strlen(str) + 1;
    this->str = new char[size];
    strcpy(this->str, str);
}

void String::deleteMem()
{
    delete[] str;
    size = 0;
}

String::String(const char* str)
{
    copy(str);
}

String::String(const String& other)
{
    copy(other.str);
}

String& String::operator=(const String& other)
{
    if (this != &other) {
        deleteMem();
        copy(other.str);
    }
    return *this;
}

String::~String()
{
    deleteMem();
}

bool String::operator==(const String& other)
{
    return (strcmp(str, other.str) == 0);
}

String& String::operator+=(const String& other)
{
    strcat(str, other.str);
    size += other.size;
    return *this;
}

String operator+(const String& first, const String& second)
{
    String newString(first);
    newString += second;
    return newString;
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
    os.write((const char*)&other.size, sizeof(other.size));
    os.write(other.str, other.size);

    return os;
}

std::istream& operator>>(std::istream& is, String& other)
{
    is.read((char*)&other.size, sizeof(other.size));
    is.read(other.str, other.size);

    return is;
}

size_t String::getSize() const
{
    return size;
}

const char* String::getStr() const
{
    return str;
}
