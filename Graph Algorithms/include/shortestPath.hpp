#include "graphRep.hpp"

namespace graphAlgo
{   
    template <class T>
    class ShortestPath
    {
        public:
        void Bellman_Ford(
                        std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, 
                        std::vector<std::vector<T>> weightedEdges,
                        graphAlgo::nodePtr<T> s_node);

    };

    template <class T>
    void ShortestPath<T>::Bellman_Ford(
                                    std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, 
                                    std::vector<std::vector<T>> weightedEdges,
                                    graphAlgo::nodePtr<T> s_node)
    {
        s_node->distance = 0;
        for (auto al:adjListObj)
        {
            auto u = al.first;
            for (auto it = al.second.begin(); it!=al.second.end(); it++)
            {
                auto v = *it;
                if (v->distance > u->distance + w)
            }
        }
    }

} // namespace graphAlgo