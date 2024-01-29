#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstddef>
#include <algorithm>

namespace Own {
    template <typename T>
    class DirectedGraph
    {
    static_assert(std::is_integral<T>::value, "T must be an integral type");
    public:
        std::vector<std::vector<T>> m_graph;
        static int id;

    public:
        constexpr DirectedGraph();
        constexpr DirectedGraph(std::size_t);

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
        constexpr void bfsFrom(size_t) const;//-

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
        constexpr void TarjanAlgorithmHelper(T, std::vector<int>&, std::vector<int>&, std::vector<bool>&, std::stack<T>&, std::vector<std::vector<T>>&) const;

    };
};

template <typename T>
int Own::DirectedGraph<T>::id = 0;

// template <typename T>
// void GraphList<T>::dfs_Tarjan(int u, std::vector<int>& low, std::vector<int>& ids, std::vector<bool>& recStack, std::stack<std::size_t>& st, std::vector<std::vector<std::size_t>>& res) {
//     static int id = 0;
//     recStack[u] = true;
//     st.push(u);
//     low[u] = ids[u] = id++;
//     for (auto v : adjList[u]) {
//         if (ids[v] == -1) {
//             dfs_Tarjan(v, low, ids, recStack, st, res);
//         }
//         if (recStack[v]) {
//             low[u] = std::min(low[u], low[v]);
//         }
//     }
//     if (low[u] == ids[u]) {
//         std::vector<std::size_t> tmp;
//         for (auto i = st.top(); ; i = st.top()) {
//             st.pop();            std::vector<std::size_t> tmp;

//             tmp.push_back(i);
//             recStack[i] = false;
//             if (i == u) break;
//         }
//         res.push_back(tmp);
//     }
// }



template <typename T>
constexpr Own::DirectedGraph<T>::DirectedGraph() {}

template <typename T>
constexpr Own::DirectedGraph<T>::DirectedGraph(std::size_t size) 
{
    m_graph.resize(size);
}

template <typename T>
constexpr void Own::DirectedGraph<T>::addEdge(T u, T v) 
{
    if (u >= m_graph.size() || v >= m_graph.size()) {
        throw std::invalid_argument("the argument(s) contain(s) wrong value(s)");
    }

    m_graph[u].push_back(v);
    //m_graph[v].push_back(u);
}

template <typename T>
constexpr void Own::DirectedGraph<T>::addVertex() 
{
    m_graph.push_back(std::vector<T>());
}

template <typename T>
constexpr std::size_t Own::DirectedGraph<T>::getEdgeAmount() const
{
    std::size_t count = 0;
    for (const auto& it : m_graph) {
        count = count + it.size();
    }
    return count;
}

template <typename T>
constexpr std::size_t  Own::DirectedGraph<T>::getVertexAmount() const
{
    return m_graph.size();
}

template <typename T>
constexpr void Own::DirectedGraph<T>::dfs() const
{
    std::vector<bool> visited(m_graph.size(), false);
    std::stack<T> st;
    st.push(0);
    visited[0] = true;

    while (!st.empty()) {
        T top = st.top();
        st.pop();
        std::cout << top << " ";

        for (const auto& it : m_graph[top]) {
            if (!visited[it]) {
                st.push(it);
                visited[it] = true;
            }
        } 
    }
}

template <typename T>
constexpr void Own::DirectedGraph<T>::dfsRecursive() const
{   
    std::vector<bool> visited(m_graph.size(), false);
    dfsRecursiveHelper(0, visited);
}

