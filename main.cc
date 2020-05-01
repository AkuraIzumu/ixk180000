/*                                                                              
 *  Filename: main.cc                                                           
 *  Date: April 29 2020                                                           
 *  Author: Ism Khadka                                                          
 *  Email: ixk180000@utdallas.edu                                               
 *  Course: CS 3377.501                                                         
 *  Version: 1.0                                                                
 *  Copyright 2020, All Rights Reserved                                         
 *                                                                              
 *  Description:                                                                
 *           Prints the matrix and displays contents int he binary file                                                                   
 *                                                                              
 */
#include <iostream>
#include "cdk.h"
#include "bin.h"

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"0","a", "b", "c"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"0","a", "b", "c", "d", "e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      return 0;
      
    }
  else{
    
    drawCDKMatrix(myMatrix, true);
    binary(myMatrix);
    drawCDKMatrix(myMatrix, true);    /* required  */

    /* so we can see results */
    string x = "";
    cin >> x; 
    
	  
  }
    // Cleanup screen
  endCDK();
}
