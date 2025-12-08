// Name: Anna Sehgal
#ifndef UTIL_H
#define UTIL_H
#include "graph.h"
class Util {
    public:
    static void builder(Graph& gr); // makes the graph
    static void ranker(const Graph& gr);// outputs ranks
};
#endif