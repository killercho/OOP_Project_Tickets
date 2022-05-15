#ifndef ROOM_H
#define ROOM_H

#include <iostream>

/**
 *  A Room class used to store information about the rooms.
 * */
class Room {
private:
    size_t roomId;
    size_t rows;
    size_t seatsOnRow;

    static size_t id;                             //!< Static id which increments with the creation of every room thus giving each one a unique id.
    static const short DEFAULT_ROW = 5;           //!< Default value for the number of rows in a room. Used in the default constructor.
    static const short DEFAULT_SEATS_ON_ROW = 10; //!< Default value for the number of seats on a row in a room. Used in the default constructor.

public:
    Room(size_t rows = DEFAULT_ROW, size_t seatsOnRow = DEFAULT_SEATS_ON_ROW);

    size_t getRoomId() const;
    size_t getRows() const;
    size_t getSeatsOnRow() const;

    bool operator==(const Room& other) const; //!< Operator '==' used to check if a room is the same as another room.

    friend std::ostream& operator<<(std::ostream& os, const Room& other); //!< Overrides the normal '<<' operator to give binary file functionality.
    friend std::istream& operator>>(std::istream& is, Room& other);       //!< Overrides the normal '>>' operator to give binary file functionality.
};

#endif
