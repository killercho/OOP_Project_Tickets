#include "Show.h"

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
