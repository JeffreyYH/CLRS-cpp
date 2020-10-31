#include "graphRep.hpp"
#include <queue>

namespace graphAlgo
{
    // twin class of BasicSearch
    // in this class we use object instead of idx to do searching
    template <class T>
    class BasicSearchObj
    {
    public:
        // input graph represented as adjacency lists
        void BFS(std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> adjListObj, graphAlgo::nodePtr<T> s_node);
        void BFS_queue(std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> adjListObj, graphAlgo::nodePtr<T> s_node);

        // DFS constists of DFS_visit and DFS
    };

    template <class T>
    void BasicSearchObj<T>::BFS(std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj,
                                graphAlgo::nodePtr<T> s_node)
    {
        std::unordered_map<T, int> level;
        level[s_node->nodeIdx] = 0;
        int i = 1;
        std::vector<graphAlgo::nodePtr<T>> frontier;
        frontier.push_back(s_node);
        std::vector<graphAlgo::nodePtr<T>> next;
        while (!frontier.empty())
        {
            next.clear();
            for (auto u:frontier)
            {
                std:: cout << "Expanding vertex " << u->nodeIdx << std::endl;
                for (auto v:adjListObj[u])
                {
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
    (std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, graphAlgo::nodePtr<T> s_node)
    {
        s_node->color = "GRAY";
        s_node->distance = 0;
        s_node->pred = nullptr;

        std::queue<graphAlgo::nodePtr<T>> Q;
        Q.push(s_node);
        while(!Q.empty())
        {
            // notice Q.front() means elment at the end of queue
            auto u_node = Q.front();
            std::cout << "visiting vertex " << u_node->nodeIdx << std::endl;
            Q.pop();
            for (auto v_node:adjListObj[u_node])
            {   
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


} // namespace graphAlgo
