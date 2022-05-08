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

public:
    Show(const String& name, const Room& room, const Date& date);

    String getName() const;
    Room getRoom() const;
    Date getDate() const;
};
#endif
