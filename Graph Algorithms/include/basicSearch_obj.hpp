#include "graphRep.hpp"
#include <queue>

namespace ga
{
    // twin class of BasicSearch
    // in this class we use object instead of idx to do searching
    template <class T>
    class BasicSearchObj
    {
    public:
        // input graph represented as adjacency lists
        void BFS(ga::graphPtr<T> graph, T s_idx);
        void BFS_queue(ga::graphPtr<T> graph, T s_idx);

        // DFS constists of DFS_visit and DFS
    };

    template <class T>
    void BasicSearchObj<T>::BFS(ga::graphPtr<T> graph, T s_idx)
    {
        std::unordered_map<T, int> level;
        ga::nodePtr<T> s_node = graph->idxToNode[s_idx];
        level[s_node->nodeIdx] = 0;
        int i = 1;
        std::vector<ga::nodePtr<T>> frontier;
        frontier.push_back(s_node);
        std::vector<ga::nodePtr<T>> next;
        while (!frontier.empty())
        {
            next.clear();
            for (auto u:frontier)
            {
                std:: cout << "Expanding vertex " << u->nodeIdx << std::endl;
                for (auto v_idx:graph->adjList[u->nodeIdx])
                {
                    ga::nodePtr<T> v = graph->idxToNode[v_idx];
                    // only update unvisited vertices
                    if (level.find(v->nodeIdx) == level.end())
                    {
                        level[v->nodeIdx] = i;
                        v->pred = u;
                        next.push_back(v);
                    }
                }
            }
            frontier = next;
            i++;
        }
    }

    // implement CLRS pg.595, BFS, based on queue
    template <class T>
    void BasicSearchObj<T>::BFS_queue
    (ga::graphPtr<T> graph, T s_idx)
    {
        ga::nodePtr<T> s_node = graph->idxToNode[s_idx];

        s_node->color = "GRAY";
        s_node->distance = 0;
        s_node->pred = nullptr;

        std::queue<ga::nodePtr<T>> Q;
        Q.push(s_node);
        while(!Q.empty())
        {
            // notice Q.front() means elment at the end of queue
            auto u_node = Q.front();
            std::cout << "visiting vertex " << u_node->nodeIdx << std::endl;
            Q.pop();
            for (auto v_idx:graph->adjList[u_node->nodeIdx])
            {   
                ga::nodePtr<T> v_node = graph->idxToNode[v_idx];
                // white means unvisited
                if (v_node->color == "WHITE")
                {
                    v_node->color = "GRAY";
                    v_node->distance = u_node->distance + 1;
                    v_node->pred = u_node;
                    Q.push(v_node);
                }
            }
            // black means visited
            u_node->color = "BLACK";
        }
    }


} // namespace ga
