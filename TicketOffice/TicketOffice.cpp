#include "TicketOffice.h"
#include <fstream>

size_t TicketOffice::searchedShowIndex(const Date& date, const String& name)
{
    for (size_t i = 0; i < shows.getSize(); ++i) {
        if (name == shows[i].getName() && date == shows[i].getDate())
            return i;
    }
    return -1;
}

size_t TicketOffice::searchedShowIndex(const Date& date, const Room& room)
{
    for (size_t i = 0; i < shows.getSize(); ++i) {
        if (room == shows[i].getRoom() && date == shows[i].getDate())
            return i;
    }
    return -1;
}

bool TicketOffice::addShow(const Date& date, const String& name, const Room& room)
{
    if (searchedShowIndex(date, room) != -1 || !date.getIsDateCorrect())
        return false;
    shows.push(Show(name, room, date));
    return true;
}

String TicketOffice::reserveTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return "No show has been found! Please double check your data!\n";

    return shows[showIndex].reserveTicket(row, seatOnRow, password, desc);
}

String TicketOffice::removeReservation(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return "Show was not found in the database! Please double check your input information and try again.\n";
    return shows[showIndex].removeReservation(row, seatOnRow, password, desc);
}

short TicketOffice::buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return -1;
    return shows[showIndex].buyTicket(row, seatOnRow);
}

short TicketOffice::buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return -1;
    return shows[showIndex].buyTicket(row, seatOnRow, password);
}

size_t TicketOffice::freeSeatsReport(const Date& date, const String& name)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return -1;
    return shows[showIndex].freeSeats();
}

void TicketOffice::reservedSeatsReport(const Date& date, const String& name, const bool allDates, const bool allNames)
{
    size_t result = 0;
    if (allDates) {
        for (size_t i = 0; i < shows.getSize(); ++i) {
            if (shows[i].getName() == name)
                result += shows[i].reserveList();
        }
    } else if (allNames) {
        for (size_t i = 0; i < shows.getSize(); ++i) {
            if (shows[i].getDate() == date)
                result += shows[i].reserveList();
        }
    } else {
        size_t showIndex = searchedShowIndex(date, name);
        if (showIndex == -1)
            return;
        result = shows[showIndex].reserveList();
    }

    String reportFileName("report-");
    String reportName = (allNames ? "ALL" : name);
    reportFileName += reportName;
    reportFileName += "-";
    String dateString;
    if (!allDates) {
        dateString += date.getStringDay();
        dateString += "-";
        dateString += date.getStringMonth();
        dateString += "-";
        dateString += date.getStringYear();
    } else
        dateString = "ALL";

    reportFileName += dateString;
    reportFileName += ".txt";

    std::ofstream file(reportFileName.getStr());
    file << "\nThe reservations(not paid but not free) on ";
    if (allDates)
        file << "ALL";
    else
        file << date;
    file << " for the show " << reportName << " are " << result;
    file.close();
}

bool TicketOffice::boughtSeatsReport(Date& fromDate, const Date& toDate, const Room& room, const bool allRooms, const Room* roomsArr, const size_t roomCount)
{
    if (fromDate > toDate)
        return false;
    if (!allRooms) {
        do {
            size_t index = searchedShowIndex(fromDate, room);
            if (index != -1)
                std::cout << "The show " << shows[index].getName()
                          << " on " << fromDate.getStringDay() << "/" << fromDate.getStringMonth() << "/" << fromDate.getStringYear()
                          << " has sold " << shows[index].boughtList() << " tickets.\n";
            fromDate.increaseDay();
        } while (!(fromDate == toDate));
    } else {
        do {
            for (size_t i = 0; i < roomCount; ++i) {
                size_t index = searchedShowIndex(fromDate, roomsArr[i]);
                if (index != -1) {
                    size_t boughtCount = shows[index].boughtList();
                    if (boughtCount != 0)
                        std::cout << "The show " << shows[index].getName()
                                  << " on " << fromDate.getStringDay() << "/" << fromDate.getStringMonth() << "/" << fromDate.getStringYear()
                                  << " has sold " << shows[index].boughtList() << " tickets.\n";
                }
            }
            fromDate.increaseDay();
        } while (!(fromDate == toDate));
    }
    return true;
}

void TicketOffice::printTicketOfficeManual() const
{
    using namespace std;
    cout << "\nMain menu!\n";
    cout << "To enter a command please use the following guide: \n";
    cout << "To add a new show to the Ticket Office please enter '1'!\n";
    cout << "To print a report about the free seats in a room for a given show please enter '2'!\n";
    cout << "To reserve a ticket for a given show please enter '3'!\n";
    cout << "To remove a reservation please enter '4'!\n";
    cout << "To buy a ticket for a given show please enter '5'!\n";
    cout << "To save a local copy of the report considering reservations made please enter '6'!\n";
    cout << "To print a report about the bought tickets please enter '7'!\n";
    cout << "To exit the menu and close the program please enter '8'!\n";
    cout << "Enter desired command now: ";
}
