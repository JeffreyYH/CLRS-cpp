#include "graphRep.hpp"

namespace ga // graph algorithms
{   
    template <class T>
    class ShortestPath
    {
        public:
        static void Bellman_Ford(ga::graphPtr<T> G, T s_idx, T g_idx);
        static void Dijkstra(ga::graphPtr<T> G, T s_idx, T g_idx);
        static void reconstruct_shortedPath(std::string method, ga::graphPtr<T> G, T s_idx, T g_idx)
        {
            // print all vertices' weights after running the algorithm
            std::cout << "Vertices and distances after applying " << method << ':' << std::endl;
            for (auto v:G->V)
            {
                std::cout << v << ' ' << G->idxToNode[v]->distance << std::endl;
            }

            // construct the shorted path backword and then print it
            std::vector<T> shorted_path {g_idx};
            T cur_idx = g_idx;
            while(cur_idx != s_idx)
            {
                cur_idx = G->idxToNode[cur_idx]->pred->nodeIdx;
                shorted_path.insert(shorted_path.begin(), cur_idx);
            }
            std::cout << "Shorted path by " << method << ':' << std::endl;
            for (auto s_p : shorted_path)
                std::cout << s_p << " ";
            std::cout << std::endl;
        }
    };


    template <class T>
    void ShortestPath<T>::Bellman_Ford(ga::graphPtr<T> G, T s_idx, T g_idx)
    {
        // initialize all vertices
        for (auto v:G->V)
        {
            G->idxToNode[v]->distance = FLT_MAX;
            G->idxToNode[v]->pred = nullptr;
        }
        G->idxToNode[s_idx]->distance = 0;

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

        ga::ShortestPath<T>::reconstruct_shortedPath("Bellman-Ford", G, s_idx, g_idx);
    }


    template <class T>
    void ShortestPath<T>::Dijkstra(ga::graphPtr<T> G, T s_idx, T g_idx)
    {   
        // initialize all vertices
        for (auto v:G->V)
        {
            G->idxToNode[v]->distance = FLT_MAX;
            G->idxToNode[v]->pred = nullptr;
        }
        G->idxToNode[s_idx]->distance = 0;

        std::set<T> S;

        // each element in prioty queue is a <vertex_type, vetex's distance> pair
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

        ga::ShortestPath<T>::reconstruct_shortedPath("Dijkstra", G, s_idx, g_idx);
    }

} // namespace ga