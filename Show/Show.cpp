#include "Show.h"

const Room Show::DEFAULT_ROOM = Room();
const Date Show::DEFAULT_DATE = Date();
const String Show::DEFAULT_STRING = String();

Show::Show(const String& name, const Room& room, const Date& date)
{
    this->name = name;
    this->room = room;
    this->date = date;

    size_t rows = room.getRows();
    size_t seatsOnRow = room.getSeatsOnRow();

    for (size_t i = 0; i < rows; ++i) {
        Vector<Ticket> row;
        for (size_t j = 0; j < seatsOnRow; ++j) {
            row.push(Ticket(i, j));
        }
        seats.push(row);
    }
}

String Show::getName() const
{
    return name;
}

Room Show::getRoom() const
{
    return room;
}

Date Show::getDate() const
{
    return date;
}

bool Show::operator==(const Show& other) const
{
    return (room == other.room);
}

bool Show::isRoomFree(const Date& checkDate) const
{
    return !(checkDate == date);
}

bool Show::isSeatTaken(size_t row, size_t seatOnRow) const
{
    return !(seats[row][seatOnRow].getReservedState() == 0);
}

String Show::reserveTicket(const size_t row, const size_t seatOnRow, const String& password, const String& desc)
{
    if (seats[row][seatOnRow].getReservedState() != 0)
        return "Cannot reserve! Seat already taken!";

    seats[row][seatOnRow].increaseReservedState();
    seats[row][seatOnRow].setDescription(desc);
    seats[row][seatOnRow].setPassword(password);
    return "Successful reservation!";
}

String Show::removeReservation(const size_t row, const size_t seatOnRow, const String& password, const String& desc)
{
    if (seats[row][seatOnRow].getReservedState() == 2)
        return "Cannot remove reservation! Ticket already bought!";

    if (seats[row][seatOnRow].getReservedState() == 0)
        return "Cannot remove reservation! Seat is not reserved!";

    if (!(seats[row][seatOnRow].getPassword() == password && seats[row][seatOnRow].getDescription() == desc))
        return "Password or description doesn't match what the database shows!";

    seats[row][seatOnRow].clearReservedState();
    return "Reservation removed successfully!";
}

bool Show::buyTicket(const size_t row, const size_t seatOnRow)
{
    if (seats[row][seatOnRow].getReservedState() == 1)
        return false;

    seats[row][seatOnRow].increaseReservedState();
    seats[row][seatOnRow].increaseReservedState();
    return true;
}

short Show::buyTicket(const size_t row, const size_t seatOnRow, const String& password)
{
    if (seats[row][seatOnRow].getReservedState() == 2)
        return 1;

    if (!(seats[row][seatOnRow].getPassword() == password))
        return 2;

    seats[row][seatOnRow].increaseReservedState();
    return 0;
}

size_t Show::freeSeats() const
{
    size_t rows = room.getRows();
    size_t seatsOnRow = room.getSeatsOnRow();
    size_t result = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < seatsOnRow; ++j) {
            if (seats[i][j].getReservedState() == 0)
                result++;
        }
    }
    return result;
}

size_t Show::reserveList() const
{
    size_t rows = room.getRows();
    size_t seatsOnRow = room.getSeatsOnRow();
    size_t result = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < seatsOnRow; ++j) {
            if (seats[i][j].getReservedState() == 1)
                result++;
        }
    }
    return result;
}

size_t Show::boughtList() const
{
    size_t rows = room.getRows();
    size_t seatsOnRow = room.getSeatsOnRow();
    size_t result = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < seatsOnRow; ++j) {
            if (seats[i][j].getReservedState() == 2)
                result++;
        }
    }
    return result;
}
