#include "graphRep.hpp"

namespace ga // graph algorithms
{   
    template <class T>
    class ShortestPath
    {
        public:
        void Bellman_Ford(ga::graphPtr<T> graph, T s_idx);

    };

    template <class T>
    void ShortestPath<T>::Bellman_Ford(ga::graphPtr<T> G, T s_idx)
    {
        ga::nodePtr<T> s_node = G->idxToNode[s_idx];
        s_node->distance = 0;
        
        for (auto e:G->E) 
        {
            ga::nodePtr<T> u = G->idxToNode[e[0]];
            ga::nodePtr<T> v = G->idxToNode[e[1]];
            float weight_uv = G->E_w[e];
            // relax (u, v, weight_uv)
            if (v->distance > u->distance + weight_uv)
            {
                v->distance = u->distance + weight_uv;
                v->pred = u;
            }
        }
        // // get optimal path by backtracking
        // for (auto al:adjListObj)
        // {
        //     auto u = al.first;
        //     for (auto it = al.second.begin(); it!=al.second.end(); it++)
        //     {
        //         auto v = *it;
        //         std::cout << char(v->nodeIdx) << " " << v->distance << std::endl;
        //         if (v->distance > u->distance + get_weight(u,v,weightedEdges))
        //             return;
        //     }
        // }
    }

} // namespace ga