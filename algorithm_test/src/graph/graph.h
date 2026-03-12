#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

namespace graph_algo {

using Graph = std::vector<std::vector<int>>;

class UnionFind {
public:
    explicit UnionFind(int n);

    int find(int x);
    bool unite(int x, int y);
    bool isConnected(int x, int y);
    int getCount() const;

private:
    std::vector<int> parent_;
    std::vector<int> size_;
    int count_;
};

std::vector<int> bfsTraversal(const Graph& graph, int start);
std::vector<int> dfsTraversal(const Graph& graph, int start);
std::vector<int> shortestPathUnweighted(const Graph& graph, int start);
std::vector<int> topologicalSort(const Graph& graph);

}  // namespace graph_algo

#endif
