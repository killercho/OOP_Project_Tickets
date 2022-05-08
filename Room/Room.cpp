#include "Room.h"

size_t Room::id = 0;

Room::Room(size_t rows, size_t seatsOnRow)
    : rows(rows)
    , seatsOnRow(seatsOnRow)
    , roomId(id++)
{
}

size_t Room::getRoomId() const
{
    return roomId;
}

size_t Room::getRows() const
{
    return rows;
}

size_t Room::getSeatsOnRow() const
{
    return seatsOnRow;
}

std::ostream& operator<<(std::ostream& os, const Room& other)
{
    os.write((const char*)&other.roomId, sizeof(other.roomId));
    os.write((const char*)&other.rows, sizeof(other.rows));
    os.write((const char*)&other.seatsOnRow, sizeof(other.seatsOnRow));

    return os;
}

std::istream& operator>>(std::istream& is, Room& other)
{
    is.read((char*)&other.roomId, sizeof(other.roomId));
    is.read((char*)&other.rows, sizeof(other.rows));
    is.read((char*)&other.seatsOnRow, sizeof(other.seatsOnRow));

    return is;
}

bool Room::operator==(const Room& other) const
{
    return roomId == other.roomId;
}
