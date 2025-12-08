// Name: Anna Sehgal
#include <iostream>
#include <vector>
#include <memory>
#include "graph.h"
using namespace std;
// new node/page added->graph
void Graph::insertnode(int id){
    webpages.push_back(shared_ptr<Node>(new Node(id)));
}

shared_ptr<Node> Graph::accessnode(int id) const{ // id access
    size_t start = 0;
    while (start < webpages.size()){
        shared_ptr<Node> pg = webpages[start];
        if (pg->nodeID() == id){
            return pg;
        }
        start++;
    }
    return shared_ptr<Node>();
}
// total nodes =>graphg
int Graph::noofnodes() const{
    return int(webpages.size()); 

}
void Graph::clear()// reset graph
{
    webpages.clear();

}
// addedges simulation 
void Graph::insertedge(int start, int end){ //direct edge additon
    shared_ptr<Node> s = accessnode(start);
    shared_ptr<Node> e = accessnode(end);
    if (s && e) {
        const vector<int>& oute = s->nodeout(); 
        bool check = false;
        size_t st = 0;
        while (st < oute.size()) {
            if (oute[st] == end) {
                check = true;
                break;
            }
            st++;
        }
        if (!check) {
            s->arrowoutside(end);// out add
            e->arrowin(start);// add in
        }
    }
}
const vector<shared_ptr<Node>>& Graph::findedge() const { // list of edges
    return webpages;

}
int Graph::noofedges() const{
    int number = 0;
    int start =0;
    int s = webpages.size();
    while(start<s){
        shared_ptr<Node>pg = webpages[start];
        number = number + (static_cast<int>(pg->nodeout().size()));
        start = start+1;
    }
    return number;
}
vector<int>Graph::out(int pageid) const{ //arrows outside a node 
    shared_ptr<Node> node = accessnode(pageid);
    if (node) {
        vector<int> outu;
        size_t start = 0;
        while (start < node->nodeout().size()) {
            int val = node->nodeout()[start];
            size_t st = 0; //a;ready in vector
            bool check = false;
            while (st < outu.size()) {
                if (outu[st] == val) {
                    check = true;
                    break;
                }
                st++;
            }
            if (!check) {
                outu.push_back(val);
            }
            start++;
        }
        return outu;
    } 
    else {
        return vector<int>();
    }
}
vector<int>Graph::in(int pageid) const{ // arrows towards a node
     shared_ptr<Node> node = accessnode(pageid);
    if (node) {
        vector<int> inu;
        size_t start = 0;
        while (start < node->nodein().size()) {
            int n = node->nodein()[start];
            size_t st = 0; // already there
            bool check = false;
            while (st < inu.size()) {
                if (inu[st] == n) {
                    check = true;
                    break;
                }
                st++;
            }

            if (!check) {
                inu.push_back(n);
            }
            start++;
        }
        return inu;
    } 
    else {
        return vector<int>();
    }
}

//// util does the below already
// void Graph::makeG(){
//     size_t start = 0;
//     while (start < webpages.size()) {
//         shared_ptr<Node> node = webpages[start];
//         cout << "Node " << node->nodeID() << " -> Out: ";
//         // Print outgoing edges
//         vector<int> outs = out(node->nodeID());
//         size_t st = 0;
//         while (st < outs.size()) {
//             cout << outs[st] << " ";
//             st++;
//         }
//         cout << " In: ";
//         // Print incoming edges
//         vector<int> ins = in(node->nodeID()); 
//         st = 0;
//         while (st < ins.size()) {
//             cout << ins[st] << " ";
//             st++;
//         }
//         cout << endl;
//         start++;
//     }
// } // builder ofgraph