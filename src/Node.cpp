// Name: Anna Sehgal
#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;
// constructor - initializing the basic node to 1 for the current node, next is 0 initially until set
Node::Node(int id) : id(id), scorenow(1.0), scorenext(0.0) {
}

// get the id of node
int Node::nodeID() const {
    return id;
}

// its current rank on that iteration
double Node::ranknow() const {
    return scorenow;
}

// on the next iteration updated rank
double Node::ranknext() const {
    return scorenext;
}

// outside arrows from page
const vector<int>& Node::nodeout() const {
    return outarrow;
}

// towards arrow to page
const vector<int>& Node::nodein() const{
    return inarrow;
}

// adds as it goes
void Node::arrowoutside(int v){
    outarrow.push_back(v);

}
void Node::arrowin(int u){
    inarrow.push_back(u);

}

// score updates
void Node::setterrank(double score){
    scorenow=score;

}
void Node::setternextrank(double score){
    scorenext = score;

}

// next score is pushed
void Node::addnextiterationrank(){
    scorenow = scorenext;

}
void Node::resetaddnextscore(){
    scorenext = 0.0;
}