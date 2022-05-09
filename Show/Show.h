#ifndef SHOW_H
#define SHOW_H

#include "../Date/Date.h"
#include "../Room/Room.h"
#include "../String/String.h"
#include "../Ticket/Ticket.h"
#include "../Vector/Vector.h"

class Show {
private:
    String name;
    Room room;
    Date date;
    Vector<Vector<Ticket>> seats;

    static const Room DEFAULT_ROOM;
    static const Date DEFAULT_DATE;
    static const String DEFAULT_STRING;

public:
    Show(const String& name = DEFAULT_STRING, const Room& room = DEFAULT_ROOM, const Date& date = DEFAULT_DATE);

    String getName() const;
    Room getRoom() const;
    Date getDate() const;

    bool operator==(const Show& other) const;
    bool isRoomFree(const Date& checkDate) const;
    bool isSeatTaken(const size_t row, const size_t seatOnRow) const;

    // Change state 0 -> 1, using the DATE and NAME to search for the SHOW in the upper class.
    String reserveTicket(const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");

    // Enter all the info and the reservation is canceled (state (1||2) -> 0, password = "", desc = "").
    String removeReservation(const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");

    // Change state from 1 -> 2 or 0 -> 2 (depending on if there is a password).
    // Return 0 if the tansaction passed.
    // Return 1 if the seat is taken.
    // Return 2 if the password is wrong.
    bool buyTicket(const size_t row, const size_t seatOnRow);
    short buyTicket(const size_t row, const size_t seatOnRow, const String& password);

    size_t freeSeats() const;
    size_t reserveList() const;
    size_t boughtList() const;
};
#endif
