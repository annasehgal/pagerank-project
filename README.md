[![C++ Build & Test](https://github.com/annasehgal/pagerank-project/actions/workflows/build.yaml/badge.svg)](https://github.com/annasehgal/pagerank-project/actions/workflows/build.yaml)
# PageRank Algorithm 
- PageRank is based on the random surfer model: imagine a user who moves from page to page across the web.
- At each step, the surfer either:
  * Follows a random outgoing link from the current page, or
  * Teleports to a random page with small probability (the damping factor).
- A page is considered “important” if the surfer is likely to land on it frequently during infinite random navigation.
- Importance flows through links: a link from a highly important page passes on more influence than a link from a low-quality page.
- Instead of treating all links equally, PageRank interprets links as weighted recommendations, capturing both the quantity and quality of incoming links.
- Over repeated iterations, the process stabilizes, producing a score that reflects global influence in the entire network, not just local link counts.

# Code Overview

# How to Run it

# Extension overview:
- Writes PageRank scores per iteration to a CSV file to log convergence.
- Displays the top nodes per iteration for like say, k =3.
- Total should be 1 after convergence, normalized.
-  After running default test cases (from /tests/ folder), it allows the user to enter some values like totalnodes, totaledges, and different edges.
- Saves all iteration scores for visualization or analysis (`custom_graph_pagerank.csv`).

### It has:
- `extension.h` / `extension.cpp`: Implements the extended PageRank logic.  
- `main.cpp`: Orchestrates running default tests and custom input.  
- Uses `Graph` and `Node` classes for graph representation.  

# How to run the extension part for pagerank
1. Compile the Program in /extension-pagerank/ directory with the command pagerank or another executable with a similar name:
```bash
g++ -std=c++17 -o pagerank main.cpp Node.cpp graph.cpp extension.cpp
```

2. Run the executable, which reads a total of 4-5 inputs (one custom from the terminal and the rest from /tests/ directory):
```bash
./pagerank
```
This shows each node's out and incoming arrows/edges, shows logging with top pages, and prints the core of Pagerank.

3. Custom input:
- Enter number of nodes.
- Enter number of edges.
- Enter each edge in from to format (space-separated).

Which gives these: 
a) Display the node links in the console and logging.
b) Display the top nodes per iteration and final ranks.
c) Save all iteration scores to custom_graph_pagerank.csv.

Output & Notes
- Console: Shows node links, iteration logs, top nodes, and final ranks.
- CSV: Stores per-iteration PageRank scores (custom_graph_pagerank.csv) for analysis.
- Parameters: Default damping = 0.85, epsilon = 1e-6, max iterations = 100, top nodes = 3.

# Presentation 
https://www.canva.com/design/DAG5JbQ8B9M/WWN1ZCESVEeP59Asck6Rvw/edit?utm_content=DAG5JbQ8B9M&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton

# References
- https://networkx.org/documentation/stable/reference/algorithms/generated/networkx.algorithms.link_analysis.pagerank_alg.pagerank.html
- https://en.wikipedia.org/wiki/PageRank
- https://web.stanford.edu/class/cs54n/handouts/24-GooglePageRankAlgorithm.pdf
- https://memgraph.github.io/networkx-guide/algorithms/centrality-algorithms/pagerank/
- https://stackoverflow.com/questions/43244805/networkx-pagerank-on-undirected-graph
