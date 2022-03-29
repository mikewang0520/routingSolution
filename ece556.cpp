// ECE556 - Copyright 2014 University of Wisconsin-Madison.  All Rights Reserved.

#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "ece556.h"

using namespace std;

int readBenchmark(const char *fileName, routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  // open read file
  ifstream myfile;
  myfile.open(fileName, ios::in);

  // ensure file is open
  if (!myfile.is_open()) return 0;

  // read x and y dimensions of global routing grid
  string line;
  getline(myfile, line); // read line
  stringstream linestream(line); // define linestream
  string item; // define
  getline(linestream, item, ' '); // token 0 ("grid")
  getline(linestream, item, ' '); // token 1 (gx)
  rst->gx = stoi(item);
  getline(linestream, item, ' '); // token 2 (gy)
  rst->gy = stoi(item);
  linestream.str("");
  linestream.clear();

  // read capacity number
  getline(myfile, line); // read line
  linestream.str(line);
  getline(linestream, item, ' '); // token 0 ("capacity")
  getline(linestream, item, ' '); // token 1 (cap)
  rst->cap = stoi(item);
  linestream.str("");
  linestream.clear();

  // read numNets
  getline(myfile, line); // read line
  linestream.str(line);
  getline(linestream, item, ' '); // token 0 ("num")
  getline(linestream, item, ' '); // token 1 ("net")
  getline(linestream, item, ' '); // token 2 (numNets)
  rst->numNets = stoi(item);
  linestream.str("");
  linestream.clear();

  // allocate space for nets
  rst->nets = (net*) malloc(rst->numNets * sizeof(net));

  // read all pins of all nets (nested for loop)
  for (int i = 0; i < rst->numNets; ++i) {
    // iterate over all nets
    getline(myfile, line); // read line
    linestream.str(line);
    getline(linestream, item, ' '); // token 0 (netName (e.g. "n0"))
    int netid = stoi(item.substr(1)); // extracts number from "n0"
    rst->nets[i].id = netid;
    getline(linestream, item, ' '); // token 1 (numPins)
    int numPins = stoi(item);
    rst->nets[i].numPins = numPins;
    linestream.str("");
    linestream.clear();

    // allocated per-net space for pins
    rst->nets[i].pins = (point*) malloc(rst->nets[i].numPins * sizeof(point));
    
    for (int j = 0; j < rst->nets[i].numPins; ++j) {
      // iterate over all pins within a net
      getline(myfile, line); // read line
      linestream.str(line);
      getline(linestream, item, ' '); // token 0 (x)
      rst->nets[i].pins[j].x = stoi(item);
      getline(linestream, item, '\t'); // token 1 (y)
      rst->nets[i].pins[j].y = stoi(item);
      linestream.str("");
      linestream.clear();
    }
  }

  // calculate and store numEdges
  rst->numEdges = ((rst->gy) * ((rst->gx)-1)) + ((rst->gx) * ((rst->gy)-1));

  // BLOCKAGE READING GOES HERE (???)
  
  // clean up and return
  //myfile.close();
  return 1;
}

// This function creates a routing solution
int solveRouting(routingInst *rst)
{
  /*********** TO BE FILLED BY YOU **********/
  
  for(int i=0; i < rst->numNets; ++i){
    // iterate through all nets
    net myNet = rst->nets[i];

    // there will be 1 less segment than there are pins
    // (e.g. 3 pins will only need 2 segments to connect)
    myNet.nroute.numSegs = myNet.numPins - 1;

    // allocate memory for segments
    myNet.nroute.segments = (segment*) malloc(myNet.nroute.numSegs * sizeof(segment));
    
    for(int j = 0; j < myNet.nroute.numSegs; ++j){
      // a segment is formed from a pin and its next pin in net
      point pin1 = myNet.pins[j];
      point pin2 = myNet.pins[j+1];
      
      int xgap = pin2.x - pin1.x;
      int ygap = pin2.y - pin1.y;

      // allocate memory for minimum number of edges
      myNet.nroute.segments[j].numEdges = xgap + ygap;
      myNet.nroute.segments[j].edges = (int*) malloc(myNet.nroute.segments[j].numEdges * sizeof(int));
      
      // pins have horizontal gap
      for (int k = 0; k < xgap; ++k) {
	// add horizontal edge to segment
	
      }
      
      // pins have vertical gap
      for (int k = 0; k < ygap; ++k) {
	// add horizontal edge to segment
	
      }
    }
  }
  return 1;
}

// Write the routing solution
int writeOutput(const char *outRouteFile, routingInst *rst)
{
  //declare file stream variable
  ofstream fileOut;
  //open the output file
  fileOut.open(outRouteFile);


  // write net segments to fileOut
  for (int i=0; i< rst->numNets; ++i) // enumerates through nets
  {
    char *string = (char *)malloc(1000 * sizeof(char));
    if (!string) {
      fputs ("ERR: memory allocation for string failed", stderr);
      exit (EXIT_FAILURE);
    }

    for (int j=0; j < rst->nets[i].nroute.numSegs; ++j) // enumerates through endpoints of routes
    {
      sprintf(string, "(%d,%d)-(%d,%d)\n",
	      rst->nets[i].nroute.segments[j].p1.x, rst->nets[i].nroute.segments[j].p1.y,
	      rst->nets[i].nroute.segments[j].p2.x, rst->nets[i].nroute.segments[j].p2.y
	      );
      fileOut << string;
    }

    free(string);
  }

  
  //close the output file
  fileOut.close();
  return 1;
}


/** 
 * Need to recursively delete all memory allocations from 
 * bottom to top (e.g., starting from segments, then routes
 * then individual fields within a net struct, then the
 * nets, then the fields in a routing instance, and finally
 * the routing instance) 
 */

// Release memory used
// NOTE: do these need to be in for loops?
int release(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/
  if (!rst) return 0; // failure if rst is NULL
  
  
  // NOTE: THESE ALL CURRENTLY SEGFAULT RIGHT NOW
  
  
  // release all edges (???)
  if (rst->nets->nroute.segments->edges) // SEGFAULT OOPS LOL
    free(rst->nets->nroute.segments->edges);
  else
    cout << "No edges??" << endl;
  
  // release all segments
  if (rst->nets->nroute.segments)
    free(rst->nets->nroute.segments);
  else
    cout << "No segments??" << endl;
  
  // release all routes (???)
  //free(rst->nets->nroute);

  // release all fields within net struct
  if (rst->nets->pins)
    free(rst->nets->pins);
  else
    cout << "No pins??" << endl;

  // release all nets
  if (rst->nets)
    free(rst->nets);
  else
    cout << "No nets??" << endl;
  
  // release fields within routing instance
  if (rst->edgeCaps)
    free(rst->edgeCaps);
  else
    cout << "No edgeCaps??" << endl;
  if (rst->edgeUtils)
    free(rst->edgeUtils);
  else
    cout << "No edgeUtils??" << endl;
  
  // release the routing instance
  free(rst);

  return 1; // success!
}
