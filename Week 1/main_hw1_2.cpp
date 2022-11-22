/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw1_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_2.cpp
 * Abstract: This program reads inputs from the user and then displays the number(s)
 * that occurs the most frequently among all the input numbers.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/07/2022
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<int, int>> frequency;
    vector<int> matches;
    int size; 
    int mostFrequent = 0; 
    int numMatches;
    cin >> size;

    int array[size];
    for (int i=0; i < size; i++) {
      cin >> array[i];
    }

    int n = sizeof(array) / sizeof(array[0]);
    sort(array, array + n);

    for (int i=0; i < n; i++) {
      numMatches = 0;
      for (int j=i; j < n; j++) {
        if (array[i] == array[j]) {
          numMatches++;
        }
      }

      frequency.push_back(make_pair(numMatches, array[i]));
    }
  
    for (int i=0; i < frequency.size(); i++) {
      int currentFreq = frequency[i].first;
      
      if (i == 0){
        mostFrequent = frequency[i].first;
        matches.push_back(frequency[i].second);
      }
      else if (mostFrequent == frequency[i].first) {
        matches.push_back(frequency[i].second);
      } 
      else if (currentFreq > mostFrequent) {
        mostFrequent = frequency[i].first;
        matches.clear();
        matches.push_back(frequency[i].second);
      }
    }

    sort(matches.rbegin(), matches.rend());

    cout << "Frequency:" << mostFrequent << endl;
    cout << "Number:";
    for (int i=0; i < matches.size(); i++) {
      if (i == 0)
        cout << matches[i];
      else
        cout << " " << matches[i];
    }

    cout << endl;
  
    return 0;
}

