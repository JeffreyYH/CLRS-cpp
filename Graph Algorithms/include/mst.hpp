/* implementation of minimum spanning tree */
#include "graphRep.hpp"

namespace ga
{   
    // template of this class used for graph node index representation
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
        std::set<T> S;
        for (auto v:G->V)
            S.insert(v);
        
        // sort the edges of G:E into nondecreasing order by weight
        std::sort(G->E_w.begin(), G->E_w.end(), 
                [](auto &x, auto &y) {
                    return x.second < y.second;
                });
        for (auto e: G->E_w)
        {
            
        }

    }

    template <class T>
    void MST<T>::Prim(ga::graphPtr<T> G)
    {

    }

} // namespace ga