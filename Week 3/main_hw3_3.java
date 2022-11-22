/*
 * INSTRUCTION:
 *     This is a Java staring code for hw3_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw3_3.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw3_3.java
 * Abstract: Write a program that implements the depth-first algorithm using a stack
 * and mark array as learned in class.
 * ID: 1914
 * Name: Josiah Sanchez
 * Date: 03/22/2022
 */

import java.util.*;

class Main 
{
    
    
    public static void main(String[] args) {
        int numVert;
        int numEdges;
        Scanner keyboard = new Scanner(System.in);

        numVert = keyboard.nextInt();
        numEdges = keyboard.nextInt();

        boolean[] visited = new boolean[numVert];
        int[] order = new int[numVert];
        for (int i=0; i < numVert; i++){
          visited[i] = false;
        }

        int[] v = new int[numEdges];
        int[] w = new int[numEdges];
        for (int i=0; i < numEdges; i++){
          v[i] = keyboard.nextInt();
          w[i] = keyboard.nextInt();
        }

        
    }
}

