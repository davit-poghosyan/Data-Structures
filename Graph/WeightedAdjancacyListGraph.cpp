#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstddef>
#include <algorithm>
#include <limits>

namespace Own {
    template <typename T>
    class WeightedAdjancacyListGraph
    {
    static_assert(std::is_integral<T>::value, "T must be an integral type");
    public:
        std::vector<std::vector<std::pair<T, int>>> adjList;
    public:
        constexpr WeightedAdjancacyListGraph();
        constexpr WeightedAdjancacyListGraph(std::size_t);

        constexpr void addEdge(T, T, int);
        constexpr void addVertex();

        constexpr size_t getEdgeAmount() const;
        constexpr size_t getVertexAmount() const;

        constexpr void dfs() const;

        constexpr void bfs() const;

        constexpr std::vector<int> DijkstraAlgorithm(T) const;
        constexpr std::vector<int> BellmanFordAlgorithm(T) const;
    };
};


template <typename T>
constexpr Own::WeightedAdjancacyListGraph<T>::WeightedAdjancacyListGraph() {}

template <typename T>
constexpr Own::WeightedAdjancacyListGraph<T>::WeightedAdjancacyListGraph(std::size_t size) 
{
    adjList.resize(size);
}

template <typename T>
constexpr void Own::WeightedAdjancacyListGraph<T>::addEdge(T u, T v, int weight)
{
    if (u >= adjList.size() || v >= adjList.size()) {
        throw std::invalid_argument("the argument(s) contain(s) wrong value(s)");
    }

    adjList[u].push_back(std::pair<T, int>(v, weight));
    //adjList[v].push_back(std::pair<T, int>(v, weight)); //for undirected graph
}

template <typename T>
constexpr void Own::WeightedAdjancacyListGraph<T>::addVertex()
{
    adjList.push_back(std::vector<std::pair<T, int>>());
}

template <typename T>
constexpr size_t Own::WeightedAdjancacyListGraph<T>::getEdgeAmount() const
{
    std::size_t count = 0;
    for (int i = 0; i < adjList.size(); ++i) {
        count += adjList[i].size();
    }

    return count;
}

template <typename T>
constexpr size_t Own::WeightedAdjancacyListGraph<T>::getVertexAmount() const
{
    return adjList.size();
}

template <typename T>
constexpr void Own::WeightedAdjancacyListGraph<T>::dfs() const
{
    std::stack<std::pair<T, int>> st;
    std::vector<bool> visited(adjList.size(), false);
    
    st.push(adjList[0][0]);
    visited[0] = true;
    std::pair<T, int> top;

    while (!st.empty()) {
        top = st.top();
        std::cout << "vertex: "  << top.first << " weight: " << top.second  << "\n";
        st.pop();
        for (const auto& it : adjList[top.first]) {
            if (!visited[it.first]) {
                visited[it.first] = true;
                st.push(it);
            }
        }
    }
}

template <typename T>
constexpr void Own::WeightedAdjancacyListGraph<T>::bfs() const
{
    std::queue<std::pair<T, int>> que;
    std::vector<bool> visited(adjList.size(), false);

    que.push(adjList[0][0]);
    visited[0] = true;

    while (!que.empty()) {
        auto front = que.front();
        que.pop();
        std::cout << "vertex: " << front.first << " weight: " << front.second << "\n";
        for (const auto& it : adjList[front.first]) {
            if (!visited[it.first]) {
                visited[it.first] = true;
                que.push(it);
            }
        }
    }
}


template <typename T>
constexpr std::vector<int> Own::WeightedAdjancacyListGraph<T>::DijkstraAlgorithm(T start) const
{
    if (start < 0 || start >= static_cast<T>(adjList.size())) {
        throw std::out_of_range("Start vertex is out of range.");
    }

    std::vector<int> dist(adjList.size(), INT32_MAX);
    std::vector<bool> visited(adjList.size(), false);

    auto compareSecond = [](std::pair<int, T>& lhs, std::pair<int, T>& rhs) {
        return lhs.second > rhs.second;
    };

    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, decltype(compareSecond)> pq(compareSecond);

    dist[start] = 0;
    pq.push(std::make_pair(0, 0));

    while (!pq.empty()) {
        auto [distance, u] = pq.top();
        visited[u] = true;
        pq.pop();

        if (dist[u] < distance) {
            continue;
        }

        for (const auto& [weight, v] : adjList[u]) {
            if (!visited[v]) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }       
    }

    return dist; 
}


template <typename T>
constexpr std::vector<int> Own::WeightedAdjancacyListGraph<T>::BellmanFordAlgorithm(T u) const
{
     if (u < 0 || u >= static_cast<T>(adjList.size())) {
        throw std::out_of_range("Start vertex is out of range.");
    }

    std::vector<int> dist(adjList.size(), INT32_MAX);

    for (std::size_t i = 0; i < adjList.size() - 1; ++i) {
        for (std::size_t u = 0; u < adjList.size(); ++u) {
            for (const auto& [v, weight] : adjList[u]) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    for (std::size_t u = 0; u < adjList.size(); ++u) {
        for (const auto& [v, weight] : adjList[u]) {
            if (dist[v] > dist[u] + weight) {
                std::cerr << "detected negative cycle\n";
                return {};
            }
        }
    }
    
    return dist;
}
