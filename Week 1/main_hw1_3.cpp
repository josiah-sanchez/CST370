/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw1_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_3.cpp
 * Abstract: Write a program that converts user directed graph data into
 * a corresponding adjacency list.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/08/2022
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numVertices, numEdges, head, tail;
    vector<pair<int, int>> edge;

    cin >> numVertices;
    cin >> numEdges;

    int vertices[numVertices];
    
    //occupy vector holding vertices
    for (int i=0; i < numVertices; i++) {
      vertices[i] = i;
    }

    //create edges and occupy vector of pairs
    for (int i = 0; i < numEdges; i++) {
      cin >> head >> tail;
      edge.push_back(make_pair(head, tail));
    }

    sort(edge.begin(), edge.end());

    for (int i = 0; i < numVertices; i++) {
      cout << vertices[i];
      for (int j = 0; j < numEdges; j++) {
        if (edge[j].first == vertices[i])
          cout << "->" << edge[j].second;
      }

      cout << endl;
    }
    
    
  
    return 0;
}

