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
    std::vector<std::pair<std::vector<char>, float>>
    weightedEdges {
            {{'a','b'},4}, {{'a','h'},8}, 
            {{'b','h'},11}, {{'b','c'},8},
            {{'c','i'},2}, {{'c','f'},4}, {{'c','d'},7},
            {{'d','f'},14}, {{'d','e'},9},
            {{'e','f'},10}, 
            {{'f','g'},2},
            {{'g','i'},6}, {{'g','h'},1},
            {{'h','i'},7}
        };
    bool isUDG = true; 

    // construct graph object
    ga::graphPtr<char> graph (new ga::Graph<char>(isUDG, vertices, edges));
    graph->E_w = weightedEdges;

    // construct weighted edges map
    std::map<std::vector<char>, float> weightedEdge_map;
    for (size_t i=0; i<weightedEdges.size(); ++i)
        weightedEdge_map[weightedEdges[i].first] = weightedEdges[i].second;
     graph->E_w_map = weightedEdge_map;

    // MST
    std::shared_ptr<ga::MST<char>> mst;
    mst->Kruskal(graph);
    mst->Prim(graph);

}


