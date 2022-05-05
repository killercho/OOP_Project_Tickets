#ifndef TICKET_H
#define TICKET_H

#include "../String/String.h"

class Ticket {
private:
    size_t seat;
    size_t row;
    String description;
    String password;
    short isReserved; // 0 - no; 1 - yes; 2 - bought

public:
    Ticket(size_t seat = 0, size_t row = 0, String password = "", String description = "");

    void changeReservedState(); // Changes the state from 0 -> 1 or from 1 -> 2.

    short getReservedState() const;
    size_t getSeat() const;
    size_t getRow() const;
    String getDescription() const;
    String getPassword() const;

    friend std::ostream& operator<<(std::ostream& os, const Ticket& other);
    friend std::istream& operator>>(std::istream& is, Ticket& other);
};

#endif
