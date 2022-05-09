#include "Show/Show.h"
#include "Ticket/Ticket.h"
#include "TicketOffice/TicketOffice.h"
#include "Vector/Vector.h"

#include <fstream>

using namespace std;

int main()
{
    String name("show1");
    Room room(5, 10);
    Date date(24, 10, 2022);

    TicketOffice ticketOffice;
    ticketOffice.addShow(date, name, room);

    ticketOffice.reservedSeatsReport(date, name);
    ticketOffice.reserveTicket(date, name, 1, 1, "blah");
    cout << '\n';
    ticketOffice.reservedSeatsReport(date, name);
}