template <typename T>
constexpr void Own::DirectedGraph<T>::dfsExtraCase() const
{
    std::vector<bool> visited(m_graph.size(), false);
    std::stack<T> st;
    for (std::size_t i = 0; i < m_graph.size(); ++i) {
        if (!visited[i]) {
            st.push(i);
            visited[i] = true;
            T top;
            while (!st.empty()) {
                top = st.top();
                st.pop();
                std::cout << top << " ";
                for (const auto& it : m_graph[top]) {
                    if (!visited[it]) {
                        st.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
    }
}

template <typename T>
constexpr void Own::DirectedGraph<T>::dfsRecursiveExtraCase() const
{
    std::vector<bool> visited(m_graph.size(), false);
    for (int i = 0; i < m_graph.size(); ++i) {
        if (!visited[i]) {
            dfsRecursiveHelper(i, visited);
        }
    }
}

template <typename T>
constexpr void Own::DirectedGraph<T>::dfsFrom(size_t u) const
{
    std::vector<bool> visited(m_graph.size(), false);
    dfsRecursiveHelper(u,visited);
}

template <typename T>
constexpr void Own::DirectedGraph<T>::bfs() const
{
    std::vector<bool> visited(m_graph.size(), false);
    std::queue<T> que;
    que.push(0);
    visited[0] = true;
    T top;
    while (!que.empty()) {
        top = que.front();
        que.pop();
        std::cout << top << " ";
        for (const auto& it : m_graph[top]) {
            if (!visited[it]) {
                visited[it] = true;
                que.push(it);
            }
        }
    }
}

template <typename T>
constexpr void Own::DirectedGraph<T>::bfsExtraCase() const
{
    std::vector<bool> visited(m_graph.size(), false);
    std::queue<T> que;
    for (std::size_t i = 0; i < m_graph.size(); ++i) {
        if (!visited[i]) {
            que.push(i);
            visited[i] = true;
            T top;
            while (!que.empty()) {
                top = que.front();
                que.pop();
                std::cout << top << " ";
                for (const auto& it : m_graph[top]) {
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
constexpr int Own::DirectedGraph<T>::shortestDistance(T u, T v) const
{
    if (u >= m_graph.size() || v >= m_graph.size()) {
        throw std::invalid_argument("the argument(s) contain(s) wrong value(s)");
    }

    std::queue<T> que;
    std::vector<T> distance(m_graph.size(), -1);

    que.push(u);
    distance[u] = 0;
    T top;
    while (!que.empty()) {
        top = que.front();
        que.pop();

        for (const auto& it : m_graph[top]) {
            if (distance[it] == -1) {
                que.push(it);
                distance[it] = distance[top] + 1;
            }
            if (it == v) {
                return distance[it];
            }
        }
    }
    return -1;
}

template <typename T> 
constexpr std::vector<T> Own::DirectedGraph<T>::shortestPath(T u, T v) const
{
    if (u >= m_graph.size() || v >= m_graph.size()) {
        throw std::invalid_argument("the argument(s) contain(s) wrong value(s)");
    }

    std::queue<T> que;
    std::vector<T> parent(m_graph.size(), -1);
    std::vector<bool> visited(m_graph.size(), false);

    visited[u] = true;
    que.push(u);
    T top;

    while (!que.empty()) {
        top = que.front();
        que.pop();

        for (const auto& it : m_graph[top]) {
            if (!visited[it]) {
                parent[it] = top;
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
constexpr void Own::DirectedGraph<T>::transpose() 
{
    std::vector<std::vector<T>> tmp_graph(m_graph.size());
    for (int i = 0; i < m_graph.size(); ++i) {
        for (const auto& it : m_graph[i]) {
            tmp_graph[it].push_back(i);
        }
    }
    m_graph = tmp_graph;
}

template <typename T>
constexpr int Own::DirectedGraph<T>::countNodesAtGivenLevel(T u, std::size_t level) const
{
    std::queue<T> que;
    std::vector<bool> visited(m_graph.size(), false);
    int nodes = 0;
    que.push(u);
    visited[u] = true;
    T top;
    while (!que.empty()) {
        top = que.front();
        if (level == 0) {
            return nodes;
        }
        --level;
        for (const auto& it : m_graph[top]) {
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
constexpr std::vector<std::vector<T>> Own::DirectedGraph<T>::allPossiblePaths() const
{
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        std::vector<bool> visited(m_graph.size(), false);
        allPossiblePathsHelper(0, visited, ans, tmp);
        std::cout << ans.size();
        return ans;
}


template <typename T>
constexpr bool Own::DirectedGraph<T>::isCycledDirected() const
{
    std::vector<bool> visited(m_graph.size(), false);
    std::vector<bool> recStack(m_graph.size(), false);


    for (std::size_t i = 0; i < m_graph.size(); ++i) {
        if (!visited[i] && isCycledHelperDirected(i, visited, recStack)) {
            return true;
        }
    }

    return false;
}


template <typename T>
constexpr bool Own::DirectedGraph<T>::isCycledUndirected() const
{
    std::vector<bool> visited(m_graph.size(), false);
    std::vector<T> parent(m_graph.size(), -1);
    for (std::size_t i = 0; i < m_graph.size(); ++i) {
        if (!visited[i] && isCycledHelperUndirected(i, visited, parent)) {
            return true;
        }
    }
    return false;
}


template <typename T>
constexpr std::vector<T> Own::DirectedGraph<T>::topSort() const
{
    std::stack<T> st;
    std::vector<bool> visited(m_graph.size(), false);
    std::vector<T> ans;


    for (std::size_t i = 0; i < m_graph.size(); ++i) {
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
constexpr std::vector<T> Own::DirectedGraph<T>::KahnAlgorithm() const
{
    std::vector<int> inDegree(m_graph.size(), 0);

    for (int i = 0 ; i < m_graph.size(); ++i) {
        for (const auto& it : m_graph[i]) {
            ++inDegree[it];
        }
    }

    std::queue<T> que;

    for (int i = 0; i < m_graph.size(); ++i) {
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
        for (int i = 0; i < m_graph[front].size(); ++i) {
            --inDegree[m_graph[front][i]];
            if (inDegree[m_graph[front][i]] == 0) {
                que.push(m_graph[front][i]);
            }
        }

    }

    if (ans.size() != m_graph.size()) {
        std::cerr << "the graph contains cycle\n";
        return {};
    }

    return ans;
}

template <typename T>
constexpr std::vector<std::vector<T>>  Own::DirectedGraph<T>::KosarajouAlgorithm()
{
    std::stack<T> st;
    std::vector<bool> visited(m_graph.size(), false);

    for (int i = 0; i < m_graph.size(); ++i) {
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
constexpr std::vector<std::vector<T>> Own::DirectedGraph<T>::TarjanAlgorithm()
{
    std::vector<int> procID(m_graph.size(), -1);
    std::vector<int> lowLink(m_graph.size(), -1);
    std::vector<bool> recStack(m_graph.size(), false);
    std::vector<std::vector<T>> ans;
    std::stack<T> st;

    for(std::size_t i = 0; i < m_graph.size(); ++i) {
        if (procID[i] == -1) {
            TarjanAlgorithmHelper(i, procID, lowLink, recStack, st, ans);
        }
    }
    return ans;
}

template <typename T>
constexpr void Own::DirectedGraph<T>::TarjanAlgorithmHelper(T u, std::vector<int>& procId, std::vector<int>& lowLink, std::vector<bool>& recStack, std::stack<T>& st, std::vector<std::vector<T>>& ans) const
{
    procId[u] = lowLink[u] = ++id;
    st.push(u);
    recStack[u] = true;

    for (const auto& v : m_graph[u]) {
        if (procId[v] == -1) {
            TarjanAlgorithmHelper(v, procId, lowLink, recStack, st, ans);
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
constexpr void Own::DirectedGraph<T>::dfsRecursiveHelper(T u, std::vector<bool>& visited) const
{
    visited[u] = true;
    std::cout << u << " ";
    for (const auto& it : m_graph[u]) {
        if (!visited[it]) {
            dfsRecursiveHelper(it, visited);
        }
    }
}

template <typename T>
constexpr void Own::DirectedGraph<T>::allPossiblePathsHelper(T u, std::vector<bool>& visited, 
                                    std::vector<std::vector<int>>& ans, std::vector<int>& tmp) const
{
    tmp.push_back(u);
    if (u == m_graph.size() - 1) {
        ans.push_back(tmp);
    } else {
        visited[u] = true;
        for (const auto& it : m_graph[u]) {
            if (!visited[it]) {
                allPossiblePathsHelper(it, visited, ans, tmp);
            }
        }               
    visited[u] = false;
    }            
    tmp.pop_back();

    
}


template <typename T>
constexpr bool Own::DirectedGraph<T>::isCycledHelperDirected(T u, std::vector<bool>& visited, std::vector<bool>& recStack) const
{
    visited[u] = true;
    recStack[u] = true;

    for (const auto& v : m_graph[u]) {
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
constexpr bool Own::DirectedGraph<T>::isCycledHelperUndirected(T u, std::vector<bool>& visited, std::vector<T>& parent) const
{
    visited[u] = true;

    for (const auto& v : m_graph[u]) {
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
constexpr void Own::DirectedGraph<T>::topSortHelper(T u, std::stack<T>& st, std::vector<bool>& visited) const
{
    visited[u] = true;
    for (const auto& it : m_graph[u]) {
        if (!visited[it]) {
            topSortHelper(it, st, visited);
            st.push(it);
        }
    }
}


template <typename T>
constexpr void Own::DirectedGraph<T>::KosarajouHelper(T u, std::vector<bool>& visited, std::stack<T>& st) 
{
    visited[u] = true;
    for (const auto& it : m_graph[u]) {
        if (!visited[it]) {
            visited[it] = true;
            KosarajouHelper(it, visited, st);
            st.push(it);

        }
    }
}

template <typename T>
constexpr void Own::DirectedGraph<T>::KosarajouHelperSecond(T u, std::vector<bool>& visited, std::vector<T>& tmp)
{
    visited[u] = true;
    tmp.push_back(u);
    for (const auto& it : m_graph[u]) {
        if (!visited[it]) {
            KosarajouHelperSecond(it, visited, tmp);
        }
    }
}



int main()
{
    Own::DirectedGraph<int> graph;
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();

    //graph.addVertex();


    // graph.addEdge(0, 1);
    // graph.addEdge(0, 3);
    // graph.addEdge(2, 3);
    // graph.addEdge(2, 4);
    // graph.addEdge(3, 0);
    // graph.addEdge(3, 4);

    // graph.addEdge(0,1);
    // graph.addEdge(0,2);
    // graph.addEdge(0,3);
    // graph.addEdge(1,0);
    // graph.addEdge(1,4);
    // graph.addEdge(3,2);
    // graph.addEdge(3,5);
    // graph.addEdge(4,2);
    // graph.addEdge(4,3);
    // graph.addEdge(4,6);
    // graph.addEdge(5,2);
    // graph.addEdge(6,5);




//     graph.addEdge(0,1);
//     graph.addEdge(0,4);
//     graph.addEdge(0,2);
//     graph.addEdge(0,3);
//     graph.addEdge(3,5);
//     graph.addEdge(1,4);
//     graph.addEdge(2,4);
//    // graph.addEdge(8,2);
//     graph.addEdge(4,8);
//     graph.addEdge(4,6);
//     graph.addEdge(5,7);
//     graph.addEdge(7,6);
//     graph.addEdge(6,9);
//     graph.addEdge(8,9);
        graph.addEdge(0,2);
        graph.addEdge(1,0);
        graph.addEdge(1,3);
        graph.addEdge(2,1);
        graph.addEdge(2,3);
        graph.addEdge(3,4);
        graph.addEdge(3,6);
        graph.addEdge(4,6);
        graph.addEdge(6,5);
        graph.addEdge(6,7);
        graph.addEdge(7,4);
       
        //graph.addEdge(3,2);

    //graph.transpose();
   // graph.bfsExtraCase();
    //std::vector<std::vector<int>> obj = graph.allPossiblePaths();
    //std::cout << obj.size();
   // std::cout << graph.isCycledDirected() << "\n";  
    // std::vector<int> vec = graph.KahnAlgorithm();
    // for (int i = 0; i < vec.size(); ++i) {
    //     std::cout <<  vec[i] << " ";
    // }
   
    std::vector<std::vector<int>> vec = graph.TarjanAlgorithm();
    //std::cout << vec.size() << "        \n";
    for (int i = 0; i < vec.size(); ++i) {
        for (auto it : vec[i]) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
    // std::cout << std::endl;
    // std::cout << "adge amount " << graph.getEdgeAmount() << std::endl;
    // std::cout <<"shortestDistance " << graph.shortestDistance(0,9) << std::endl;
    // std::vector<int> vec = graph.shortestPath(0, 9);
    // std::cout << "vec size " <<vec.size() << std::endl;
    // for (auto it : vec) 
    //     std::cout << it << " ";
}