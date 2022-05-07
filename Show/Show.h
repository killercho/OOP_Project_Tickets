#ifndef SHOW_H
#define SHOW_H

#include "../Date/Date.h"
#include "../Room/Room.h"
#include "../String/String.h"
#include "../Ticket/Ticket.h"

class Show {
private:
    String name;
    Room room;
    Date date;
    Ticket** seats;

    void copy(const String& name, const Room& room, const Date& date, Ticket** seats);
    void copy(const String& name, const Room& room, const Date& date);
    void deleteMem();

public:
    Show(const String& name, const Room& room, const Date& date);
    Show(const Show& other);
    Show& operator=(const Show& other);
    ~Show();

    String getName() const;
    Room getRoom() const;
    Date getDate() const;
};
#endif
