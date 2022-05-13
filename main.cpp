#include "TicketOffice/TicketOffice.h"

#include <fstream>

using namespace std;

const Room avaluableRooms[] = { Room(7, 4), Room(8, 15), Room(9, 16), Room(6, 10) };

Date enterDate()
{
    Date date;
    unsigned dateBuff;
    cin >> dateBuff;
    date.setDay(dateBuff);
    cin >> dateBuff;
    date.setMonth(dateBuff);
    cin >> dateBuff;
    date.setYear(dateBuff);
    return date;
}

String enterString()
{
    char nameBuff[1024];
    cin.get();
    cin.getline(nameBuff, 1024);
    String name(nameBuff);
    return name;
}

void addShowInput(TicketOffice& ticketOffice)
{
    cout << "\nYou have selected 'Add a new show'. To add a new show we need the date, name and room from the programme!\n";
    cout << "Please enter a date in the following format 'dd mm yyyy' (where 'dd' is the day, 'mm' is the month and 'yyyy' is the year, and the devisor is a space): ";
    Date date = enterDate();

    cout << "Great! Now we need the name of the show: ";
    String name = enterString();

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
    Date date = enterDate();

    cout << "Now enter the name of the show: ";
    String name = enterString();

    size_t freeSeats = ticketOffice.freeSeatsReport(date, name);
    if (freeSeats != -1)
        cout << "The free seats for the show " << name << " on "
             << date.getStringDay() << "/" << date.getStringMonth() << "/" << date.getStringYear()
             << " are " << freeSeats << ".\n";
    else
        cout << "The show with that name on that date was not found! Please double check the name and the date and try again.\n";
}

void reserveTicket(TicketOffice& ticketOffice)
{
    cout << "You have selected the 'Reserve ticket option'.\n";
    cout << "To be able to reserve a ticket you need to enter a date (using the same format): ";
    Date date = enterDate();

    cout << "Now enter the name of the show: ";
    String name = enterString();

    cout << "Enter the row and seat you want with the following format 'r s' (where 'r' is row and 's' is the seat on the row, using space as a delimiter): ";
    size_t row, seat;
    cin >> row >> seat;

    cout << "For the reservation we need you to make a password and remember it to confirm your purchase later. \n";
    cout << "Please enter a password: ";
    String password = enterString();

    cout << "Adding a description to the ticket is optional. If you want to add a description enter '1'.\n";
    cout << "Keep in mind that if you enter a description then you need to remember it to remove the reservation.\n";
    cout << "If you think adding a description is pointless enter '2': ";
    char descriptionOption;
    cin >> descriptionOption;
    String desc;
    if (descriptionOption == '1') {
        cout << "Enter a description (not more than 1024 symbols and on one line): ";
        desc = enterString();
    }

    cout << ticketOffice.reserveTicket(date, name, row, seat, password, desc) << '\n';
}

void removeReservation(TicketOffice& ticketOffice)
{
    cout << "You have selected the 'Remove reservation option'.\n";
    cout << "To remove the reservation enter the same data you entered when making the reservation.\n";
    cout << "Start with the date, using the same format: ";
    Date date = enterDate();

    cout << "Now enter the name of the show: ";
    String name = enterString();

    cout << "Enter the row and seat you want with the following format 'r s' (where 'r' is row and 's' is the seat on the row, using space as a delimiter): ";
    size_t row, seat;
    cin >> row >> seat;

    cout << "Please enter a password: ";
    String password = enterString();

    cout << "If you added a description enter '1' and you will be able to write it again here.\n";
    cout << "If you didn't add a description enter '2'.\n";
    cout << "Enter option now: ";
    char descriptionOption;
    cin >> descriptionOption;
    String desc = "";
    if (descriptionOption == '1') {
        cout << "Enter a description (not more than 1024 symbols and on one line): ";
        desc = enterString();
    }

    cout << ticketOffice.removeReservation(date, name, row, seat, password, desc);
}

void buyTicket(TicketOffice& ticketOffice)
{
    cout << "You have selected the 'Buy ticket' option.\n";
    cout << "To buy a ticket you need to enter the date of the show, using the same format: ";
    Date date = enterDate();

    cout << "Now enter the name of the show: ";
    String name = enterString();

    cout << "Enter the row and seat you want with the following format 'r s' (where 'r' is row and 's' is the seat on the row, using space as a delimiter): ";
    size_t row, seat;
    cin >> row >> seat;

    cout << "If you have reserved a ticked before and want to buy it enter '1', if you want to buy an unreserved spot enter '2': ";
    char buyingOption;
    cin >> buyingOption;
    short response;
    if (buyingOption == '1') {
        cout << "Now you have to enter the password you used in the reservation stage: ";
        String password = enterString();
        response = ticketOffice.buyTicket(date, name, row, seat, password);
    } else
        response = ticketOffice.buyTicket(date, name, row, seat);

    switch (response) {
    case -1: {
        cout << "The transaction did not pass.\n";
        break;
    }
    case 0: {
        cout << "The transaction passed!\n";
        break;
    }
    case 1: {
        cout << "The seat you are trying to buy has already been bought!\n";
        break;
    }
    case 2: {
        cout << "The entered password is wrong!\n";
        break;
    }
    case 3: {
        cout << "The ticket you are trying to buy is reserved. If you want to buy it you have to enter a password!\n";
        break;
    }
    }
}

void saveReservationsReport(TicketOffice& ticketOffice)
{
    cout << "You have selected 'Save reservations report to a file'!\n";
    cout << "If you want to get the report about all dates you can enter 'ALL', if you want a specific date enter 'NOALL': ";
    String checkDateDesire = enterString();
    if (checkDateDesire == "ALL") {
        cout << "Now enter the name of the show: ";
        char nameBuff[1024];
        cin.getline(nameBuff, 1024);
        String name(nameBuff);
        ticketOffice.reservedSeatsReport(Date(), name, true, false);
    } else {
        cout << "If you want to get the report about all names you can enter 'ALL', if you want a specific name enter 'NOALL': ";
        char nameBuff[1024];
        cin.getline(nameBuff, 1024);
        String checkNameDesire(nameBuff);
        if (checkNameDesire == "ALL") {
            cout << "Enter the date: ";
            Date date = enterDate();
            ticketOffice.reservedSeatsReport(date, String(), false, true);
        } else {
            cout << "Enter the date of the show: ";
            String name = enterString();
            cout << "Enter the name of the show: ";
            Date date = enterDate();
            ticketOffice.reservedSeatsReport(date, name, false, false);
        }
    }
    cout << '\n';
}

int main()
{
    TicketOffice ticketOffice;

    /*
    Date date;
    String name("something");
    ticketOffice.addShow(date, name, avaluableRooms[0]);
    ticketOffice.buyTicket(date, name, 1, 1);
    ticketOffice.reservedSeatsReport(date, name);
*/

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
            reserveTicket(ticketOffice);
            break;
        }
        case '4': {
            removeReservation(ticketOffice);
            break;
        }
        case '5': {
            buyTicket(ticketOffice);
            break;
        }
        case '6': {
            saveReservationsReport(ticketOffice);
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
