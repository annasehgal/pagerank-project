import json
import os
import glob

GRAPHS_DIR = "../graphs/"
TESTS_DIR = "../tests/"


json_files = sorted(glob.glob(f"{GRAPHS_DIR}/graph_*.json"))
for json_file in json_files:
    graph_id = os.path.splitext(os.path.basename(json_file))[0].split("_")[1]
    output_file = f"{TESTS_DIR}/test{graph_id}.in"
    with open(json_file, "r") as f:
        graph = json.load(f)
    nodes = graph["nodes"]
    edges = graph["edges"]
    with open(output_file, "w") as out:
        out.write(f"{len(nodes)}\n")
        out.write(f"{len(edges)}\n")
        for u, v in edges:
            out.write(f"{u} {v}\n")