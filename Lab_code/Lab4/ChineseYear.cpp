#include <iostream>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <string>

#include "ChineseYear.hpp"

#define CYCLE_YEARS    12

using namespace std;

// Casts to silence compilation warnings
static char *G_animals[CYCLE_YEARS + 1] = 
                    {(char *)"Rat",
                     (char *)"Ox",
                     (char *)"Tiger",
                     (char *)"Rabbit",
                     (char *)"Dragon",
                     (char *)"Snake",
                     (char *)"Horse",
                     (char *)"Goat",
                     (char *)"Monkey",
                     (char *)"Rooster",
                     (char *)"Dog",
                     (char *)"Pig",
                     NULL};

//
// --   Utility functions
//
static int animal_pos(string animal) {
    int         i = 0;
    const char *a = animal.c_str();

    G_animals[CYCLE_YEARS] = (char *)a;
    while (strcasecmp(G_animals[i], (char *)a)) {
      i++;
    }
    if (i == CYCLE_YEARS) {
      return -1;
    }
    return i;
}

static bool valid_animal(string animal) {
    return (animal_pos(animal) == -1 ? false : true);
}

static string animal(int pos) {
    if ((pos >= 0) && (pos < CYCLE_YEARS)) {
      return string(G_animals[pos]);
    }
    return NULL;
}

// 
// From now on, it’s you turn to write the code for constructors,
// operators and friend functions …`
//
ChineseYear::ChineseYear(){}

ChineseYear::ChineseYear(std::string animal) {
	if (false==valid_animal(animal))
		throw ChineseYear::WrongChineseYear();
	int index = animal_pos(animal);
	_animal = string(G_animals[index]);

	time_t tt; 
	struct tm * timeinfo;
	tt = time (NULL);
	timeinfo = localtime ( &tt );
	int toyear;
	toyear = timeinfo->tm_year; //year after 1900 == current - 1900
	toyear = toyear/CYCLE_YEARS;

	_greg = toyear*CYCLE_YEARS+index+1900;
}

ChineseYear::ChineseYear(int year) {
	if (year<1900)
		throw ChineseYear::WrongGregorianYear();
	_greg = year;
	int index = (year-1900)%CYCLE_YEARS;
	_animal = animal(index);
}

std::ostream &operator<<(std::ostream &os, const ChineseYear &cy) {
	int year = cy._greg;
	os << cy._animal << " " << year << "-" << year+1;
	return os;
}

ChineseYear &operator+=(ChineseYear &cy, const int x) {
    cy._greg += x;
    cy._animal = animal((cy._greg-1900)%CYCLE_YEARS);
    return cy;
}

ChineseYear &operator+(const int x, ChineseYear &cy) {
	ChineseYear *cynew = new ChineseYear(x+cy._greg);
	return *cynew;
}

ChineseYear &operator+(ChineseYear cy, const int x) {
	ChineseYear *cynew = new ChineseYear(x+cy._greg);
	return *cynew;
}