#include "Show/Show.h"

#include <fstream>

using namespace std;

int main()
{
    String name("show1");
    Room room(5, 10);
    Date date(4, 6, 2002);

    Show show(name, room, date);
    cout << "Success!";
}
