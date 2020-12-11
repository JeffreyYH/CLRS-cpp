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
    std::vector<std::pair<std::vector<char>, float>>
    weightedEdges {
                    {{'s','t'},3}, {{'s','y'},5}, 
                    {{'t','y'},2}, {{'t','x'},6},
                    {{'y','t'},1}, {{'y','x'},4}, {{'y','z'},6},
                    {{'x','z'},2,},
                    {{'z','x'},7}, {{'z','s'},3}
                    };
    bool isUDG = false;  // if directed graph, edge represent e[0] -> e[1]

    // construct graph object
    ga::graphPtr<char> graph (new ga::Graph<char>(isUDG, vertices, edges));
    graph->E_w = weightedEdges;

    // construct weighted edges map
    std::map<std::vector<char>, float> weightedEdge_map;
    for (size_t i=0; i<weightedEdges.size(); ++i)
    {
        weightedEdge_map[weightedEdges[i].first] = weightedEdges[i].second;
        if (isUDG)
        {
            std::vector<char> reveredEdge {weightedEdges[i].first[1], weightedEdges[i].first[0]};
            weightedEdge_map[reveredEdge] = weightedEdges[i].second;
        }
    }
    graph->E_w_map = weightedEdge_map;

    // search shorted path with Bellman Ford
    std::shared_ptr<ga::ShortestPath<char>> shortestPath (new ga::ShortestPath<char>());
    char start_idx = 's', goal_idx = 'z';
    // shortestPath->Bellman_Ford(graph, start_idx);

    shortestPath->Dijkstra(graph, start_idx);
}   