#include "shortestPath.hpp"

using std::cout;
using std::endl;


int main()
{
    std::vector<char> vertices {'s', 't', 'x', 'y', 'z'};
    std::vector<std::vector<char>> edges {
                                {'s','t'}, {'s','y'}, 
                                {'t','y'}, {'t','x'},
                                {'y','t'}, {'y','x'}, {'y','z'},
                                {'x','z'},
                                {'z','x'}, {'z','s'}
                            };
    std::vector<float> weights {3, 5, 
                            2, 6, 
                            1, 4, 6,
                            2,
                            7, 3};
    bool isUndirected = false;  // if directed graph, edge represent e[0] -> e[1]

    // construct weighted edges
    std::map<std::vector<char>, float> weightedEdges;
    for (size_t i=0;i<edges.size(); ++i)
        weightedEdges[edges[i]] = weights[i];

    // construct graph object
    ga::graphPtr<char> graph (new ga::Graph<char>(isUndirected, vertices, edges));
    graph->E_w = weightedEdges;

    // search shorted path with Bellman Ford
    std::shared_ptr<ga::ShortestPath<char>> shortestPath (new ga::ShortestPath<char>());
    char start_idx = 's', goal_idx = 'z';
    shortestPath->Bellman_Ford(graph, start_idx);
}   