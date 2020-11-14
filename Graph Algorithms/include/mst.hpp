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
        // A is used to represent MST,
        // which is a set contains all the edges of MST
        std::vector<std::vector<T>> A;
        std::unordered_map<T, std::shared_ptr<std::set<T>>> Sets;
        for (auto v:G->V)
        {
            std::shared_ptr<std::set<T>> S (new std::set<T>);
            S->insert(v);
            Sets[v] = S;
        }
        
        // sort the edges of G:E into nondecreasing order by weight
        // using lambda feature of C++
        std::sort(G->E_w.begin(), G->E_w.end(), 
                [](auto &x, auto &y) {
                    return x.second < y.second;
                });
        for (auto e: G->E_w)
        {
            T u = e.first[0];
            T v = e.first[1];
            // is u and v in the same set, we will not use edge (u,v)
            // otherwise there will be a circle
            if (Sets[u]!=Sets[v])
            {
                A.push_back(e.first);
                // merge the sets which have u and v
                std::shared_ptr<std::set<T>> S_union (new std::set<T>);
                
                std::set_union(Sets[u]->begin(), Sets[u]->end(),
                                Sets[v]->begin(), Sets[v]->end(),
                                std::inserter(*S_union, S_union->begin()));
                // all the element in S_union should have the same set pointer
                for (auto ele: *S_union)
                    Sets[ele] = S_union;              
            }
        }

        // print MST
        const bool PRINT = 1;
        if (PRINT)
        {
            std::cout << "Edges of MST In processing order, aka increasing order by weights:" << std::endl;
            for (auto e:A)
            {
                for (auto x:e)
                    std::cout << x << ' ';
                std::cout << std::endl;
            }
        }

    }

    template <class T>
    void MST<T>::Prim(ga::graphPtr<T> G)
    {

    }

} // namespace ga