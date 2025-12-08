// Name: Anna Sehgal
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <memory>
#include "Node.h"
using namespace std;
class Graph{
    private: 
    vector<shared_ptr<Node>> webpages;
    public: 
    // constructo
    Graph() = default;
    void insertnode(int id); // new node/page added
    shared_ptr<Node> accessnode(int id) const;
    int noofnodes() const; 
    void clear();// reset graph
    void insertedge(int start, int end); // direct edge
    vector<shared_ptr<Node>>& findedge() const;// list of all edge
    int noofedges() const;
    vector<int>out(int pageid) const; //arrows outside a node
    vector<int>in(int pageid) const; // arrows towards a node
    void makeG(); // builder ofgraph

};
#endif