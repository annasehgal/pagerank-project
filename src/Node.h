// Name: Anna Sehgal
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
using namespace std;
// a single page is considered as a node
// from my understanding of pagerank, each node is a unique id, it has a rank which updates based on iteration
// furthermore, each node has incoming and outgoing edges
class Node{
    private: 
    int id; // each page is unique and has an id or domain name like www.x.com
    double scorenow; // this is the score currently, basically the pagerank
    double scorenext; // after the next iteration, this score is updated for each node,
    vector<int>outarrow; // links outgoing from the page
    vector<int>inarrow; // links towards the page

    public:
    // these functions have consts so they can be fixed at all time and not edited
    Node(int id);// constructor function for basic init of each webpage
    int nodeID() const; // it will always be the same name
    double ranknow() const;
    double ranknext() const;
    const vector<int>& nodeout() const;
    const vector<int>& nodein() const;
    void arrowoutside(int v);
    void arrowin(int u);
    void setterrank(double score);
    void setternextrank(double score);
    void addnextiterationrank();
    void resetaddnextscore();   
};
#endif 