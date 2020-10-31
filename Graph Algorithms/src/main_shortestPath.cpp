#include "shortestPath.hpp"

using std::cout;
using std::endl;



int main()
{
    std::vector<int> vertices {'s', 't', 'x', 'y', 'z'};
    std::vector<std::vector<int>> edges {
                                {'s','t'}, {'s','y'}, 
                                {'t','y'}, {'t','x'},
                                {'y','t'}, {'y', 'x'}, {'y','z'},
                                {'x','z'},
                                {'z','x'}, {'z','s'}
                            };
    std::vector<float> weights {3, 5, 
                            2, 6, 
                            1, 4, 6,
                            2,
                            7, 3};
    bool isUndirected = false;

    // construct weighted edges
    std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> weightedEdges(edges.size());
    for (size_t i=0;i<edges.size(); ++i)
    {
        std::shared_ptr<graphAlgo::WeightedEdge> wEdge (new graphAlgo::WeightedEdge());
        wEdge->edge = edges[i];
        wEdge->weight = weights[i];
        weightedEdges[i] = wEdge;
    }

    // get adj list of the graph
    std::shared_ptr<graphAlgo::GraphRep<int>> graphRep(new graphAlgo::GraphRep<int>());
    std::unordered_map<graphAlgo::nodePtr<int>, std::list<graphAlgo::nodePtr<int>>> 
                adjListObj = graphRep->construct_adjList_obj(vertices, edges, isUndirected);

    // search shorted path with Bellman Ford
    std::shared_ptr<graphAlgo::ShortestPath<int>> shortestPath (new graphAlgo::ShortestPath<int>());
    int start_idx = 's';
    // first find the object with index s
    graphAlgo::nodePtr<int> s_node;
    for (auto al:adjListObj)
    {
        if (start_idx == al.first->nodeIdx)
            s_node = al.first;
    }
    shortestPath->Bellman_Ford(adjListObj, weightedEdges, s_node);
}   