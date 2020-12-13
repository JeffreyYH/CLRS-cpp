#include "graphRep.hpp"
#include <queue>

namespace ga // graph algorithms
{
    template <class T>
    class ElementaryAlgo
    {
    public:
        // input graph represented as adjacency lists
        static void BFS(ga::graphPtr<T> graph, T s_idx);
        static void BFS_queue(ga::graphPtr<T> graph, T s_idx);
        // DFS constists of DFS_visit and DFS
        static void DFS(ga::graphPtr<T> graph);
        static void DFS_visit(ga::graphPtr<T> graph, T u);
        static void topologicalSort(ga::graphPtr<T> graph);
        static void stronglyConnectedComponents(ga::graphPtr<T> graph);
    public:
        static std::list<T> topoSortList;
    };

    template <class T>
    std::list<T> ElementaryAlgo<T>::topoSortList {};

    template <class T>
    void ElementaryAlgo<T>::BFS(ga::graphPtr<T> graph, T s_idx)
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
    void ElementaryAlgo<T>::BFS_queue
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
            // notice that Q.front() means element at the end of queue
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

    template <class T>
    void ElementaryAlgo<T>::DFS_visit(ga::graphPtr<T> graph, T u)
    {
        graph->idxToNode[u]->color = "GRAY";
        for (auto v:graph->adjList[u])
        {
            if (graph->idxToNode[v]->color == "WHITE")
            {
                std::cout << "Visiting vertex " << v << std::endl;
                graph->idxToNode[v]->pred = graph->idxToNode[u];
                DFS_visit(graph, v);
            }
        }
        topoSortList.push_front(u);
        graph->idxToNode[u]->color = "BLACK";

    }

    template <class T>
    void ElementaryAlgo<T>::DFS(ga::graphPtr<T> graph)
    {   
        topoSortList = {};
        for (auto u:graph->V)
        {
            graph->idxToNode[u]->color = "WHITE";
            graph->idxToNode[u]->pred = nullptr;
        }
        int step = 0;
        for (auto u:graph->V)
        {
            if (graph->idxToNode[u]->color == "WHITE")
            {
                std::cout << "Visiting vertex " << u << std::endl;
                ElementaryAlgo<T>::DFS_visit(graph, u);
            }
        }
    }

    template <class T>
    void ElementaryAlgo<T>::topologicalSort(ga::graphPtr<T> graph)
    {
        ga::ElementaryAlgo<T>::DFS(graph);
        for(auto tpsl:topoSortList)
            std::cout << tpsl << ' ';
        std::cout << std::endl;
    }

    template <class T>
    void ElementaryAlgo<T>::stronglyConnectedComponents(ga::graphPtr<T> graph)
    {

    }


} // namespace ga
