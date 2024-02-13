#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstddef>
#include <algorithm>

namespace Own {
    template <typename T>
    class AdjancacyListGraph
    {
    static_assert(std::is_integral<T>::value, "T must be an integral type");
    private:
        std::vector<std::vector<T>> adjList;
    public:
        constexpr AdjancacyListGraph();
        constexpr AdjancacyListGraph(std::size_t);

        constexpr void addEdge(T, T);
        constexpr void addVertex();

        constexpr size_t getEdgeAmount() const;
        constexpr size_t getVertexAmount() const;

        constexpr void dfs() const;
        constexpr void dfsRecursive() const;
        constexpr void dfsExtraCase() const;
        constexpr void dfsRecursiveExtraCase() const;
        constexpr void dfsFrom(size_t) const;

        constexpr void bfs() const;
        constexpr void bfsExtraCase() const;
        constexpr void bfsFrom(size_t) const;

        constexpr int shortestDistance(T, T) const;
        constexpr std::vector<T> shortestPath(T, T) const;
        constexpr void transpose();
        constexpr int countNodesAtGivenLevel(T, std::size_t) const; 
        constexpr std::vector<std::vector<T>> allPossiblePaths() const;
        constexpr bool isCycledDirected() const;
        constexpr bool isCycledUndirected() const;
        constexpr std::vector<T> topSort() const;
        constexpr std::vector<T> KahnAlgorithm() const;
        constexpr std::vector<std::vector<T>> KosarajouAlgorithm();
        constexpr std::vector<std::vector<T>> TarjanAlgorithm();
    private:
        constexpr void dfsRecursiveHelper(T, std::vector<bool>&) const;
        constexpr void allPossiblePathsHelper(T, std::vector<bool>&, std::vector<std::vector<int>>&, std::vector<int>&) const;
        constexpr bool isCycledHelperDirected(T, std::vector<bool>&, std::vector<bool>&) const;
        constexpr bool isCycledHelperUndirected(T, std::vector<bool>&, std::vector<T>&) const;
        constexpr void topSortHelper(T, std::stack<T>&, std::vector<bool>&) const;
        constexpr void KosarajouHelper(T, std::vector<bool>&, std::stack<T>&);
        constexpr void KosarajouHelperSecond(T , std::vector<bool>&, std::vector<T>&);
        constexpr void TarjanAlgorithmHelper(T, std::vector<int>&, std::vector<int>&, std::vector<bool>&, std::stack<T>&, std::vector<std::vector<T>>&, int&) const;

    };
};




template <typename T>
constexpr Own::AdjancacyListGraph<T>::AdjancacyListGraph() {}

