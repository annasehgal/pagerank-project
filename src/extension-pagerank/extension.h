// Name: Anna Sehgal
#ifndef EXTENSION_H
#define EXTENSION_H
#include <vector>
#include <string>
#include "../graph.h"
using namespace std;
class Extension {
private:
    Graph& g; // reference to the graph
    int n;    // total nodes
    void logiteration(int iter, const string& filename); //log CSV
    void normalizeranks(); //rank sum=1
public:
    Extension(Graph& graph);
    // run PageRank with convergence logging and rank top 3 pages
    void runextendedpagerank(double damping = 0.85, double epsilon = 1e-6, int maxiter = 100, const string& logfile = "pagerank_log.csv", int topk = 3);
};
#endif