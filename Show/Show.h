#ifndef SHOW_H
#define SHOW_H

#include "../Date/Date.h"
#include "../Room/Room.h"
#include "../String/String.h"
#include "../Ticket/Ticket.h"
#include "../Vector/Vector.h"

/**
 * A Show class used to store infromation about the shows.
 * */
class Show {
private:
    String name;                  //!< Name of the show of type String.
    Room room;                    //!< The room, where the show is showed, of type Room.
    Date date;                    //!< The date at which the show is being showed.
    Vector<Vector<Ticket>> seats; //!< Vector of vectors of tickets, imitating a Ticket** type. Used to create all the avaluable seats in the room for that show.

    static const Room DEFAULT_ROOM;     //!< Default value for the room. Used in the default constructor.
    static const Date DEFAULT_DATE;     //!< Default value for the date. Used in the default constructor.
    static const String DEFAULT_STRING; //!< Default value for the name. Used in the default constructor.

public:
    Show(const String& name = DEFAULT_STRING, const Room& room = DEFAULT_ROOM, const Date& date = DEFAULT_DATE);

    String getName() const;
    Room getRoom() const;
    Date getDate() const;

    bool operator==(const Show& other) const;                         //!< Operator '==' used to check if a show is the same as another show.
    bool isRoomFree(const Date& checkDate) const;                     //!< Checks if the room is free on the date given as an argument. Returns true if the room is free.
    bool isSeatTaken(const size_t row, const size_t seatOnRow) const; //!< Checks if that seat on that row is already taken. Returns true if the seat is free

    /**
     * Function used to reserve a ticket on the specific row and seat. Reserving a seat requires the user to enter a password as well.
     * Entering a description is optional.
     * After that the function changes the state of the ticket from 0 -> 1 and saves the password and description in that specific ticket.
     * In the end the function returns a String used to convey any errors or the successful transaction.
     */
    String reserveTicket(const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");

    /**
     * Function used to remove the reservation of a seat.
     * To remove the reservation the user needs to enter the row and seat which he reserved, then enter the password used for reservation.
     * If the user entered a description he/she needs to enter that as well. But since it's optional the default value is "".
     * After all the infromation is correct the state of the ticket goes back to 0, meaning unreserved.
     * In the end the function returns a String used to convey any errors or the successful transaction.
     */
    String removeReservation(const size_t row, const size_t seatOnRow, const String& password, const String& desc = "");

    /**
     * Function used to buy a ticket on a specific seat on a row.
     * If the user wants to buy an unreserved spot the password is not needed, then the function without the 'password' argument is called.
     * In the opposite case the function with 'password' argument is called.
     * Returns 0 if the tansaction passed.
     * Returns 1 if the seat is taken.
     * Returns 2 if the password is wrong.
     * Returns 3 if the user tried to buy a reserved ticket without entering a password.
     */
    short buyTicket(const size_t row, const size_t seatOnRow);
    short buyTicket(const size_t row, const size_t seatOnRow, const String& password);

    size_t freeSeats() const;   //!< Returns the number of unreserved and not bought seats in a 'size_t' type.
    size_t reserveList() const; //!< Returns the number of reserved seats in a 'size_t' type.
    size_t boughtList() const;  //!< Returns the number of bought seats in a 'size_t' type.
};
#endif
