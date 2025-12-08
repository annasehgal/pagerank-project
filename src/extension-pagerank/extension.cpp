// Name: Anna Sehgal
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "extension.h"
using namespace std;
// constructor
Extension::Extension(Graph& graph) : g(graph) {
    n = g.noofnodes();
}
// log CSV of scorenow
void Extension::logiteration(int iter, const string& filename){
    ofstream file(filename, iter == 0 ? ios::out : ios::app);
    const vector<shared_ptr<Node>>& nodes = g.findedge();
    file << iter;
    size_t i = 0;
    while (i < nodes.size()){
        file << "," << fixed << setprecision(6) << nodes[i]->ranknow();
        i++;
    }
    file << "\n";
    file.close();
}
// norm sum = 1
void Extension::normalizeranks(){
    double sum = 0.0;
    const vector<shared_ptr<Node>>& nodes = g.findedge();
    size_t i = 0;
    while (i < nodes.size()){
        sum += nodes[i]->ranknow();
        i++;
    }
    if (sum > 0.0){
        i = 0;
        while (i < nodes.size()){
            nodes[i]->setterrank(nodes[i]->ranknow() / sum);
            i++;
        }
    }
}
// run PageRank with logging and rank pages
void Extension::runextendedpagerank(double damping, double epsilon, int maxiter, const string& logfile, int topk){
    const vector<shared_ptr<Node>>& nodes = g.findedge();
    size_t i = 0;
    while (i < nodes.size()){ // init
        nodes[i]->setterrank(1.0 / n);
        nodes[i]->setternextrank(0.0);
        i++;
    }
    int iter = 0;
    while (iter < maxiter){
        bool converged = true;
        // dangling mass
        double dangling_sum = 0.0;
        i = 0;
        while (i < nodes.size()){
            if (nodes[i]->nodeout().empty()) dangling_sum += nodes[i]->ranknow();
            i++;
        }

        i = 0;
        while (i < nodes.size()){
            Node* node = nodes[i].get();
            double nextrank = (1.0 - damping)/n + damping * dangling_sum / n;

            vector<int> inneighbors = node->nodein();
            size_t j = 0;
            while (j < inneighbors.size()){
                int u = inneighbors[j];
                shared_ptr<Node> inNode = g.accessnode(u);
                size_t outdeg = inNode->nodeout().size();
                if (outdeg > 0){
                    nextrank += damping * inNode->ranknow() / static_cast<double>(outdeg);
                }
                j++;
            }

            node->setternextrank(nextrank);
            i++;
        }
        // rank and converge check
        i = 0;
        while (i < nodes.size()){
            double oldrank = nodes[i]->ranknow();
            double newrank = nodes[i]->ranknext();
            if (abs(newrank - oldrank) > epsilon) converged = false;
            nodes[i]->addnextiterationrank();
            nodes[i]->resetaddnextscore();
            i++;
        }
        // csv visual
        logiteration(iter, logfile);
        // dynamic sorting
        vector<shared_ptr<Node>> sortednodes = nodes;
        sort(sortednodes.begin(), sortednodes.end(), [](const shared_ptr<Node>& a, const shared_ptr<Node>& b){
            return a->ranknow() > b->ranknow();
        });
        cout << "Iteration " << iter << " top nodes: ";
        int count = 0;
        while (count < topk && count < sortednodes.size()){
            cout << sortednodes[count]->nodeID() << "(" << sortednodes[count]->ranknow() << ") ";
            count++;
        }
        cout << endl;
        if (converged) break;
        iter++;
    }
    normalizeranks();
}
