// Name: Anna Sehgal
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include "../graph.h"
#include "../Node.h"
#include "extension.h"
using namespace std;
namespace fs = std::filesystem;

// run it like: g++ -std=c++17 -o pagerank main.cpp Node.cpp graph.cpp extension.cpp
// then ./pagerank
// The program automatically runs the first few test files from ../../tests/ (around 4–5), 
// showing iteration logs, top nodes per iteration, and final PageRanks, 
// then lets the user enter their own custom graph at the last one


int main() {
    // from /tests/
    string path = "../../tests/";
    string pattern = "tests";

    for (const auto& entry : fs::directory_iterator(path)) {
        string filename = entry.path().string();
        if (filename.find(pattern) != string::npos && filename.find(".in") != string::npos) {
            cout << "\nProcessing file: " << filename << "\n";
            ifstream infile(filename);
            if (!infile.is_open()) {
                cout << "Failed to open " << filename << "\n";
                continue;
            }
            Graph g;
            int n, m;
            infile >> n;
            for (int i = 0; i < n; i++) g.insertnode(i);
            infile >> m;
            for (int i = 0; i < m; i++) {
                int u, v;
                infile >> u >> v;
                g.insertedge(u, v);
            }
            infile.close();
            size_t i = 0;
            while (i < g.noofnodes()) {
                shared_ptr<Node> node = g.accessnode(i);
                cout << "Node " << node->nodeID() << " links to: ";
                vector<int> outs = g.out(node->nodeID());
                for (size_t j = 0; j < outs.size(); j++) cout << outs[j] << " ";
                cout << " | linked from: ";
                vector<int> ins = g.in(node->nodeID());
                for (size_t j = 0; j < ins.size(); j++) cout << ins[j] << " ";
                cout << "\n";
                i++;
            }
            // run
            Extension ext(g);
            string logfile = filename + "_pagerank.csv";
            ext.runextendedpagerank(0.85, 1e-6, 100, logfile, 3);
            cout << "Final ranks:\n";
            i = 0;
            while (i < g.noofnodes()) {
                shared_ptr<Node> node = g.accessnode(i);
                cout << "Node " << node->nodeID() << " = " << node->ranknow() << "\n";
                i++;
            }
        }
    }
    // manual
    cout << "\nEnter your own graph:\n";
    Graph g;
    int n, m;
    cout << "Number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) g.insertnode(i);
    cout << "Number of edges: ";
    cin >> m;
    cout << "Enter edges (from to):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.insertedge(u, v);
    }
    // custom graph
    size_t i = 0;
    while (i < g.noofnodes()) {
        shared_ptr<Node> node = g.accessnode(i);
        cout << "Node " << node->nodeID() << " links to: ";
        vector<int> outs = g.out(node->nodeID());
        for (size_t j = 0; j < outs.size(); j++) cout << outs[j] << " ";
        cout << " | linked from: ";
        vector<int> ins = g.in(node->nodeID());
        for (size_t j = 0; j < ins.size(); j++) cout << ins[j] << " ";
        cout << "\n";
        i++;
    }
    Extension ext(g);
    string logfile = "custom_graph_pagerank.csv";
    ext.runextendedpagerank(0.85, 1e-6, 100, logfile, 3);
    cout << "Final ranks:\n";
    i = 0;
    while (i < g.noofnodes()) {
        shared_ptr<Node> node = g.accessnode(i);
        cout << "Node " << node->nodeID() << " = " << node->ranknow() << "\n";
        i++;
    }
    return 0;
}