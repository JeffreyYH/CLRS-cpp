#include "graphRep.hpp"

namespace ga // graph algorithms
{   
    template <class T>
    class ShortestPath
    {
        public:
        void Bellman_Ford(ga::graphPtr<T> G, T s_idx);
        void Dijkstra(ga::graphPtr<T> G, T s_idx);
    };

    template <class T>
    void ShortestPath<T>::Bellman_Ford(ga::graphPtr<T> G, T s_idx)
    {
        ga::nodePtr<T> s_node = G->idxToNode[s_idx];
        s_node->distance = 0;
        // from start to each of these vertices:
        for (auto vertex:G->V)
        {   
            // process all vertices except start
            if (vertex == s_idx)
                continue;

            for (auto edge:G->E) 
            {
                ga::nodePtr<T> u_node = G->idxToNode[edge[0]];
                ga::nodePtr<T> v_node = G->idxToNode[edge[1]];
                float weight_uv = G->E_w_map[edge];
                // relax (u, v, weight_uv)
                if (v_node->distance > u_node->distance + weight_uv)
                {
                    v_node->distance = u_node->distance + weight_uv;
                    v_node->pred = u_node;
                }
            }
        }
        // check negative-weight cycle
        for (auto edge:G->E) 
        {
            ga::nodePtr<T> u_node = G->idxToNode[edge[0]];
            ga::nodePtr<T> v_node = G->idxToNode[edge[1]];
            if (v_node->distance > u_node->distance + G->E_w_map[edge])
            {
                std::cout << "Megative-weight cycle exists" << std::endl;
                return;
            }
        }
    }


    template <class T>
    void ShortestPath<T>::Dijkstra(ga::graphPtr<T> G, T s_idx)
    {   
        // INITIALIZE-SINGLE-SOURCE(G, s)
        G->idxToNode[s_idx]->distance = 0;

        std::set<T> S;

        // each element in prioty queue is a <vertex_type, verex's distance> pair
        auto comp = []( std::pair<T, float> a, std::pair<T, float> b ) { 
            return a.second> b.second; 
        };
        std::priority_queue <std::pair<T, float>, 
                            std::vector<std::pair<T, float>>, 
                            decltype(comp)> Q(comp);
        // put all vertices inside the queue
        for (auto v:G->V)
        {
            float d_v = G->idxToNode[v]->distance;
            Q.push(std::make_pair(v, d_v));
            std::cout << v << ' ' << d_v << std::endl;
        }

        while (!Q.empty())
        {
            std::pair<T, float> u_pair = Q.top();
            Q.pop();
            T u = u_pair.first;
            S.insert(u);
            for (auto v:G->adjList[u])
            {
                // relax (u, v, w)
                ga::nodePtr<T> u_node = G->idxToNode[u];
                ga::nodePtr<T> v_node = G->idxToNode[v];
                std::vector<T> cur_edge {u, v};
                float weight_uv = G->E_w_map[cur_edge];
                if (v_node->distance > u_node->distance + weight_uv)
                {
                    v_node->distance = u_node->distance + weight_uv;
                    v_node->pred = u_node;
                }
            }
        }
    }

} // namespace ga