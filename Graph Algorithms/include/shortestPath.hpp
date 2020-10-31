#include "graphRep.hpp"

namespace ga // graph algorithms
{   
    template <class T>
    class ShortestPath
    {
        public:
        void Bellman_Ford(ga::graphPtr<T> graph, T s_idx);
        void Dijkstra(ga::graphPtr<T> graph, T s_idx);
    };

    template <class T>
    void ShortestPath<T>::Bellman_Ford(ga::graphPtr<T> G, T s_idx)
    {
        ga::nodePtr<T> s_node = G->idxToNode[s_idx];
        s_node->distance = 0;
        // from start to each of these vertices:
        for (auto vertex:G->V)
        {   
            // process all vertices except start
            if (vertex == s_idx)
                continue;

            for (auto edge:G->E) 
            {
                ga::nodePtr<T> u_node = G->idxToNode[edge[0]];
                ga::nodePtr<T> v_node = G->idxToNode[edge[1]];
                float weight_uv = G->E_w[edge];
                // relax (u, v, weight_uv)
                if (v_node->distance > u_node->distance + weight_uv)
                {
                    v_node->distance = u_node->distance + weight_uv;
                    v_node->pred = u_node;
                }
            }
        }
        // check negative-weight cycle
        for (auto edge:G->E) 
        {
            ga::nodePtr<T> u_node = G->idxToNode[edge[0]];
            ga::nodePtr<T> v_node = G->idxToNode[edge[1]];
            if (v_node->distance > u_node->distance + G->E_w[edge])
            {
                std::cout << "Megative-weight cycle exists" << std::endl;
                return;
            }
        }
    }

} // namespace ga