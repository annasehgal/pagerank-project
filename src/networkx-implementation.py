# Name : Anna Sehgal
# so with this I will be using implementation from networkx for pagerank
# reference: https://networkx.org/documentation/stable/reference/algorithms/generated/networkx.algorithms.link_analysis.pagerank_alg.pagerank.html
# the goal is to generate the .out files in tests-python which I can later cross check with my .out files for accuracy of my implementaiton

from pathlib import Path
import networkx
import glob

#this is to read .in files in test-python
def readin(file_path):
    with open(file_path, "r") as i:
        totalnodes = int(i.readline())
        totaledges = int(i.readline())
        edges = [tuple(map(int, line.split())) for line in i]
    return totalnodes, totaledges, edges

#this write .out files in test-python using networkx library
def writeout(file_path, pr_dict):
    with open(file_path, "w") as o:
        for node, rank in sorted(pr_dict.items()):
            o.write(f"Node {node+1}: {rank:.6f}\n")

def networkxpagerankimplement(inp, outs, damping=0.85):
    totalnodes, totaledges, edges = readin(inp)
    G = networkx.DiGraph()
    G.add_nodes_from(range(totalnodes))
    G.add_edges_from([(u-1, v-1) for u,v in edges])
    pr = networkx.pagerank(G, alpha=damping, max_iter=1000, tol=1e-6)
    writeout(outs, pr)


def main():
    tests = Path("../tests-python")
    # for in inp sorted(tests.glob(*.in)):
    for inp in tests.glob("*.in"):
        outs = inp.with_suffix(".out")
        print(f"output {inp} -> {outs}")
        networkxpagerankimplement(inp, outs)
if __name__ == "__main__":
    main()
