#include "basicSearch.hpp"

using std::cout;
using std::endl;

int main()
{
    std::vector<int> vertices {0,1,2,3,4};
    std::vector<std::vector<int>> edges {
                                {0,1}, {0,4}, 
                                {1,4}, {1,3}, {1,2},
                                {2,3}, 
                                {3,4}
                            };
    bool isUndirected = false;
    

    // use smart pointer
    ga::graphPtr<int> graph (new ga::Graph<int>(isUndirected, vertices, edges));

    // print adj matrix
    cout << "Adjacency matrix:" << endl;
    std::vector<std::vector<int>> adjMat = graph->construct_adjMat(vertices, edges, isUndirected);
    for(size_t i=0; i<adjMat.size(); ++i)
    {
        for (size_t j=0; j<adjMat[0].size(); ++j)
            cout << adjMat[i][j] << ' ';
        cout << endl;
    }

    // print adj list
    cout << "Adjacency list:" << endl;
    for (auto l:graph->adjList)
    {
        cout << l.first << "->";
        for (auto it = l.second.begin(); it!=l.second.end(); it++)
            cout << *it << ' ';
        cout << endl;
    }

    // do BFS
    cout << "BFS: " << endl;
    int start = 0;
    ga::BasicSearch<int>::BFS(graph->adjList, start);
    // do DFS
    cout << "DFS: " << endl;
    ga::BasicSearch<int>::DFS(vertices, graph->adjList);

    // do BFS object
    cout << "BFS Object: " << endl;
    ga::ElementaryAlgo<int>::BFS(graph, start);
    // do queue based BFS
    cout << "BFS Queue: " << endl;
    ga::ElementaryAlgo<int>::BFS_queue(graph, start);
    cout << "DFS object:" << endl;
    ga::ElementaryAlgo<int>::DFS(graph);

    // construct another graph and do topological sort
    std::vector<int> vertices2 {0,1,2,3};
    std::vector<std::vector<int>> edges2 {
                                {0,1}, {0,2}, 
                                {1,3},
                                {2,3}
                            };
    ga::graphPtr<int> graph2 (new ga::Graph<int>(false, vertices2, edges2));
    cout << "Topological sort:" << endl;
    ga::ElementaryAlgo<int>::topologicalSort(graph2);

    return 0;
}
