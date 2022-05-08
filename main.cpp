#include "Show/Show.h"
#include "Ticket/Ticket.h"
#include "Vector/Vector.h"

#include <fstream>

using namespace std;

int main()
{
    String name("show1");
    Room room(5, 10);
    Date date(1, 1, 2022);

    Show show(name, room, date);

    cout << show.isRoomFree(Date(1, 2, 2022));
    cout << '\n'
         << show.isRoomFree(Date(1, 1, 2022));
    cout << '\n'
         << show.reserveTicket(0, 0, "123", "description");
    cout << '\n'
         << show.reserveTicket(0, 0, "bum");
    cout << '\n'
         << show.reserveTicket(1, 2, "2");
    cout << '\n'
         << show.buyTicket(1, 2, "bu");
    cout << '\n'
         << show.removeReservation(0, 0, "123");
    cout << '\n'
         << show.buyTicket(0, 0);

    cout << '\n'
         << show.freeSeats();
}
