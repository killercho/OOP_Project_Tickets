#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <ostream>

class MyString {
private:
    char* str;
    size_t size;

    void copy(const char* str);
    void deleteMem();

public:
    MyString(const char* str = nullptr);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    size_t getSize() const;
    const char* getStr() const;

    bool operator==(const MyString& other);
    MyString& operator+=(const MyString& other);

    friend std::ostream& operator<<(std::ostream& os, const MyString& other);
    friend std::istream& operator>>(std::istream& is, MyString& other);
};

MyString operator+(const MyString& first, const MyString& second);

#endif
