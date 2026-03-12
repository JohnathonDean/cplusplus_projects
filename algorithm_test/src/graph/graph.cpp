#include "graph.h"

#include <queue>
#include <stack>

namespace graph_algo {

UnionFind::UnionFind(int n) : parent_(n), size_(n, 1), count_(n) {
    // 初始时每个节点各自独立，父节点指向自己。
    for (int i = 0; i < n; ++i) {
        parent_[i] = i;
    }
}

int UnionFind::find(int x) {
    // 路径压缩：在查找根节点的过程中，直接把沿途节点挂到根上。
    if (parent_[x] != x) {
        parent_[x] = find(parent_[x]);
    }
    return parent_[x];
}

bool UnionFind::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    // 已经属于同一个集合时，无需重复合并。
    if (rootX == rootY) {
        return false;
    }

    // 按集合大小合并，小树挂到大树下面，降低树高。
    if (size_[rootX] < size_[rootY]) {
        std::swap(rootX, rootY);
    }

    parent_[rootY] = rootX;
    size_[rootX] += size_[rootY];
    --count_;
    return true;
}

bool UnionFind::isConnected(int x, int y) {
    return find(x) == find(y);
}

int UnionFind::getCount() const {
    return count_;
}

namespace {

void dfsImpl(const Graph& graph, int node, std::vector<bool>& visited,
             std::vector<int>& order) {
    // 当前节点一旦进入递归，就立刻标记为已访问。
    visited[node] = true;
    order.push_back(node);

    // 继续访问当前节点的所有未访问邻接点。
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsImpl(graph, neighbor, visited, order);
        }
    }
}

}  // namespace

// 广度优先搜索：按“离起点的层次”从近到远遍历图。
std::vector<int> bfsTraversal(const Graph& graph, int start) {
    std::vector<int> order;

    // 起点越界时返回空结果，避免非法访问。
    if (start < 0 || start >= static_cast<int>(graph.size())) {
        return order;
    }

    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;

    // 起点先入队，并标记为已访问，避免重复入队。
    visited[start] = true;
    q.push(start);

    // 队列中的元素始终表示“当前这一层以及下一层待处理的节点”。
    while (!q.empty()) {
        const int node = q.front();
        q.pop();
        order.push_back(node);

        // 将当前节点所有未访问的邻接点加入队列。
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return order;
}

// 深度优先搜索：沿着一条路径尽可能向深处访问，再回溯处理其他分支。
std::vector<int> dfsTraversal(const Graph& graph, int start) {
    std::vector<int> order;

    // 起点非法时直接返回空结果。
    if (start < 0 || start >= static_cast<int>(graph.size())) {
        return order;
    }

    std::vector<bool> visited(graph.size(), false);
    dfsImpl(graph, start, visited, order);
    return order;
}

// 无权图最短路径：返回从 start 到每个节点的最少边数，不可达则为 -1。
std::vector<int> shortestPathUnweighted(const Graph& graph, int start) {
    std::vector<int> distance(graph.size(), -1);

    // 起点非法时直接返回全 -1 结果。
    if (start < 0 || start >= static_cast<int>(graph.size())) {
        return distance;
    }

    std::queue<int> q;
    distance[start] = 0;
    q.push(start);

    // BFS 天然按路径长度从小到大扩展，因此第一次到达即为最短路。
    while (!q.empty()) {
        const int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            // 还没有访问过的节点，更新距离并入队。
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}

// 拓扑排序：仅适用于有向无环图，返回一个满足依赖关系的节点顺序。
std::vector<int> topologicalSort(const Graph& graph) {
    const int n = static_cast<int>(graph.size());
    std::vector<int> indegree(n, 0);
    std::vector<int> order;
    std::queue<int> q;

    // 先统计每个节点的入度。
    for (int node = 0; node < n; ++node) {
        for (int neighbor : graph[node]) {
            ++indegree[neighbor];
        }
    }

    // 所有入度为 0 的节点都可以作为拓扑序的起点。
    for (int node = 0; node < n; ++node) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    // 每取出一个节点，就相当于移除它发出的边。
    while (!q.empty()) {
        const int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : graph[node]) {
            --indegree[neighbor];
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // 如果没有处理完所有节点，说明图中存在环，拓扑排序无效。
    if (static_cast<int>(order.size()) != n) {
        return {};
    }

    return order;
}

}  // namespace graph_algo
