//name: anna sehgal
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>
#include "util.h"
using namespace std;

// buildds graph basd on input given
void Util::builder(Graph& gr){
    int nodes;// from input number of pages
    int edges; // from input number of total edges
    // cout << "No of nodes:";
    cin >> nodes;
    int start =0; //insertion -> graph
    while(start < nodes){ //loop adding
        gr.insertnode(start +1);
        start++;
    }
    // cout <<"no of edges:";
    cin >> edges;
    // cout << "input egdes (start end):";
    int e = 0; // add edges->graph
    while (e < edges) {
        int u; //start
        int v;//end
        cin >> u >> v; 
        gr.insertedge(u, v);
        e++;
    }


}
// rank Node x : xxx.xx value
// void Util::ranker(const Graph& gr){
//     const vector<shared_ptr<Node>>& pages = gr.findedge();
//     cout << fixed << setprecision(6);
//     cout << "\nPager scores for ranks:" << endl;
//     size_t start = 0;
//     while (start < pages.size()){
//         shared_ptr<Node> pg = pages[start];
//         cout << "Node " << pg->nodeID() << ": " << pg->ranknow() << endl;
//         start++;
//     }
// }
void Util::ranker(const Graph& gr){
    const auto& pages = gr.findedge();
    cout << "Pager scores for ranks:" << endl;
    for(const auto& pg : pages){
        double val = pg->ranknow();
        val = round(val * 1e3) / 1e3; // proper rounding
        cout << "Node " << pg->nodeID() << ": " << fixed << setprecision(3) << val << endl;
    }
}
