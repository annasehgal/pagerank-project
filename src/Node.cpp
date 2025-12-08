// Name: Anna Sehgal
#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;
// constructor - initializing the basic node to 1 for the current node, next is 0 initially until set
Node::Node(int id) : id(id), scorenow(1.0), scorenext(0.0) {
}

int Node::nodeID() const {
    return id;
}

double Node::ranknow() const {
    return scorenow;
}

double Node::ranknext() const {
    return scorenext;
}

const vector<int>& Node::nodeout() const {

}


const vector<int>& Node::nodein() const{

}
void Node::arrowoutside(int v){

}
void Node::arrowin(int u){

}
void Node::setterrank(double score){

}
void Node::setternextrank(double score){

}
void Node::addnextiterationrank(){

}
void Node::resetaddnextscore(){
    
}