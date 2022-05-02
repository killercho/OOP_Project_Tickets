# Add dependencies to main:
main: main.o ./utils/String.o
	g++ -o main main.o ./utils/String.o

# Add header files used in main:
main.o: main.cpp ./utils/String.h
	g++ -c main.cpp

# Add header files used in ./uitls/String.o:
String.o: ./utils/String.h

