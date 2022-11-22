/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw2_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_3.cpp
 * Abstract: Write a program that checks if an string is a palindrome or not.
 * Ignore all case and remove non-alphanumeric characters. Must use recursive
 * function.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/15/2022
 */

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool palindrome(string input, int start, int end) {
  if (start == end)
    return true;

  if (input[start] != input[end])
    return false;

  return palindrome(input, start + 1, end - 1);
}

int main()
{
    string input;
    int counter = 0;

    getline(cin, input);
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
  
    while (counter < input.length()) {
      input[counter] = toupper(input[counter]);
      counter++;
    }

    for (int i = 0; i < input.length(); i++) {
      if ((input[i] < 'A' || input[i] > 'Z') && (input[i] < '0' || input[i] > '9')){
        input.erase(i, 1);
        i--;
      }
    }
  
    if (palindrome(input, 0, input.length() - 1))
      cout << "TRUE";
    else
      cout << "FALSE";
  
    return 0;
}

