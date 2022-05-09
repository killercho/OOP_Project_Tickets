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
    if (searchedShowIndex(date, room) != -1)
        return false;
    shows.push(Show(name, room, date));
    return true;
}

bool TicketOffice::reserveTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return false;

    shows[showIndex].reserveTicket(row, seatOnRow, password, desc);
    return true;
}

void TicketOffice::removeReservation(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password, const String& desc)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return;
    shows[showIndex].removeReservation(row, seatOnRow, password, desc);
}

void TicketOffice::buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return;
    shows[showIndex].buyTicket(row, seatOnRow);
}

void TicketOffice::buyTicket(const Date& date, const String& name, const size_t row, const size_t seatOnRow, const String& password)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return;
    shows[showIndex].buyTicket(row, seatOnRow, password);
}

void TicketOffice::freeSeatsReport(const Date& date, const String& name)
{
    size_t showIndex = searchedShowIndex(date, name);
    if (showIndex == -1)
        return;
    shows[showIndex].freeSeats();
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
        dateString += date.getStringYear(); // TODO: Fix the segmentation fault here!
    } else
        dateString = "ALL";

    reportFileName += dateString;
    std::cout << reportFileName;
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

void TicketOffice::boughtSeatsReport(const Date& fromDate, const Date& toDate, const Room& room, const bool allRooms)
{
    if (fromDate > toDate)
        return;
    if (!allRooms) {
        while (!(fromDate == toDate)) {
            size_t index = searchedShowIndex(fromDate, room);
            std::cout << "The show " << shows[index].getName() << " has sold " << shows[index].boughtList() << " tickets.";
        }
    } else {
        while (!(fromDate == toDate)) {
            for (size_t i = 0; i < shows.getSize(); ++i) {
                std::cout << "The show " << shows[i].getName() << " has sold " << shows[i].boughtList() << " tickets.";
            }
        }
    }
}
