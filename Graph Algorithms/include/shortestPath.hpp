#include "graphRep.hpp"

namespace graphAlgo
{   
    template <class T>
    class ShortestPath
    {
        public:
        float get_weight(graphAlgo::nodePtr<T> u, graphAlgo::nodePtr<T> v, 
                std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> weightedEdges);
        void Bellman_Ford(
                        std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, 
                        std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> weightedEdges,
                        graphAlgo::nodePtr<T> s_node);

    };

    template <class T>
    float ShortestPath<T>::get_weight(graphAlgo::nodePtr<T> u, graphAlgo::nodePtr<T> v, 
                std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> weightedEdges)
    {
        // search for the cost from u to v
        std::vector<T> cur_edge {u->nodeIdx, v->nodeIdx};
        for (auto e:weightedEdges)
        {
            if (cur_edge == e->edge)
                return e->weight;
        }    
    }

    template <class T>
    void ShortestPath<T>::Bellman_Ford(
                                std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, 
                                std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> weightedEdges,
                                graphAlgo::nodePtr<T> s_node)
    {
        s_node->distance = 0;
        for (auto al:adjListObj)
        {
            auto u = al.first;
            for (auto it = al.second.begin(); it!=al.second.end(); it++)
            {
                auto v = *it;
                float weight_uv = get_weight(u,v,weightedEdges);
                // relax (u, v, weight_uv)
                if (v->distance > u->distance + weight_uv)
                {
                    v->distance = u->distance + weight_uv;
                    v->pred = u;
                }
            }
        }
        // get optimal path by backtracking
        for (auto al:adjListObj)
        {
            auto u = al.first;
            for (auto it = al.second.begin(); it!=al.second.end(); it++)
            {
                auto v = *it;
                std::cout << char(v->nodeIdx) << " " << v->distance << std::endl;
                if (v->distance > u->distance + get_weight(u,v,weightedEdges))
                    return;
            }
        }
    }

} // namespace graphAlgo