#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>

class String {
private:
    char* str;
    size_t size;

    void copy(const char* str);
    void deleteMem();

public:
    String(const char* str = nullptr);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    String(String&& other);
    String& operator=(String&& other);

    size_t getSize() const;
    const char* getStr() const;

    bool operator==(const String& other);
    String& operator+=(const String& other);

    friend std::ostream& operator<<(std::ostream& os, const String& other);
    friend std::istream& operator>>(std::istream& is, String& other);
};

String operator+(const String& first, const String& second);

#endif
