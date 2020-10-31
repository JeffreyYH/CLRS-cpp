#include "graphRep.hpp"

namespace graphAlgo
{   
    template <class T>
    class ShortestPath
    {
        public:
        void Bellman_Ford(std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, 
                        std::vector<std::vector<T>> weightedEdges,
                        T s);

    };

    template <class T>
    void ShortestPath<T>::Bellman_Ford(std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, 
                                    std::vector<std::vector<T>> weightedEdges,
                                    T s)
    {
        std::cout << "hello" << std::endl;
    }

} // namespace graphAlgo