# Add dependencies to main:
main: main.o ./MyString/MyString.o
	g++ -o main main.o ./MyString/MyString.o

# Add header files used in main:
main.o: main.cpp ./MyString/MyString.h
	g++ -c main.cpp

# Add header files used in ./MyString/MyString.o:
MyString.o: ./MyString/MyString.h

