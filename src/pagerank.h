// name: Anna Sehgal
#ifndef PAGERANK_H
#define PAGERANK_H
#include "graph.h"
class Pagerank{
    private:
    double dampingfactor; // normallhy it is 0.85
    double e; // convergence thresehold is this
    public:
    // constructor
    Pagerank(double damp = 0.85, 
        double eps = 1e-6, 
        int maxIter = 100);
    void running(Graph& gr);

};
#endif