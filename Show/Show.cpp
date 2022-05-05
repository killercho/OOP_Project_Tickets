#include "Show.h"

void Show::copy(const String& name, const Room& room, const Date& date, Ticket** seats)
{
    this->name = name;
    this->room = room;
    this->date = date;

    size_t rows = room.getRows();
    size_t seatsOnRow = room.getSeatsOnRow();

    this->seats = new Ticket*[rows];
    for (size_t i = 0; i < rows; ++i) {
        this->seats[i] = new Ticket[seatsOnRow];
        for (size_t j = 0; j < seatsOnRow; ++j) {
            this->seats[i][j] = seats[i][j];
        }
    }
}

void Show::deleteMem()
{
    for (size_t i = 0; i < room.getRows(); ++i) {
        delete[] seats[i];
    }
    delete[] seats;
}

Ticket** Show::createEmptySaloon(const size_t rows, const size_t seatsOnRow)
{
    Ticket** newSeats = new Ticket*[rows];
    for (size_t i = 0; i < rows; ++i) {
        newSeats[i] = new Ticket[seatsOnRow];
        for (size_t j = 0; j < seatsOnRow; ++j) {
            newSeats[i][j] = Ticket(j, i);
        }
    }
    return newSeats;
}

Show::Show(const String& name, const Room& room, const Date& date)
{
    Ticket** newSeats = createEmptySaloon(room.getRows(), room.getSeatsOnRow());
    copy(name, room, date, newSeats);
    for (size_t i = 0; i < room.getRows(); ++i) {
        delete[] newSeats[i];
    }
    delete[] newSeats;
}

Show::Show(const Show& other)
{
    copy(other.name, other.room, other.date, other.seats);
}

Show& Show::operator=(const Show& other)
{
    if (this != &other) {
        deleteMem();
        copy(other.name, other.room, other.date, other.seats);
    }
    return *this;
}

Show::~Show()
{
    deleteMem();
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
