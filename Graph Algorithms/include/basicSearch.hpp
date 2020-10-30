#include "basicSearch_obj.hpp"

#define None -100000

namespace graphAlgo
{
    template <class T>
    class BasicSearch
    {
    public:
        // input graph represented as adjacency lists
        void BFS(std::vector<std::list<T>> adjList, T s);

        // DFS constists of DFS_visit and DFS
        void DFS_visit(std::vector<T> vertices, std::vector<std::list<T>> adjList, 
                    T s, std::unordered_map<T, T> &parent);
        void DFS(std::vector<T> vertices, std::vector<std::list<T>> adjList);
    };

    template <class T>
    void BasicSearch<T>::BFS(std::vector<std::list<T>> adjList, T s)
    {
        std::unordered_map<T, int> level;
        std::unordered_map<T, T> parent;
        level[s] = 0;
        parent[s] = None;
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
                                    T s, std::unordered_map<T, T> &parent)
    {
        for (auto v: adjList[s])
        {
            // is v not in parent, which means no visited
            if (parent.find(v) == parent.end())
            {
                parent[v] = s;
                std:: cout << "Expanding vertex " << v << std::endl;
                DFS_visit(vertices, adjList, v, parent);
            }
        }
    }

    // DFS
    template <class T>
    void BasicSearch<T>::DFS(std::vector<T> vertices, std::vector<std::list<T>> adjList)
    {
        std::unordered_map<T, T> parent;
        for (auto s:vertices)
        {
            if (parent.find(s) == parent.end())
            {
                parent[s] = None;
                std:: cout << "Expanding vertex " << s << std::endl;
                DFS_visit(vertices, adjList, s, parent);
            }
        }
    }

} // namespace graphAlgo
