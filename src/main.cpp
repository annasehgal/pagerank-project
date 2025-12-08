// Name: Anna Sehgal
/* This project covers the implementation of Pagerank*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "graph.h"
#include "pagerank.h"
#include "util.h"
using namespace std;
int main (){
  Graph gr;
  Util::builder(gr); // make the graph
  Pagerank runpagerank(0.85, 1e-6, 100); // on damping factor 0.85 , convergence, max 
  runpagerank.simulate(gr);
  Util::ranker(gr); // score of each node on graph
  return 0;
}
