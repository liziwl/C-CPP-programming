#ifndef _CHINESE_YEAR_HPP
#define _CHINESE_YEAR_HPP

#include <iostream>

class ChineseYear {
    private:
        std::string _animal;
        int         _greg;   // Gregorian year (eg 2017)
                // This is the year when the Chinese New Year took place

    public:
        // Here are two exceptions that you can use
        class WrongChineseYear:std::exception {
            public:
              virtual const char * what(void) const throw () {
                 return "Invalid Chinese Year";
              }
        };

        class WrongGregorianYear:std::exception {
            public:
              virtual const char * what(void) const throw () {
                 return "Invalid Gregorian Year (must be >= 1900)";
              }
        };

        // Constructors
        ChineseYear();
        ChineseYear(std::string animal); // Exception if invalid animal
        ChineseYear(int year); // Exception if the year isn’t >= 1900

        // Friend function
        // The proper way to display a Chinese Year in this program is
        // the animal name, followed by a space, followed by the Gregorian
        // when the Chinese Year started, followed by a minus signed and
        // followed by the Gregorian year when the Chinese year ended.
        // Gregorian years should be on 4 digits.
        // For instance
        //     “Rooster 2017-2018”
        // Strictly respect this, because the output of the program will be
        // tested by scripts and it has to be exactly as expected.
        friend std::ostream &operator<<(std::ostream &os,
                                        const ChineseYear &cy);

        // You are asked to implement operator+=(), to add a number of years
        // to a ChineseYear, as well as operator+() to implement addition between
        // a ChineseYear and a number of years (the difference? in the first case 
        // the variable is modified, in the second case it’s not modified).
        // Don’t forget that chinese_year + x could also be written 
        // x + chinese_year …
        // It’s up to you to decide whether to use methods or friend functions.
        friend ChineseYear &operator+=(ChineseYear &cy, const int x);
        friend ChineseYear &operator+(const int x, ChineseYear &cy);
        friend ChineseYear &operator+(ChineseYear cy, const int x);

};

#endif
