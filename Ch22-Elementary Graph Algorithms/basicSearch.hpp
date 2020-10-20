#include "graphRep.hpp"
#include <unordered_map>

namespace graphAlgo
{
    template <class T>
    class BasicSearch
    {
    public:
        // input graph represented as adjacency lists
        void BFS(std::vector<std::list<T>> adjList, T s);
        // DFS constists of DFS_visit and DFS
        void DFS_visit(std::vector<T> vertices, std::vector<std::list<T>> adjList, T s, std::unordered_map<T, bool> &visited);
        void DFS(std::vector<T> vertices, std::vector<std::list<T>> adjList);
    };

    template <class T>
    void BasicSearch<T>::BFS(std::vector<std::list<T>> adjList, T s)
    {
        std::unordered_map<T, int> level;
        std::unordered_map<T, T> parent;
        level[s] = 0;
        parent[s] = NULL;
        int i = 1;
        std::vector<T> frontier;
        frontier.push_back(s);
        std::vector<T> next;
        while (!frontier.empty())
        {
            next.clear();
            for (auto u:frontier)
            {
                std:: cout << "Expanding vertex " << u << std::endl;
                for (auto v:adjList[u])
                {
                    // only update unvisited vertices
                    if (level.find(v) == level.end())
                    {
                        level[v] = i;
                        parent[v] = u;
                        next.push_back(v);
                    }
                }
            }
            frontier = next;
            i++;
        }
    }

    // DFS-visit
    template <class T>
    void BasicSearch<T>::DFS_visit(std::vector<T> vertices, std::vector<std::list<T>> adjList, 
                                    T s, std::unordered_map<T, bool> &visited)
    {
        for (auto v: adjList[s])
        {
            // is v not in parent, which means no visited
            if (!visited[v])
            {
                visited[v] = true;
                std:: cout << "Expanding vertex " << v << std::endl;
                DFS_visit(vertices, adjList, v, visited);
            }
        }
    }

    // DFS
    template <class T>
    void BasicSearch<T>::DFS(std::vector<T> vertices, std::vector<std::list<T>> adjList)
    {
        std::unordered_map<T, bool> visited;
        // std::unordered_map<T, T> parent;
        for (auto s:vertices)
        {
            if (!visited[s])
            {
                visited[s] = true;
                std:: cout << "Expanding vertex " << s << std::endl;
                DFS_visit(vertices, adjList, s, visited);
            }
        }
    }

} // namespace graphAlgo
