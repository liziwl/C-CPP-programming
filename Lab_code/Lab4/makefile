all: lab4

lab4: main.cpp ChineseYear.hpp ChineseYear.o
	g++ -o lab4 main.cpp ChineseYear.o

ChineseYear.o: ChineseYear.cpp ChineseYear.hpp
	g++ -c -o ChineseYear.o ChineseYear.cpp
