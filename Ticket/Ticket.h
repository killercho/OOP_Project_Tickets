#ifndef TICKET_H
#define TICKET_H

#include "../String/String.h"

/**
 *  A Ticket class used to store information about the ticket.
 * */
class Ticket {
private:
    size_t seat;
    size_t row;
    String description; //!< The description that the user can enter during reservation.
    String password;    //!< The password used when reserving and buying a ticket.
    short isReserved;   //!< Short variable to store the ticket state. 0 when the ticket is free. 1 when the ticket is reserved. 2 when the ticket is bought.

public:
    Ticket(size_t row = 0, size_t seat = 0, String password = "", String description = "");

    void increaseReservedState(); //!< A function used to change the state of the ticket from 0 -> 1 or from 1 -> 2.
    void clearReservedState();    //!< Changes the state to 0 and clears the description and password.

    short getReservedState() const;
    size_t getSeat() const;
    size_t getRow() const;
    String getDescription() const;
    String getPassword() const;

    void setPassword(const String& pass);
    void setDescription(const String& desc);

    friend std::ostream& operator<<(std::ostream& os, const Ticket& other); //!< Overrides the '<<' operator allowing writing in a binary file.
    friend std::istream& operator>>(std::istream& is, Ticket& other);       //!< Overrides the '>>' operator allowing reading from a binary file.
};

#endif
