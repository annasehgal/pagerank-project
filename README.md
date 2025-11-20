[![C++ Build & Test](https://github.com/annasehgal/pagerank-project/actions/workflows/build.yaml/badge.svg)](https://github.com/annasehgal/pagerank-project/actions/workflows/build.yaml)
# PageRank Algorithm Project
- PageRank is based on the random surfer model: imagine a user who moves from page to page across the web.
- At each step, the surfer either:
  * Follows a random outgoing link from the current page, or
  * Teleports to a random page with small probability (the damping factor).
- A page is considered “important” if the surfer is likely to land on it frequently during infinite random navigation.
- Importance flows through links: a link from a highly important page passes on more influence than a link from a low-quality page.
- Instead of treating all links equally, PageRank interprets links as weighted recommendations, capturing both the quantity and quality of incoming links.
- Over repeated iterations, the process stabilizes, producing a score that reflects global influence in the entire network, not just local link counts.

# Presentation 
https://www.canva.com/design/DAG5JbQ8B9M/WWN1ZCESVEeP59Asck6Rvw/edit?utm_content=DAG5JbQ8B9M&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
