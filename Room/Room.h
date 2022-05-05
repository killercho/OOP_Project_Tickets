#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Room {
private:
    size_t roomId;
    size_t rows;
    size_t seatsOnRow;

    static size_t id;

public:
    Room(size_t rows = 5, size_t seatsOnRow = 10);

    size_t getRoomId() const;
    size_t getRows() const;
    size_t getSeatsOnRow() const;

    bool operator==(const Room& other);

    friend std::ostream& operator<<(std::ostream& os, const Room& other);
    friend std::istream& operator>>(std::istream& is, Room& other);
};

#endif
