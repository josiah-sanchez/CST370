/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw2_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_2.cpp
 * Abstract: Write a program that takes a set input by the user and display
 * decimal numbers, binary numbers, and all subsets on individual lines.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/14/2022
 */

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

string decToBin(int n, int size){
    string binary = "";
    for (int i = size - 1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            binary += "1";
        else
            binary += "0";
    }

    return binary;
}


int main()
{
    string input;
    string ready = "";
    int size;
    int pos = 0;

    cin >> size;
    cin.ignore(256, '\n');
    string set[size];

    if (size == 0) {
      cout << "0:0:EMPTY" << endl;
    } 
    else {
  
      getline(cin, input);

      for (int i = 0; i <= input.size(); i++) {
        if (input[i] == ' ') {
          set[pos] = ready;
          ready = "";
          pos++;
        } 
        else if (i == input.size()) {
          set[pos] = ready;
        }
        else {
          ready += input[i];
        }
      }

      cout << "0:" << setw(size) << setfill('0') << "0" << ":EMPTY" << endl;

      int numSub = pow(2, size);
      string subset = "";
      
      for (int i = 1; i < numSub; i++) {
        string binary = decToBin(i, size);
        cout << i << ':' << binary << ':';
        
        for (int j = 0; j < size; j++) {
          if (binary[j] == '1'){
            subset += set[j] + ' ';
          }
        }

        subset = subset.substr(0, subset.length() - 1);
        cout << subset << endl;
        subset = "";
      }

    }
  
    return 0;
}

