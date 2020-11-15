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
        void Prim(ga::graphPtr<T> G, T r);     
    };

    template <class T>
    void MST<T>::Kruskal(ga::graphPtr<T> G)
    {   
        float total_cost = 0;
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
            if (Sets[u] != Sets[v])
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
                
                total_cost += e.second;
            }
        }

        // print MST
        const bool PRINT = 1;
        if (PRINT)
        {
            std::cout << "Edges of MST by Kruskal (In processing order, aka increasing order by weights):" << std::endl;
            for (auto e:A)
            {
                for (auto x:e)
                    std::cout << x << " ";
                std::cout << std::endl;
            }
            std::cout << "Total cost :" << total_cost << std::endl;
        }

    }

    template <class T>
    void MST<T>::Prim(ga::graphPtr<T> G, T r)
    {   
        float total_cost = 0;
        // set the distance of r node as 0
        (G->idxToNode[r])->distance = 0;
        // use min heap
        auto comp = [](ga::nodePtr<T> a, ga::nodePtr<T> b) { return a->distance > b->distance; };
	    std::priority_queue <ga::nodePtr<T>, std::vector<ga::nodePtr<T>>, decltype(comp)> Q(comp);
        for (auto v_obj:G->V_obj)
            Q.push(v_obj);
        // make a copy of vector which contains all elements of Q
        std::vector<T> Q_idx = G->V;
        
        while (!Q.empty())
        {
            ga::nodePtr<T> u_node = Q.top();
            for (auto v : G->adjList[u_node->nodeIdx])
            {   
                // edge (u,v)
                std::vector<T> e_uv {u_node->nodeIdx, v};
                // weight of edge (u,v)
                float w_uv = G->E_w_map[e_uv];
                // if v in Q_idx
                if (std::find(Q_idx.begin(), Q_idx.end(), v) != Q_idx.end()
                    && w_uv < (G->idxToNode[v])->distance )
                {
                    (G->idxToNode[v])->pred = u_node;
                    (G->idxToNode[v])->distance = w_uv;
                    std::cout << u_node->nodeIdx << ' ' << v << std::endl;
                    total_cost += w_uv;
                }
            }
            Q.pop();
            Q_idx.erase(std::remove(Q_idx.begin(), Q_idx.end(), u_node->nodeIdx), Q_idx.end());     
        }
        std::cout << "Total cost :" << total_cost << std::endl;

    }

} // namespace ga