#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Room {
private:
    size_t roomId;
    size_t rows;
    size_t seatsOnRow;

    static size_t id;
    static const short DEFAULT_ROW = 5;
    static const short DEFAULT_SEATS_ON_ROW = 10;

public:
    Room(size_t rows = DEFAULT_ROW, size_t seatsOnRow = DEFAULT_SEATS_ON_ROW);

    size_t getRoomId() const;
    size_t getRows() const;
    size_t getSeatsOnRow() const;

    bool operator==(const Room& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Room& other);
    friend std::istream& operator>>(std::istream& is, Room& other);
};

#endif
