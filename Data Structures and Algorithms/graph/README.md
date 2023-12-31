# Graph Algorithms

Part of the graph algorithms were developed in CPP in another repository.

## Algorithms
- Minimum Path in a Digraph: [Bellman-Ford](https://github.com/TETEURYAN/GraphTeory/tree/main/bellman)
- Minimum Path in a graph: [Dijkstra's](https://github.com/TETEURYAN/GraphTeory/tree/main/dijkstra)
- Minimum Path with DP in a graph: [Floyd-Warshall](https://github.com/TETEURYAN/GraphTeory/tree/main/warshall)
- Minimum Spanning Tree with greedy in a graph: [Prim](https://github.com/TETEURYAN/GraphTeory/tree/main/prim)
- Minimum Spanning Tree with Union-Find in a graph: [Kruskal](https://github.com/TETEURYAN/GraphTeory/tree/main/kruskal)
- Maximum flow in a graph: [Ford-Fulkerson](https://github.com/TETEURYAN/GraphTeory/tree/main/fulkerson)
- Topological Order in a graph: [Kahn](https://github.com/TETEURYAN/GraphTeory/tree/main/kahn)

# Minimum Path Problem

## At the Heart of the Problem

In the realm of graphs, a frequent challenge is to find the most efficient path between two points. This is where shortest path algorithms come into play, serving as essential tools for navigating through interconnected nodes and edges.

Imagine a network of cities connected by roads with varying travel times, or a circuit board with components linked by wires with different signal delays. These scenarios, and many others, can be modeled as graphs, where vertices represent points of interest and edges represent connections with associated weights. Shortest path algorithms aim to identify the path between two vertices that minimizes the total weight, whether it's distance, cost, time, or any other measurable metric.
### Key Algorithms:
1. **Dijkstra's Algorithm:** Efficient for finding shortest paths from a single source to all other vertices in graphs with non-negative edge weights. It's widely used in GPS navigation and network routing.
2. **Bellman-Ford Algorithm:** Handles graphs with negative edge weights, but with slower performance compared to Dijkstra's. It's valuable for detecting negative weight cycles, making it useful in financial modeling and risk analysis.
3. **Floyd-Warshall Algorithm:** Computes shortest paths between all pairs of vertices in a graph, regardless of edge weight signs. It finds applications in DNA sequence analysis and social network studies.

# Minimum Spanning Trees

## At the Core of Connectivity
In the realm of graphs, where points are interconnected by weighted edges, a common challenge arises: how to create a network that connects all points while minimizing the overall cost. This is where minimum spanning trees (MSTs) step in, offering efficient pathways through dense webs of possibilities.

## Building Bridges Without Breaking the Bank

### Defining the MST:

  An MST is a subgraph of a weighted, connected, undirected graph that includes all vertices and a subset of edges, forming a tree with the minimum possible total edge weight.
  It ensures full connectivity while minimizing the cost of construction or communication.

### Key Algorithms:

  **Prim's Algorithm:** Starts with a single vertex and gradually expands the tree by adding the cheapest edge connecting a new vertex to the existing tree.
  **Kruskal's Algorithm:** Follows a greedy approach, adding edges in ascending order of weight, as long as they don't create cycles.

