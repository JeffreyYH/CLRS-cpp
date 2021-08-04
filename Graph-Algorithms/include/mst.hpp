/* implementation of minimum spanning tree */
#include "graphRep.hpp"
#include "disjointSet.hpp"

namespace ga
{   
    // template of this class used for graph node index representation
    template <class T>
    class MST  
    {
    public:
        static void Kruskal (ga::graphPtr<T> G);
        static void Prim_naive (ga::graphPtr<T> G, T r); 
        static void Prim (ga::graphPtr<T> G, T r); 
        static void printMST(std::string method, std::vector<std::vector<T>> MST_edges);    
    };

    template <class T>
    void MST<T>::Kruskal(ga::graphPtr<T> G)
    {   
        float total_cost = 0;
        // A is used to represent MST,
        // which is a set contains all the edges of MST
        std::vector<std::vector<T>> MST_edges;
        DisjointSet<T>::make_set(G->V);  
        DisjointSet<T>::print_sets();

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
            if (DisjointSet<T>::find_set(u) != DisjointSet<T>::find_set(v))
            {
                MST_edges.push_back(e.first);
                // // merge the sets which have u and v
                DisjointSet<T>::union_sets(u, v);
                total_cost += e.second;
            }
        }

        // print MST
        const bool PRINT = 1;
        if (PRINT)
        {
            // In processing order, aka increasing order by weights
            ga::MST<T>::printMST("Kruskal", MST_edges);
            std::cout << "Total cost: " << total_cost << std::endl;
        }

    }

    template <class T>
    void MST<T>::Prim_naive(ga::graphPtr<T> G, T r)
    {    
        float total_cost = 0;

        // set which constains all the vertices in MST  
        std::set<T> S;
        S.insert(r);
        // set the distance of r node as 0
        (G->idxToNode[r])->distance = 0;

        // subset of MST edges
        std::vector<std::vector<T>> A;

        // a set contains all the elements not in MST_vertices;
        std::set<T> V_minus_S;
        for (auto v:G->V)
        {
            if (v!=r)
                V_minus_S.insert(v);
        }
        while (!V_minus_S.empty())
        {   
            // find the lightest edges among all the cuts
            // cuts are edge that one of its endpoint in S and the other in V-S
            std::vector<T> e_ltst;   
            float w_min = FLT_MAX;
            for (auto u:S)
            {
                for (auto v:G->adjList[u])
                {
                    if (V_minus_S.count(v))
                    {
                        std::vector<T> e_uv {u, v};
                        float w_uv = G->E_w_map[e_uv];
                        // in the example graph of Fig.23.5, if we set w_uv <= w_min, in the second iteration,
                        // Prim algorithm will choose edge (b,c)
                        if (w_uv < w_min)
                        {
                            w_min = w_uv;
                            e_ltst = e_uv;
                        }
                    }
                }
            }
            // add v of the lightest edge to S and erase v from V-S
            // and e_ltst[0] should be in S already
            S.insert(e_ltst[1]);
            V_minus_S.erase(e_ltst[1]);
            A.push_back(e_ltst);
            std::cout << e_ltst[0] << ' ' << e_ltst[1] << std::endl;
            total_cost += w_min;
        }
        std::cout<< "using prim" << std::endl;
        std::cout << "Total cost: " << total_cost << std::endl;
    }

    template <class T>
    void MST<T>::Prim (ga::graphPtr<T> G, T r)
    {

    }


    template <class T>
    void MST<T>::printMST(std::string method, std::vector<std::vector<T>> MST_edges)
    {
        std::cout << "Edges of MST by " << method << std::endl;
        for (auto e:MST_edges)
        {
            for (auto x:e)
                std::cout << x << " ";
            std::cout << std::endl;
        }
    }

} // namespace ga