/* implementation of minimum spanning tree */
#include "graphRep.hpp"

namespace ga
{
    template <class T>
    class MST  
    {
    public:
        void Kruskal (ga::graphPtr<T> G);
        void Prim(ga::graphPtr<T> G);
    };

    template <class T>
    void MST<T>::Kruskal(ga::graphPtr<T> G)
    {
        std::list<std::vector<T>> A;

    }

    template <class T>
    void MST<T>::Prim(ga::graphPtr<T> G)
    {

    }

} // namespace ga