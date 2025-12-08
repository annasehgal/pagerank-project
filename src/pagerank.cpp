// Name: Anna Sehgal
#include "pagerank.h"
#include <cmath>
#include <vector>
#include <memory>
#include "graph.h"
#include "Node.h"
using namespace std;
Pagerank::Pagerank(double damp, double eps, int maxIter) : dampingfactor(damp), e(eps) {// damping factor, convergence, and max it for simulation
  //nothing
}
// sim
void Pagerank::simulate(Graph& gr) {
    int n = gr.noofnodes();
    if (n == 0){
      return;
    }
    const vector<shared_ptr<Node>>& pages = gr.findedge(); // nodes 
    size_t start =0;
    while (start<pages.size()){
        pages[start]->setterrank(1.0 / double(n)); // Initialize all ranks to 1 / n
        pages[start]->setternextrank(0.0);
        start++;
    }
    int it = 0;
    int maxit = 100; // default, can adjust if needed

    while (it < maxit){
        bool converged = true;
        double dsum = 0.0; // sum of ranks of nodes with no outgoing edges
        start = 0;
        while (start < pages.size()) {
            if (pages[start]->nodeout().empty()) {
                dsum += pages[start]->ranknow();
            }
            start++;
        }
        start = 0; // next rank of node
        while (start<pages.size()){
            Node* node = pages[start].get();
            double nextr = (1.0 - dampingfactor) / double(n); // tepseport
            nextr= nextr + (dampingfactor * dsum / double(n)); // dangling contrib
            vector<int> inNodes = node->nodein(); // in edge contrib
            size_t st = 0;
            while (st < inNodes.size()){
                int u = inNodes[st];
                shared_ptr<Node> inNode = gr.accessnode(u);
                vector<int> outNeighbors = inNode->nodeout();
                size_t outDegree = outNeighbors.size();
                if (outDegree > 0) {
                    nextr = nextr + (dampingfactor * inNode->ranknow() / double(outDegree));
                }
                st++;
            }
            node->setternextrank(nextr); 
            start++;
        }
        start = 0; // add next rank and
        while (start < pages.size()){
            double oldRank = pages[start]->ranknow();
            double newRank = pages[start]->ranknext();
            if (fabs(newRank - oldRank) > e) {
                converged = false; // check converge
            }
            pages[start]->addnextiterationrank();//move nextRank to ranknow
            pages[start]->resetaddnextscore(); 
            start++;
        }
        if (converged){
          break;
        }
        it++;
    }
    double sum = 0.0; // normalize part to 1
    start = 0;
    while (start < pages.size()) {
        sum += pages[start]->ranknow();
        start++;
    }
    if (sum > 0.0) {
        start = 0;
        while (start < pages.size()) {
            pages[start]->setterrank(pages[start]->ranknow() / sum);
            start++;
        }
    }
}