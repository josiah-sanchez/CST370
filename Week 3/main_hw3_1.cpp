/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_1.cpp
 * Abstract: Write a program that reads a designated amount of
 * input numbers and displays them in ascending order.
 * Consecutive numbers should be truncated.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/20/2022
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool consecutive(int first, int second){
  if (first - second == 1)
    return true;
  else
    return false;
}

bool isVect(vector<vector<int>> vector, int number){
  bool in = false;
  for (int i=0; i < vector.size(); i++){
    for (int j=0; j < vector[i].size(); j++){
      if (number == vector[i][j])
        in = true;
    }
  }

  return in;
}

int main()
{
    vector<vector<int>> consec;
    int counter = 0;
    int size;
    cin >> size;

    int input[size];
    for (int i=0; i < size; i++){
      cin >> input[i];
    }

    int n = sizeof(input) / sizeof(input[0]);
    sort(input, input + n);
  
    for (int i = 0; i < size; i++){ 
      vector<int> temp;
      
      for (int j = 0; j < size; j++){
        if (consecutive(input[j], input[j-1])){
          temp.push_back(input[j]);
          if (input[j-1] != temp[counter-1])
            temp.push_back(input[j-1]);
        } 
        
        if (!consecutive(input[j], input[j-1]) && !temp.empty()){
          temp.erase(unique(temp.begin(), temp.end()), temp.end());
          sort(temp.begin(), temp.end());
          temp.erase(unique(temp.begin(), temp.end()), temp.end());
          consec.push_back(temp);
          temp.clear();
        }

        if (!temp.empty() && j == size-1){
          temp.erase(unique(temp.begin(), temp.end()), temp.end());
          sort(temp.begin(), temp.end());
          temp.erase(unique(temp.begin(), temp.end()), temp.end());
          consec.push_back(temp);
          temp.clear();
        }
      }
    }
    
    if (!consec.empty()) {
      sort(consec.begin(), consec.end());
      consec.erase(unique(consec.begin(), consec.end()), consec.end());
  
      counter = 0;
      while (counter < size) {
        if (!isVect(consec, input[counter])){
          if (counter == size-1)
            cout << input[counter] << endl;
          else{
            cout << input[counter] << " ";
          }
        }
        else{
          for (int pos=0; pos < consec.size(); pos++){
            if (input[counter] == consec[pos].front()){
              cout << consec[pos].front() << "-" << consec[pos].back();
              if (pos == size-1)
                cout << endl;
              else
                cout << ' ';
            }
          }
        }

        counter++;
      }
    }
    else {
      for (int i = 0; i < size; i++){
        if (i == size-1)
          cout << input[i] << endl;
        else
          cout << input[i] << ' ';
      }
    }

    cout << endl;
    return 0;
}
