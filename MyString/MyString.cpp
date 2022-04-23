#include "MyString.h"
#include <cstring>

void MyString::copy(const char* str)
{
    size = strlen(str) + 1;
    this->str = new char[size];
    strcpy(this->str, str);
}

void MyString::deleteMem()
{
    delete[] str;
    size = 0;
}

MyString::MyString(const char* str)
{
    copy(str);
}

MyString::MyString(const MyString& other)
{
    copy(other.str);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        deleteMem();
        copy(other.str);
    }
    return *this;
}

MyString::~MyString()
{
    deleteMem();
}

bool MyString::operator==(const MyString& other)
{
    return (strcmp(str, other.str) == 0);
}

MyString& MyString::operator+=(const MyString& other)
{
    strcat(str, other.str);
    size += other.size;
    return *this;
}

MyString operator+(const MyString& first, const MyString& second)
{
    MyString newString(first);
    newString += second;
    return newString;
}

std::ostream& operator<<(std::ostream& os, const MyString& other)
{
    os.write((const char*)&other.size, sizeof(other.size));
    os.write(other.str, other.size);

    return os;
}

std::istream& operator>>(std::istream& is, MyString& other)
{
    is.read((char*)&other.size, sizeof(other.size));
    is.read(other.str, other.size);

    return is;
}

size_t MyString::getSize() const
{
    return size;
}

const char* MyString::getStr() const
{
    return str;
}
