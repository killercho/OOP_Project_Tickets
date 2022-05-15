#ifndef STRING_H
#define STRING_H

#include <iostream>

/**
 * A normal String class, used to replace all the char* types later in the project.
 * */
class String {
private:
    char* str;
    size_t size;

    void copy(const char* str);
    void deleteMem();

public:
    String(const char* str = "");
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    String(String&& other);
    String& operator=(String&& other);

    size_t getSize() const;
    const char* getStr() const;

    bool operator==(const String& other) const;
    String& operator+=(const String& other); //!< Operator, used to concat two Strings. Returns the first String with concatenated second String.

    friend std::ostream& operator<<(std::ostream& os, const String& other);
    friend std::istream& operator>>(std::istream& is, String& other);
};

String operator+(const String& first, const String& second); //!< Operator, used to concat two Strings. Returns a new String as a result from concatenating the first and the second.

#endif
