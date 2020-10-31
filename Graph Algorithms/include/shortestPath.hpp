#include "graphRep.hpp"

namespace graphAlgo
{   
    template <class T>
    class ShortestPath
    {
        public:
        float get_weight(graphAlgo::nodePtr<T> u, graphAlgo::nodePtr<T> v, 
                std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> weightedEdges);
        void Bellman_Ford(graphAlgo::graphPtr<T> graph, T s_idx);

    };

    // template <class T>
    // float ShortestPath<T>::get_weight(graphAlgo::nodePtr<T> u, graphAlgo::nodePtr<T> v, 
    //             std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> weightedEdges)
    // {
    //     // search for the cost from u to v
    //     std::vector<T> cur_edge {u->nodeIdx, v->nodeIdx};
    //     for (auto e:weightedEdges)
    //     {
    //         if (cur_edge == e->edge)
    //             return e->weight;
    //     }    
    // }

    template <class T>
    void ShortestPath<T>::Bellman_Ford(graphAlgo::graphPtr<T> G, T s_idx)
    {
        graphAlgo::nodePtr<T> s_node = G->idxToNode[s_idx];
        s_node->distance = 0;
        
        for (auto e:G->E) 
        {
            graphAlgo::nodePtr<T> u = G->idxToNode[e[0]];
            graphAlgo::nodePtr<T> v = G->idxToNode[e[1]];
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

} // namespace graphAlgo