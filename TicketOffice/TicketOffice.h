#ifndef TICKET_OFFICE_H
#define TICKET_OFFICE_H

#include "../Show/Show.h"

/**
 * A TicketOffice class that stores information about all the shows an office can have.
 * */
class TicketOffice {
private:
    Vector<Show> shows; //!< Vector of Show that imitates a Show* type. Used to store all the shows.

    size_t searchedShowIndex(const Date& date, const String& name); //!< Used to search for the index of the show in 'shows' with a given date and name.
    size_t searchedShowIndex(const Date& date, const Room& room);   //!< Used to search for the index of the show in 'shows' with a given date and room.

public:
    /**
     * Adds a show in the vector, using the date, name and room.
     * Returns false if the room is for that show is taken on that date, then the adding is not done.
     * Returns true if the operation succeeded.
     * */
    bool addShow(const Date& date, const String& name, const Room& room);

    /**
     * A function that reserves a ticket on a given seat and row for a show on a given date with a given name.
     * The reservation requires a password.
     * Adding a description is optional.
     * In the end the function returns a String type, used to convey any errors or the success of the function.
     */
    String reserveTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");

    /**
     * A function that removes a reservation for a ticket on a given seat and row for a show on a given date with a given name.
     * The removal of a reservation requires a password.
     * Adding a description is optional, depending on whether the user entered a description when reserving the ticket.
     * In the end the function returns a String type, used to convey any errors or the success of the function.
     */
    String removeReservation(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");

    /**
     * A function used to buy a ticket on a given seat and row for a show on a given date with a given name.
     * If the user tries to buy a reserved spot then the function with 'password' argument should be called.
     * In the other case when the user tries to buy a free spot, the function without a 'password' argument should be called.
     * Returns -1 if the show is not in the vector.
     * Returns 0 if the tansaction passed.
     * Returns 1 if the seat is taken.
     * Returns 2 if the password is wrong.
     * Returns 3 if the user tried to buy a reserved ticket without entering a password.
     * */
    short buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow);
    short buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password);

    size_t freeSeatsReport(const Date& date, const String& name); //!< Returns the number of the free seats on that date for a show with that name, in a type 'size_t'.
    /**
     * A function that saves the number of the reserved seats, for a given date and name, in a file.
     * The file name is 'report-DATE-NAME.txt'.
     * If the user enters ALL when asked for a date then the 'allDates' flag is switched to true and the file includes the shows with that name from all dates.
     *  If the user enters ALL when asked for a name then the 'allNames' flag is switched to true and the file includes the shows from that date with all names.

     * */
    void reservedSeatsReport(const Date& date, const String& name, const bool allDates = false, const bool allNames = false);

    /**
     * A function that prints the number of bought seats for a given period of time for a given room.
     * If the user entered 'ALL' when asked for the room, the 'allRooms' flag is switched to true, the programme prints a report for that period for all rooms separately.
     * When the function is called with the 'allRooms' flag with value true, the function has to be called with the 'roomsArr' and 'roomCount' arguments representing the array of all the rooms and the number of those rooms.
     * In the end the function returns true if the function succeeded and false if the first date was more than the second date (meaning the 'fromDate' is after the 'toDate' and the period is not valid).
     * */
    bool boughtSeatsReport(Date& fromDate, const Date& toDate, const Room& room = Room(), const bool allRooms = false, const Room* roomsArr = nullptr, const size_t roomCount = 0);

    void printTicketOfficeManual() const; //!< Prints the main menu.
};

#endif
