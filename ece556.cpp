// ECE556 - Copyright 2014 University of Wisconsin-Madison.  All Rights Reserved.

#include <iostream>
#include <fstream>
#include "ece556.h"

// Reference for routingInst struct
//  typedef struct
  //  {
    //   int gx ;             /* x dimension of the global routing grid */
    //   int gy ;             /* y dimension of the global routing grid */

    //   int cap ;

    //   int numNets ;        /* number of nets */
    //   net *nets ;          /* array of nets */

    //   int numEdges ;       /* number of edges of the grid */
    //   int *edgeCaps;       /* array of the actual edge capacities after considering for blockages */
    //   int *edgeUtils;      /* array of edge utilizations */

    //  } routingInst ;

int readBenchmark(const char *fileName, routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/
  std::ofstream myfile;
  myfile.open(fileName);
  myfile << "readBenchmark file\n";
  myfile.close();
  
  return 1;
}

int solveRouting(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}

int writeOutput(const char *outRouteFile, routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/
  std::ofstream myfile;
  myfile.open(outRouteFile);
  myfile << "writeOutput file\n";
  myfile.close();
  
  return 1;
}


int release(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/
  if (!rst) return 0; // failure if rst is NULL

  // free all memory structures in rst
  free(rst->nets);
  free(rst->edgeCaps);
  free(rst->edgeUtils);
  // free rst memory structure
  free(rst);
  return 1; // success!
}
  