template <typename T>
constexpr Own::AdjancacyListGraph<T>::AdjancacyListGraph(std::size_t size) 
{
    adjList.resize(size);
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::addEdge(T u, T v) 
{
    if (u >= adjList.size() || v >= adjList.size()) {
        throw std::invalid_argument("the argument(s) contain(s) wrong value(s)");
    }

    adjList[u].push_back(v);
    //adjList[v].push_back(u); //for undirected graph
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::addVertex() 
{
    adjList.push_back(std::vector<T>());
}

template <typename T>
constexpr std::size_t Own::AdjancacyListGraph<T>::getEdgeAmount() const
{
    std::size_t count = 0;
    for (const auto& it : adjList) {
        count = count + it.size();
    }
    return count;
}

template <typename T>
constexpr std::size_t  Own::AdjancacyListGraph<T>::getVertexAmount() const
{
    return adjList.size();
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::dfs() const
{
    std::vector<bool> visited(adjList.size(), false);
    std::stack<T> st;
    st.push(0);
    visited[0] = true;
    T top;

    while (!st.empty()) {
        top = st.top();
        st.pop();
        std::cout << top << " ";

        for (const auto& it : adjList[top]) {
            if (!visited[it]) {
                st.push(it);
                visited[it] = true;
            }
        } 
    }
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::dfsRecursive() const
{   
    std::vector<bool> visited(adjList.size(), false);
    dfsRecursiveHelper(0, visited);
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::dfsExtraCase() const
{
    std::vector<bool> visited(adjList.size(), false);
    std::stack<T> st;
    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            st.push(i);
            visited[i] = true;
            T top;
            while (!st.empty()) {
                top = st.top();
                st.pop();
                std::cout << top << " ";
                for (const auto& it : adjList[top]) {
                    if (!visited[it]) {
                        st.push(it);
                    }
                }
            }
        }
    }
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::dfsRecursiveExtraCase() const
{
    std::vector<bool> visited(adjList.size(), false);
    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            dfsRecursiveHelper(i, visited);
        }
    }
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::dfsFrom(size_t u) const
{
    std::vector<bool> visited(adjList.size(), false);
    dfsRecursiveHelper(u,visited);
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::bfs() const
{
    std::vector<bool> visited(adjList.size(), false);
    std::queue<T> que;
    que.push(0);
    visited[0] = true;
    T front;

    while (!que.empty()) {
        front = que.front();
        que.pop();
        std::cout << front << " ";
        for (const auto& it : adjList[front]) {
            if (!visited[it]) {
                visited[it] = true;
                que.push(it);
            }
        }
    }
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::bfsExtraCase() const
{
    std::vector<bool> visited(adjList.size(), false);
    std::queue<T> que;
    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            que.push(i);
            visited[i] = true;
            T front;
            while (!que.empty()) {
                front = que.front();
                que.pop();
                std::cout << front << " ";
                for (const auto& it : adjList[front]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        que.push(it);
                    }
                }
            }
        }
    }
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::bfsFrom(std::size_t u) const
{
    std::vector<bool> visited(adjList.size(), false);
    std::queue<T> que;
    que.push((u));
    visited[u] = true;
    T front;
    while (!que.empty()) {
        front = que.front();
        que.pop();
        std::cout << front << " ";
        for (const auto& it : adjList[front]) {
            if (!visited[it]) {
                visited[it] = true;
                que.push(it);
            }
        }
    }

}


template <typename T>
constexpr int Own::AdjancacyListGraph<T>::shortestDistance(T u, T v) const
{
    if (u >= adjList.size() || v >= adjList.size()) {
        throw std::invalid_argument("the argument(s) contain(s) wrong value(s)");
    }

    std::queue<T> que;
    std::vector<T> distance(adjList.size(), -1);

    que.push(u);
    distance[u] = 0;
    T front;

    while (!que.empty()) {
        front = que.front();
        que.pop();

        for (const auto& it : adjList[front]) {
            if (distance[it] == -1) {
                que.push(it);
                distance[it] = distance[front] + 1;
            }
            if (it == v) {
                return distance[it];
            }
        }
    }

    return -1;
}






template <typename T> 
constexpr std::vector<T> Own::AdjancacyListGraph<T>::shortestPath(T u, T v) const
{
    if (u >= adjList.size() || v >= adjList.size()) {
        throw std::invalid_argument("the argument(s) contain(s) wrong value(s)");
    }

    std::queue<T> que;
    std::vector<T> parent(adjList.size(), -1);
    std::vector<bool> visited(adjList.size(), false);

    visited[u] = true;
    que.push(u);
    T front;

    while (!que.empty()) {
        front = que.front();
        que.pop();

        for (const auto& it : adjList[front]) {
            if (!visited[it]) {
                parent[it] = front;
                visited[it] = true;
                que.push(it);
            }
            if (it == v) {
                break;
            }
        }
    }

    std::vector<T> path;
    T current = v;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    std::reverse(path.begin(), path.end());

    return path;
}






template <typename T>
constexpr void Own::AdjancacyListGraph<T>::transpose() 
{
    std::vector<std::vector<T>> tmp_graph(adjList.size());
    
    for (std::size_t u = 0; u < adjList.size(); ++u) {
        for (const auto& v : adjList[u]) {
            tmp_graph[v].push_back(u);
        }
    }

    adjList = tmp_graph;
}

template <typename T>
constexpr int Own::AdjancacyListGraph<T>::countNodesAtGivenLevel(T u, std::size_t level) const
{
    std::queue<T> que;
    std::vector<bool> visited(adjList.size(), false);
    int nodes = 0;
    que.push(u);
    visited[u] = true;
    T front;

    while (!que.empty()) {
        front = que.front();
        que.pop();

        if (level == 0) {
            return nodes;
        }

        --level;
        
        for (const auto& it : adjList[front]) {
            if (!visited[it]) {
                ++nodes;
                visited[it] = true;
                que.push(it);
            }
        }            
    }

    return -1;
}

 


template <typename T>
constexpr std::vector<std::vector<T>> Own::AdjancacyListGraph<T>::allPossiblePaths() const
{
    std::vector<std::vector<int>> ans;
    std::vector<int> tmp;
    std::vector<bool> visited(adjList.size(), false);

    allPossiblePathsHelper(0, visited, ans, tmp);

    return ans;
}


template <typename T>
constexpr bool Own::AdjancacyListGraph<T>::isCycledDirected() const
{
    std::vector<bool> visited(adjList.size(), false);
    std::vector<bool> recStack(adjList.size(), false);

    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (!visited[i] && isCycledHelperDirected(i, visited, recStack)) {
            return true;
        }
    }

    return false;
}


template <typename T>
constexpr bool Own::AdjancacyListGraph<T>::isCycledUndirected() const
{
    std::vector<bool> visited(adjList.size(), false);
    std::vector<T> parent(adjList.size(), -1);

    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (!visited[i] && isCycledHelperUndirected(i, visited, parent)) {
            return true;
        }
    }

    return false;
}


template <typename T>
constexpr std::vector<T> Own::AdjancacyListGraph<T>::topSort() const
{
    std::stack<T> st;
    std::vector<bool> visited(adjList.size(), false);
    std::vector<T> ans;

    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            topSortHelper(i, st, visited);
            st.push(i);
        }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

template <typename T>
constexpr std::vector<T> Own::AdjancacyListGraph<T>::KahnAlgorithm() const
{
    std::vector<int> inDegree(adjList.size(), 0);

    for (std::size_t u = 0 ; u < adjList.size(); ++u) {
        for (const auto& v : adjList[u]) {
            ++inDegree[v];
        }
    }

    std::queue<T> que;

    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (inDegree[i] == 0) {
            que.push(i);
            --inDegree[i];
        }
    }

    std::vector<T> ans;
    T front;

    while (!que.empty()) {
        front = que.front();
        que.pop();
        ans.push_back(front);
        for (std::size_t i = 0; i < adjList[front].size(); ++i) {
            --inDegree[adjList[front][i]];
            if (inDegree[adjList[front][i]] == 0) {
                que.push(adjList[front][i]);
            }
        }
    }

    if (ans.size() != adjList.size()) {
        std::cerr << "the graph contains cycle\n";
        return {};
    }

    return ans;
}

