#include "mst.hpp"

int main()
{
    std::vector<char> 
    vertices {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    std::vector<std::vector<char>> 
    edges {
            {'a','b'}, {'a','h'}, 
            {'b','h'}, {'b','c'},
            {'c','i'}, {'c','f'}, {'c','d'},
            {'d','f'}, {'d','e'},
            {'e','f'}, 
            {'f','g'}, 
            {'g','i'}, {'g','h'},
            {'h','i'}
        };
    std::vector<float>
    weights {4, 8,
            11, 8,
            2, 4, 7,
            14, 9,
            10,
            2,
            6, 1,
            7
        };
    bool isUDG = true; 

    // construct weighted edges
    std::map<std::vector<char>, float> weightedEdges;
    for (size_t i=0;i<edges.size(); ++i)
        weightedEdges[edges[i]] = weights[i];

    // construct graph object
    ga::graphPtr<char> graph (new ga::Graph<char>(isUDG, vertices, edges));
    graph->E_w = weightedEdges;

    // MST
    std::shared_ptr<ga::MST<char>> mst;
    mst->Kruskal(graph);
    mst->Prim(graph);

}