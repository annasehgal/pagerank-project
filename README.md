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

# How to run a little extension for pagerank

# Presentation 
https://www.canva.com/design/DAG5JbQ8B9M/WWN1ZCESVEeP59Asck6Rvw/edit?utm_content=DAG5JbQ8B9M&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton

# References
- https://networkx.org/documentation/stable/reference/algorithms/generated/networkx.algorithms.link_analysis.pagerank_alg.pagerank.html
- https://en.wikipedia.org/wiki/PageRank
- https://web.stanford.edu/class/cs54n/handouts/24-GooglePageRankAlgorithm.pdf
- https://memgraph.github.io/networkx-guide/algorithms/centrality-algorithms/pagerank/
- https://stackoverflow.com/questions/43244805/networkx-pagerank-on-undirected-graph
