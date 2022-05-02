# Add dependencies to main:
main: main.o ./utils/String.o ./utils/Date.o
	g++ -o main main.o ./utils/String.o ./utils/Date.o

# Add header files used in main:
main.o: main.cpp ./utils/String.h ./utils/Date.h
	g++ -c main.cpp

# Add header files used in ./uitls/String.o:
String.o: ./utils/String.h

#Add header files used in ./utils/Date.o:
Date.o: ./utils/Date.h
