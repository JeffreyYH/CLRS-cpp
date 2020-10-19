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

} // end of namespace
