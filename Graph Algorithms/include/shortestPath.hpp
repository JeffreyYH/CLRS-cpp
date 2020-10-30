#include "graphRep.hpp"

namespace graphAlgo
{   
    template <class T>
    class ShortedPath
    {
        public:
        void Bellman_Ford(std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, 
                        std::vector<std::vector<T>> weightedEdges,
                        T s);


    };
} // namespace graphAlgo