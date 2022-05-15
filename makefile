# Add dependencies to main:
main: main.o ./String/String.o ./Date/Date.o ./Room/Room.o ./Ticket/Ticket.o ./Show/Show.o ./TicketOffice/TicketOffice.o
	g++ -g -o main main.o ./String/String.o ./Date/Date.o ./Room/Room.o ./Ticket/Ticket.o ./Show/Show.o ./TicketOffice/TicketOffice.o

# Add header files used in main:
main.o: main.cpp ./String/String.h ./Date/Date.h ./Room/Room.h ./Ticket/Ticket.h ./Show/Show.h ./Vector/Vector.h ./TicketOffice/TicketOffice.h
	g++ -c main.cpp

# Add header files used in ./String/String.o:
String.o: ./String/String.h

#Add header files used in ./Date/Date.o:
Date.o: ./Date/Date.h

#Add header files used in ./Room/Room.o:
Room.o: ./Room/Room.h

#Add header files used in ./Show/Show.o:
Show.o: ./Show/Show.h

#Add header files used in ./Vector/Vector.o:
Vector.o: ./Vector/Vector.h

#Add header files used in ./TicketOffice/TicketOffice.o:
TicketOffice.o: ./TicketOffice/TicketOffice.h

#Add clean functionality:
clean:
	rm ./String/String.o ./Date/Date.o ./Room/Room.o ./Ticket/Ticket.o ./Show/Show.o ./TicketOffice/TicketOffice.o
