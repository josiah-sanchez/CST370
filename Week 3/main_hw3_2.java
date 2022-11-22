/*
 * INSTRUCTION:
 *     This is a Java staring code for hw3_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw3_2.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw3_2.java
 * Abstract: Write a program that takes user graph data and outputs the 
 * shortest path for the TSP problem.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/22/2022
 */

import java.util.*;
class Main 
{  
    public static void Permute(int[] input, int startindex, int startVert, int[][] edges) 
    {
        int size = input.length;
        Integer[] path = new Integer[size+1];
        int distance = 0;
        List<Integer[]> list;
        list = new ArrayList<Integer[]>();
        int pos = 0;

        if (size == startindex + 1) 
        {
          if (startVert == input[0]){
              for (int i = 0; i < size; i++) 
              {
                  if (i != size-1)
                    System.out.print(input[i] + "->");
                  else
                    System.out.print(input[i]);
                  
                  path[i] = input[i];
              }
              System.out.println();
          }
       } 
        else 
        {
            for (int i = startindex; i < size; i++) 
            {
                int temp = input[i];
                input[i] = input[startindex];
                input[startindex] = temp;

                Permute(input, startindex + 1, startVert, edges);
                temp = input[i];
                input[i] = input[startindex];
                input[startindex] = temp;
            }
        }
    }
  
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        int numVertices = keyboard.nextInt();
        int numEdges = keyboard.nextInt();
        int distance;
        int[] vertices = new int[numVertices];
        int[][] edges = new int[numEdges][3];
        int counter = 0;
        int[][] map = new int[numVertices][numVertices];

        for (int i=0; i < numVertices; i++){
          vertices[i] = i;
        }

        for (int i=0; i < numEdges; i++){
          for (int j=0; j < 3; j++){
            edges[i][j] = keyboard.nextInt();
          }
        }

        Arrays.sort(edges, Comparator.comparingDouble(o -> o[0]));
        // System.out.println(Arrays.deepToString(edges));

        while (counter < numVertices) {
          for (int i=counter; i < numEdges; i++){
            
            if (counter == edges[i][0])
              map[counter][(edges[i][1])] = edges[i][2];
          }
          // System.out.println(Arrays.deepToString(map));
          counter++;
        }
        
      

        int start = keyboard.nextInt();
        Permute(vertices, 0, start, edges);
    }
}

