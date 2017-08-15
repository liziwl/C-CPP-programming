#include <iostream>

#include "ChineseYear.hpp"

using namespace std;

int main() {
    // Test 1: Create a new Chinese Year with an animal
    ChineseYear cy1 = ChineseYear("Tiger");
    // Test 2: Create a new Chinese Year with a year
    ChineseYear cy2 = ChineseYear(2015);
    // Test 3: Create a default Chinese Year
    ChineseYear cy3;
    // Test 4: Create a wrong Chinese Year
    cout << "Trying the year of the Panda" << endl;
    try {
        ChineseYear cy3 = ChineseYear("Panda");
    } catch (ChineseYear::WrongChineseYear &e) {
        cerr << e.what() << endl;
    }
    // Test 5: Display cy1, cy2 and cy3
    cout << "cy1 = " << cy1 << ", cy2 = " << cy2 << ", cy3 = "<< cy3 << endl;
    // Test 6: Increment cy1 and display
    cy1 += 1;
    cout << "cy1 = " << cy1 << endl;
    // Test 7: Add 3 to cy2 and display
    cout << "cy2 + 3 = " << cy2  + 3 << endl;
    // Test 8: Add 5 to cy2 and display, different order
    cout << "5 + cy2 = " << 5 + cy2 << endl;
    return 0;
}
