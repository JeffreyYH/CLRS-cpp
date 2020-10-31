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
    bool isUndirected = false;

    // construct weighted edges
    std::map<std::vector<char>, float> weightedEdges;
    for (size_t i=0;i<edges.size(); ++i)
    {
        weightedEdges[edges[i]] = weights[i];
    }

    std::shared_ptr<graphAlgo::GraphRep<char>> graphRep(new graphAlgo::GraphRep<char>());
    cout << "Adjacency list:" << endl;
    std::unordered_map<char, std::list<char>> adjList = graphRep->construct_adjList(vertices, edges, isUndirected);
    for (auto l:adjList)
    {
        cout << l.first << "->";
        for (auto it = l.second.begin(); it!=l.second.end(); it++)
            cout << *it << ' ';
        cout << endl;
    }
    // construct graph object
    graphAlgo::graphPtr<char> graph (new graphAlgo::Graph<char>(vertices, edges, adjList));
    graph->E_w = weightedEdges;

    // search shorted path with Bellman Ford
    std::shared_ptr<graphAlgo::ShortestPath<char>> shortestPath (new graphAlgo::ShortestPath<char>());
    char start_idx = 's';
    shortestPath->Bellman_Ford(graph, start_idx);
}   