#include "shortestPath.hpp"

using std::cout;
using std::endl;

int main()
{
    std::vector<int> vertices {0,3,5,9,11};
    std::vector<std::vector<int>> edges {
                                {0,3}, {0,5}, 
                                {3,5}, {3,9},
                                {5,3}, {5,9}, {5,11},
                                {9,11},
                                {11,9}, {11,0}
                            };
    std::vector<int> weights {3, 5, 
                            2, 6, 
                            1, 4, 6,
                            2,
                            7, 3};
    std::vector<std::vector<int>> weightedEdges = edges;
    for (size_t i=0;i<edges.size(); ++i)
    {
        weightedEdges[i].push_back(weights[i]);
    }
    bool isUndirected = false;

    // get adj list of the graph
    std::shared_ptr<graphAlgo::GraphRep<int>> graphRep(new graphAlgo::GraphRep<int>());
    std::unordered_map<graphAlgo::nodePtr<int>, std::list<graphAlgo::nodePtr<int>>> 
                adjListObj = graphRep->construct_adjList_obj(vertices, edges, isUndirected);

    // search shorted path with Bellman Ford
    std::shared_ptr<graphAlgo::ShortestPath<int>> shortestPath (new graphAlgo::ShortestPath<int>());
    int start_idx = 0;
    // first find the object with index s
    graphAlgo::nodePtr<int> s_node;
    for (auto al:adjListObj)
    {
        if (start_idx == al.first->nodeIdx)
            s_node = al.first;
    }
    shortestPath->Bellman_Ford(adjListObj, weightedEdges, s_node);
}   