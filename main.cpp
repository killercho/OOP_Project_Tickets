#include "Date/Date.h"
#include "Room/Room.h"
#include "Show/Show.h"
#include "String/String.h"
#include "Ticket/Ticket.h"

#include <fstream>

using namespace std;

int main()
{
    String name("show1");
    Room room(5, 10);
    Date date(4, 6, 2002);
    Show show1(name, room, date);

    // cout << show1.getName() << '\n';
}
