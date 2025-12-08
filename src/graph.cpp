// Name: Anna Sehgal
#include <iostream>
#include <vector>
#include <memory>
#include "graph.h"
using namespace std;
// new node/page added
void Graph::insertnode(int id) {
    webpages.push_back(shared_ptr<Node>(new Node(id)));
}

shared_ptr<Node> Graph::accessnode(int id) const{

}
int Graph::noofnodes() const{
    return int(webpages.size()); 

}
void Graph::clear()// reset graph
{
    webpages.clear();

}
void Graph::insertedge(int start, int end){

}
const vector<shared_ptr<Node>>& Graph::findedge() const { // list of edges

}
int Graph::noofedges() const{

}
vector<int>Graph::out(int pageid) const{ //arrows outside a node
}
vector<int>Graph::in(int pageid) const{ // arrows towards a node
}
void Graph::makeG(){

} // builder ofgraph