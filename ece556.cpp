// ECE556 - Copyright 2014 University of Wisconsin-Madison.  All Rights Reserved.
#include <fstream>
#include "ece556.h"

// Reads in the benchmark file and initializes the routing instance
// This function needs to populate some fields in the routingInst structure
int readBenchmark(const char *fileName, routingInst *rst)
{
  /*********** TO BE FILLED BY YOU **********/
  //declare file stream variable
  ofstream fileIn;
  //open the input file
  fileIn.open(fileName);
  //wirte to the input file
  fileOut << ;
  //close the input file
  fileIn.close(); 
  return 1;
}

// This function creates a routing solution
int solveRouting(routingInst *rst)
{
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}

// Write the routing solution
int writeOutput(const char *outRouteFile, routingInst *rst)
{
  /*********** TO BE FILLED BY YOU **********/
  //declare file stream variable
  ofstream fileOut;
  //open the output file
  fileOut.open(outRouteFile);
  //wirte to the output file
  fileOut << "";
  //close the output file
  fileOut.close();
  return 1;
}

// Release memory used
int release(routingInst *rst)
{
  /*********** TO BE FILLED BY YOU **********/
  free(rst);
  return 1;
}
