#include "graph.h"

#include <iostream>
#include <string>
#include <vector>

namespace {

void printResult(const std::string& name, bool passed) {
    std::cout << name << ": " << (passed ? "PASS" : "FAIL") << std::endl;
}

bool isEqual(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    return lhs == rhs;
}

}  // namespace

int main() {
    // 无向图通常会在邻接表里记录双向边。
    const graph_algo::Graph traversalGraph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };

    printResult(
        "bfsTraversal",
        isEqual(graph_algo::bfsTraversal(traversalGraph, 0), {0, 1, 2, 3, 4, 5})
    );

    printResult(
        "dfsTraversal",
        isEqual(graph_algo::dfsTraversal(traversalGraph, 0), {0, 1, 3, 4, 5, 2})
    );

    printResult(
        "shortestPathUnweighted",
        isEqual(graph_algo::shortestPathUnweighted(traversalGraph, 0), {0, 1, 1, 2, 2, 2})
    );

    // 这是一个 DAG，用于验证拓扑排序。
    const graph_algo::Graph dag = {
        {1, 2},
        {3},
        {3, 4},
        {5},
        {5},
        {}
    };

    printResult(
        "topologicalSort",
        isEqual(graph_algo::topologicalSort(dag), {0, 1, 2, 3, 4, 5})
    );

    // 有环图不应该返回有效拓扑序。
    const graph_algo::Graph cyclicGraph = {
        {1},
        {2},
        {0}
    };

    printResult(
        "topologicalSort_cycle",
        graph_algo::topologicalSort(cyclicGraph).empty()
    );

    graph_algo::UnionFind unionFind(6);
    printResult("unionFind_init_count", unionFind.getCount() == 6);

    printResult("unionFind_unite_0_1", unionFind.unite(0, 1));
    printResult("unionFind_unite_1_2", unionFind.unite(1, 2));
    printResult("unionFind_connected_0_2", unionFind.isConnected(0, 2));
    printResult("unionFind_not_connected_0_3", !unionFind.isConnected(0, 3));

    printResult("unionFind_unite_3_4", unionFind.unite(3, 4));
    printResult("unionFind_count_after_merge", unionFind.getCount() == 3);

    // 再次合并同一集合中的节点，应返回 false。
    printResult("unionFind_unite_duplicate", !unionFind.unite(0, 2));

    printResult("unionFind_unite_2_4", unionFind.unite(2, 4));
    printResult("unionFind_connected_0_4", unionFind.isConnected(0, 4));
    printResult("unionFind_final_count", unionFind.getCount() == 2);

    return 0;
}
