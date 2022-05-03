#include "Ticket.h"

Ticket::Ticket(size_t seat, size_t row, String password, String description)
    : seat(seat)
    , row(row)
    , password(password)
    , description(description)
    , isReserved(0)
{
}

void Ticket::changeReservedState()
{
    isReserved++;
}

short Ticket::getReservedState() const
{
    return isReserved;
}

size_t Ticket::getSeat() const
{
    return seat;
}

size_t Ticket::getRow() const
{
    return row;
}

String Ticket::getPassword() const
{
    return password;
}

String Ticket::getDescription() const
{
    return description;
}

std::ostream& operator<<(std::ostream& os, const Ticket& other)
{
    os.write((const char*)&other.seat, sizeof(other.seat));
    os.write((const char*)&other.row, sizeof(other.row));
    os << other.password;
    os << other.description;

    return os;
}

std::istream& operator>>(std::istream& is, Ticket& other)
{
    is.read((char*)&other.seat, sizeof(other.seat));
    is.read((char*)&other.row, sizeof(other.row));
    is >> other.password;
    is >> other.description;

    return is;
}
