/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw1_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_1.cpp
 * Abstract: Write a program that reads integer inputs from the user
 * and displays the closest distance between two numbers among all inputs.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/07/2022
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> pairs;
    int size;
    int min;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++){
      cin >> array[i];
    }

    int n = sizeof(array) / sizeof(array[0]);
    sort(array, array + n);

    for (int i=0; i < n; i++) {
      int currentDist = abs(array[i+1] - array[i]);
      
      if (i == 0) {
        min = abs(array[i+1] - array[i]);
        pairs.push_back(make_pair(array[i], array[i+1]));
        
      } 
      else if (currentDist == min) {
        pairs.push_back(make_pair(array[i], array[i+1]));
        
      } 
      else if (currentDist < min) {
        min = array[i+1] - array[i];
        pairs.erase(pairs.begin() + pairs.size());
        pairs.push_back(make_pair(array[i], array[i+1]));
      }
    }
  
    cout << "Min Distance:" << min << endl;

    for (int i = 0; i < pairs.size(); i++) {
      cout << "Pair:" << pairs[i].first << " " << pairs[i].second << endl;
    }

    return 0;
}

