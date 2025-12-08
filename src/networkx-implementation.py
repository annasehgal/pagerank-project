# Name : Anna Sehgal
# so with this I will be using implementation from networkx for pagerank
# reference: https://networkx.org/documentation/stable/reference/algorithms/generated/networkx.algorithms.link_analysis.pagerank_alg.pagerank.html
# the goal is to generate the .out files in tests-python which I can later cross check with my .out files for accuracy of my implementaiton

from pathlib import Path
import networkx

#this is to read .in files in test-python
def readin(filepath):
#this write .out files in test-python using networkx library
def writeout(filepath, pr_dict):

def networkxpagerankimplement(inp, outs, damping=0.85):

def main():
    tests = Path("../tests-python")
    for in inp sorted(tests.glob(*.in)):
        outs = inp.with_suffix(".out")
        print(f"output {inp} -> {outs}")
        networkxpagerankimplement(inp, out)
if __name__ == "__main__":
    main()
