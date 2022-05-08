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
    cout << show.getName();
}
