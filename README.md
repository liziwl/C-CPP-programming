# C/C++programming
Course codes and material, Summer 2017 in SUSTech

## Lab1
1.	To get familiar with the environment write a very simple program that reads your name and Student ID from the keyboard, and outputs “Welcome XXX to the C and C++ world” on the screen. XXX is your name and Student ID. ( 2 points)
2.	Initialize the shifted alphabet table of Vigenere encoding and display it on the screen. (3 points)
3.	Using “ Vigenere” as a key, encrypt the ouput from task1 (just encrypt the alpha, keep other characters unchanged). Hint: You can use a Unix pipe so that the output of task1 becomes the in input of task3 (5 points)
### OPTIONAL
1.	Perform encryption using only letter computations and without using the shifted alphabet table as indicated in LAB1_SUBJECT.(2 points)
2.	Decode encoded text as indicated in LAB1_SUBJECT.(2 points) Try it on the output of task3 and check that you get back the output of task1.

## Lab2
You are provided for testing with a big file called unidata.csv (coming from a US government website) with the list of higher-education institutes in the US, as well as a spreadsheet describing the data.

Your program will use Unix-style flags to specify some options. The function to use for processing options is called [getopt()](https://linux.die.net/man/3/getopt) and man 3 getopt provides explanations as well as a complete example ("3" is required, there is another getopt in section 1 of the manual). You can copy, paste and adapt the example.

You are asked to implement two flags:
* -s followed by the separator used (default separator: one space)
* -i followed by the number of lines to ignore (default: 0). You may have lines to ignore when the first line(s) contains headers, not data. It’s the case in the sample file that is provided.
### Example:
If you just want to extract from unidata.csv the state abbreviation (STABBR, 5th field) whether the institution is active (CYACTIVE, 39th field) and the institutional category (INSTCAT, 45th filed), you should enter the command (I’m calling the program extract, you can give it any name you want):

extract -s ',' -i 1 5 39 45 < unidata.csv
* -s ',' means that the separator is a comma.
* -i 1 means to ignore (skip) the first line.

## Lab3

## Lab4
You are provided with a .hpp file to complete, a .cpp file to complete, and a main.cpp that you mustn't modify and is exactly what will be used to test your code. Additionally, you get a makefile. For grading, we'll compare the output with your classes to a known result.

The class that is implemented is a ChineseYear class. You are asked to write constructors, and functions and methods to write them to a stream, and to add to them a number of years. The detail is in comments in the code that is supplied.

By default, it will implicitly be the current 12-year cycle.

An information that will be useful: 1900 (remember that the field tm_year in a struct tm is the year minus 1900) was a year of the Rat, and therefore the beginning of a 12-year cycle. It can be helpful for finding out which animal corresponds to a year.