template <typename T>
constexpr std::vector<std::vector<T>>  Own::AdjancacyListGraph<T>::KosarajouAlgorithm()
{
    std::stack<T> st;
    std::vector<bool> visited(adjList.size(), false);

    for (std::size_t i = 0; i < adjList.size(); ++i) {
        if (visited[i] == false) {
            KosarajouHelper(i, visited, st);
            st.push(i);
        }
    }

    transpose();
    std::vector<std::vector<T>> ans;
    std::vector<T> tmp;
    T top;

    std::fill(visited.begin(), visited.end(), false);

    while (!st.empty()) {
        top = st.top();
        st.pop();
        if (!visited[top]) {
            KosarajouHelperSecond(top, visited, tmp);
            ans.push_back(tmp);
            tmp.clear();
        }
    }

    transpose();

    return ans;
}


template <typename T>
constexpr std::vector<std::vector<T>> Own::AdjancacyListGraph<T>::TarjanAlgorithm()
{
    std::vector<int> procID(adjList.size(), -1);
    std::vector<int> lowLink(adjList.size(), -1);
    std::vector<bool> recStack(adjList.size(), false);
    std::vector<std::vector<T>> ans;
    std::stack<T> st;
    int id = -1;

    for(std::size_t i = 0; i < adjList.size(); ++i) {
        if (procID[i] == -1) {
            TarjanAlgorithmHelper(i, procID, lowLink, recStack, st, ans, id);
        }
    }

    return ans;
}


