#include <iostream>
#include <vector>

struct Edges{
    int u, v, weight;
};

typedef std::pair<int,int> Pair;

class Graph
{
public:

    std::vector<std::vector<Pair>> adjList;
    Graph(std::vector<Edges> const &edges, int n);
};

Graph::Graph(std::vector<Edges> const &edges, int n){


    adjList.resize(n);
    for (auto &edge:edges){
        adjList[edge.u].push_back(std::make_pair(edge.v,edge.weight));
    }
    
}
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++){
        for (Pair v: graph.adjList[i]) {
            std::cout << "(Src: " << i << ", Dest:" << v.first << ", Peso:" << v.second << ") ";
        }
        std::cout << std::endl;
    }
}
