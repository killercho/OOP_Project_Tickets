#include "TicketOffice/TicketOffice.h"

#include <fstream>

using namespace std;

const Room avaluableRooms[] = { Room(7, 4), Room(8, 15), Room(9, 16), Room(6, 10) };

void addShowInput(TicketOffice& ticketOffice)
{
    cout << "\nYou have selected 'Add a new show'. To add a new show we need the date, name and room from the programme!\n";
    cout << "Please enter a date in the following format 'dd mm yyyy' (where 'dd' is the day, 'mm' is the month and 'yyyy' is the year, and the devisor is a space): ";
    Date date;
    unsigned dateBuff;
    cin >> dateBuff;
    date.setDay(dateBuff);
    cin >> dateBuff;
    date.setMonth(dateBuff);
    cin >> dateBuff;
    date.setYear(dateBuff);

    cout << "Great! Now we need the name of the show: ";
    char nameBuff[1024];
    cin.get();
    cin.getline(nameBuff, 1024);
    String name(nameBuff);

    unsigned avaluableRoomsCount = (sizeof(avaluableRooms) / sizeof(Room));
    cout << "The last thing needed is the room in which the show is going to be showed. \n";
    cout << "There are currently " << avaluableRoomsCount << " avaluable rooms. \n";
    cout << "Keep in mind that some rooms might not be avaluable on the date you select!\n";
    cout << "Choose a room entering a number between 1 and " << avaluableRoomsCount << ": ";
    short roomIndex;
    cin >> roomIndex;
    if (!ticketOffice.addShow(date, name, avaluableRooms[roomIndex - 1]))
        cout << "Adding failed! There is a show in the same room on the same date!\n";
    else
        cout << "Successfully added a show on "
             << date.getStringDay() << "/" << date.getStringMonth() << "/" << date.getStringYear()
             << ", in room number " << roomIndex
             << " with name " << name << ".\n\n";
}

void printFreeSeatsReport(TicketOffice& ticketOffice)
{
    cout << "You have selected 'Show free seats report'.\n";
    cout << "Please enter the date you wish to check the free seats on in the following format "
         << "'dd mm yyyy' \n(where 'dd' is the day, 'mm' is the month and 'yyyy' is the year, and the devisor is a space): ";
    Date date;
    unsigned dateBuff;
    cin >> dateBuff;
    date.setDay(dateBuff);
    cin >> dateBuff;
    date.setMonth(dateBuff);
    cin >> dateBuff;
    date.setYear(dateBuff);

    cout << "Now enter the name of the show: ";
    char nameBuff[1024];
    cin.get();
    cin.getline(nameBuff, 1024);
    String name(nameBuff);

    size_t freeSeats = ticketOffice.freeSeatsReport(date, name);
    if (freeSeats != -1)
        cout << "The free seats for the show " << name << " on "
             << date.getStringDay() << "/" << date.getStringMonth() << "/" << date.getStringYear()
             << " are " << freeSeats << ".\n";
    else
        cout << "The show with that name on that date was not found! Please double check the name and the date and try again.\n";
}

int main()
{
    TicketOffice ticketOffice;

    bool menuActive = true;
    while (menuActive) {
        ticketOffice.printTicketOfficeManual();
        char command;
        cin >> command;

        switch (command) {
        case '1': {
            addShowInput(ticketOffice);
            break;
        }
        case '2': {
            printFreeSeatsReport(ticketOffice);
            break;
        }
        case '3': {
            break;
        }
        case '4': {
            break;
        }
        case '5': {
            break;
        }
        case '6': {
            break;
        }
        case '7': {
            break;
        }
        case '8': {
            menuActive = false;
            break;
        }
        }
    }
}
