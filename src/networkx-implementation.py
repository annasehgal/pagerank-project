# Name : Anna Sehgal
# so with this I will be using implementation from networkx for pagerank
# reference: https://networkx.org/documentation/stable/reference/algorithms/generated/networkx.algorithms.link_analysis.pagerank_alg.pagerank.html
# the goal is to generate the .out files in tests-python which I can later cross check with my .out files for accuracy of my implementaiton

from pathlib import Path
import networkx

#this is to read .in files in test-python
def readin(file_path):
    with open(file_path, "r") as i:
        totalnodes = int(i.readline())
        totaledges = int(i.readline())
        edges = [tuple(map(int, line.split())) for line in f]
    return totalnodes, totaledges, edges

#this write .out files in test-python using networkx library
def writeout(file_path, pr_dict):
    with open(file_path, "w") as o:
        for node, rank in sorted(pr_dict.items()):
            o.write(f"Node {node+1}: {rank:.6f}\n")

def networkxpagerankimplement(inp, outs, damping=0.85):

def main():
    tests = Path("../tests-python")
    for in inp sorted(tests.glob(*.in)):
        outs = inp.with_suffix(".out")
        print(f"output {inp} -> {outs}")
        networkxpagerankimplement(inp, out)
if __name__ == "__main__":
    main()
