/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_1.cpp
 * Abstract: Write a program that takes two timestaps  and display the difference
 * between them.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/14/2022
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    string eventOne, eventTwo;
    int hoursOne, hoursTwo, minutesOne, minutesTwo, secondsOne, secondsTwo;
    int difference[3];
    
    cin >> eventOne;
    cin >> eventTwo;

    hoursOne = stoi(eventOne.substr(0,2));
    minutesOne = stoi(eventOne.substr(3, 5));
    secondsOne = stoi(eventOne.substr(6, eventOne.length()));
    
    hoursTwo = stoi(eventTwo.substr(0,2));
    minutesTwo = stoi(eventTwo.substr(3, 5));
    secondsTwo = stoi(eventTwo.substr(6, eventTwo.length()));

    if (hoursOne > hoursTwo) {
      hoursTwo = hoursTwo + 24;
    }

    difference[0] = abs(hoursOne - hoursTwo);

    if (minutesOne > minutesTwo) {
      difference[0] = difference[0] - 1;
      minutesTwo = minutesTwo + 60;
    }

    difference[1] = abs(minutesOne - minutesTwo);

    if (secondsOne > secondsTwo) {
      secondsTwo = secondsTwo + 60;
      difference[1] = difference[1] - 1;
    }

    difference[2] = abs(secondsOne - secondsTwo);

    cout << setw(2) << setfill('0') << difference[0] << ":"; 
    cout << setw(2) << setfill('0') << difference[1] << ":"; 
    cout << setw(2) << setfill('0') << difference[2] << endl;
  

    return 0;
}

