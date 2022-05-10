#ifndef TICKET_OFFICE_H
#define TICKET_OFFICE_H

#include "../Show/Show.h"

class TicketOffice {
private:
    Vector<Show> shows;

    size_t searchedShowIndex(const Date& date, const String& name); // Used to search for the index of the show in 'shows' with a given date and name.
    size_t searchedShowIndex(const Date& date, const Room& room);   // Used to search for the index of the show in 'shows' with a given date and room.

public:
    bool addShow(const Date& date, const String& name, const Room& room); // If the room is taken on that date the adding is not done.

    bool reserveTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");
    void removeReservation(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");

    void buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow);
    void buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password);

    void freeSeatsReport(const Date& date, const String& name);
    void reservedSeatsReport(const Date& date, const String& name, const bool allDates = false, const bool allNames = false); // If ALL is entered the bool flag is turned to true
                                                                                                                              // and the corresponding value is set to default.
    void boughtSeatsReport(Date& fromDate, const Date& toDate, const Room& room, const bool allRooms = false);                // Same as the reservedSeatsReference function.

    void printTicketOfficeManual() const;
};

#endif
