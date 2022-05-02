# Add dependencies to main:
main: main.o ./String/String.o ./Date/Date.o ./Room/Room.o
	g++ -o main main.o ./String/String.o ./Date/Date.o ./Room/Room.o

# Add header files used in main:
main.o: main.cpp ./String/String.h ./Date/Date.h ./Room/Room.h
	g++ -c main.cpp

# Add header files used in ./String/String.o:
String.o: ./String/String.h

#Add header files used in ./Date/Date.o:
Date.o: ./Date/Date.h

#Add header files used in ./Room/Room.o:
Room.o: ./Room/Room.h
