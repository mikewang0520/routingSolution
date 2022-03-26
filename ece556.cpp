// ECE556 - Copyright 2014 University of Wisconsin-Madison.  All Rights Reserved.

#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "ece556.h"

using namespace std;

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
  /*
  std::ofstream myfile;
  myfile.open(fileName);
  myfile << "readBenchmark file\n";
  myfile.close();
  */

  // open read file
  ifstream myfile;
  myfile.open(fileName, ios::in);

  // ensure file is open
  if (!myfile.is_open()) return 0;

  // read x and y dimensions of global routing grid
  string line;
  getline(myfile, line); // read line
  stringstream linestream(line);
  string item;
  getline(linestream, item, ' '); // token 0 (garbage)

  getline(linestream, item, ' '); // token 1
  rst->gx = stoi(item);
  getline(linestream, item, ' '); // token 2
  rst->gy = stoi(item);

  //
  
  // clean up and return
  myfile.close();
  return 1;
}

int solveRouting(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}

int writeOutput(const char *outRouteFile, routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/
  ofstream myfile;
  myfile.open(outRouteFile);
  myfile << "writeOutput file\n";
  myfile.close();
  
  return 1;
}


/**
 * Need to recursively delete all memory allocations from
 * bottom to top (e.g., starting from segments then routes
 * then individual fields within a net struct, then the
 * nets, then the fields in a routing instance, and finally
 * the routing instance)
 */

// NOTE: do these need to be in for loops?
int release(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/
  if (!rst) return 0; // failure if rst is NULL

  // release all edges (???)
  free(rst->nets->nroute.segments->edges);

  // release all segments
  free(rst->nets->nroute.segments);
  
  // release all routes (???)
  //free(rst->nets->nroute);

  // release all fields within net struct
  free(rst->nets->pins);

  // release all nets
  free(rst->nets);
  
  // release fields within routing instance
  free(rst->edgeCaps);
  free(rst->edgeUtils);
  
  // release the routing instance
  free(rst);

  return 1; // success!
}
  