template <typename T>
constexpr void Own::AdjancacyListGraph<T>::TarjanAlgorithmHelper(T u, std::vector<int>& procId, std::vector<int>& lowLink, std::vector<bool>& recStack, std::stack<T>& st, std::vector<std::vector<T>>& ans, int& id) const
{
    procId[u] = lowLink[u] = ++id;
    st.push(u);
    recStack[u] = true;

    for (const auto& v : adjList[u]) {
        if (procId[v] == -1) {
            TarjanAlgorithmHelper(v, procId, lowLink, recStack, st, ans, id);
        }
        if (recStack[v]) {
            lowLink[u] = std::min(lowLink[u], lowLink[v]);
        }
    }

    int top;
    std::vector<T> tmp;

    if (lowLink[u] == procId[u]) {
        while (st.top() != u) {
            top = st.top();
            tmp.push_back(top);
            recStack[top] = false;
            st.pop();
        }
        top = st.top();
        tmp.push_back(top);
        ans.push_back(tmp);
        tmp.clear();
        recStack[top] = false;
        st.pop();
    }
}


template <typename T>
constexpr void Own::AdjancacyListGraph<T>::dfsRecursiveHelper(T u, std::vector<bool>& visited) const
{
    visited[u] = true;
    std::cout << u << " ";

    for (const auto& v : adjList[u]) {
        if (!visited[v]) {
            dfsRecursiveHelper(v, visited);
        }
    }
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::allPossiblePathsHelper(T u, std::vector<bool>& visited, 
                                    std::vector<std::vector<int>>& ans, std::vector<int>& tmp) const
{
    tmp.push_back(u);

    if (u == adjList.size() - 1) {
        ans.push_back(tmp);
    } else {
        visited[u] = true;
        for (const auto& v : adjList[u]) {
            if (!visited[v]) {
                allPossiblePathsHelper(v, visited, ans, tmp);
            }
        }    

    visited[u] = false;
    }            

    tmp.pop_back();
}


template <typename T>
constexpr bool Own::AdjancacyListGraph<T>::isCycledHelperDirected(T u, std::vector<bool>& visited, std::vector<bool>& recStack) const
{
    visited[u] = true;
    recStack[u] = true;

    for (const auto& v : adjList[u]) {
        if (!visited[v] && isCycledHelperDirected(v, visited, recStack)) {
            return true;
        }
        else if (recStack[v] == true) {
            return true;
        }
    }

    recStack[u] = false;
    
    return false;
}

template <typename T>
constexpr bool Own::AdjancacyListGraph<T>::isCycledHelperUndirected(T u, std::vector<bool>& visited, std::vector<T>& parent) const
{
    visited[u] = true;

    for (const auto& v : adjList[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (isCycledHelperUndirected(v, visited, parent)) {
                return true;
            }
        } else if (parent[u] != v) {
            return true;
        }
    }

    return false;
}



template <typename T>
constexpr void Own::AdjancacyListGraph<T>::topSortHelper(T u, std::stack<T>& st, std::vector<bool>& visited) const
{
    visited[u] = true;

    for (const auto& it : adjList[u]) {
        if (!visited[it]) {
            topSortHelper(it, st, visited);
            st.push(it);
        }
    }
}


template <typename T>
constexpr void Own::AdjancacyListGraph<T>::KosarajouHelper(T u, std::vector<bool>& visited, std::stack<T>& st) 
{
    visited[u] = true;
    
    for (const auto& v : adjList[u]) {
        if (!visited[v]) {
            KosarajouHelper(v, visited, st);
            st.push(v);
        }
    }
}

template <typename T>
constexpr void Own::AdjancacyListGraph<T>::KosarajouHelperSecond(T u, std::vector<bool>& visited, std::vector<T>& tmp)
{
    visited[u] = true;
    tmp.push_back(u);
    
    for (const auto& it : adjList[u]) {
        if (!visited[it]) {
            KosarajouHelperSecond(it, visited, tmp);
        }
    }
}

