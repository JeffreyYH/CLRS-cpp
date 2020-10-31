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
    bool isUndirected = true;
    

    // use smart pointer
    std::shared_ptr<graphAlgo::GraphRep<int>> graphRep(new graphAlgo::GraphRep<int>());
    // construct adj matrix
    cout << "Adjacency matrix:" << endl;
    std::vector<std::vector<int>> adjMat = graphRep->construct_adjMat(vertices, edges, isUndirected);
    for(size_t i=0; i<adjMat.size(); ++i)
    {
        for (size_t j=0; j<adjMat[0].size(); ++j)
            cout << adjMat[i][j] << ' ';
        cout << endl;
    }
    // construct adj list
    cout << "Adjacency list:" << endl;
    std::unordered_map<int, std::list<int>> adjList = graphRep->construct_adjList(vertices, edges, isUndirected);
    for (auto l:adjList)
    {
        cout << l.first << "->";
        for (auto it = l.second.begin(); it!=l.second.end(); it++)
            cout << *it << ' ';
        cout << endl;
    }
    // construct graph object
    std::shared_ptr<graphAlgo::Graph<int>> graph (new graphAlgo::Graph<int>(vertices, edges, adjList));


    // graphAlgo::BasicSearch<int> basicSearch;
    std::shared_ptr<graphAlgo::BasicSearch<int>> basicSearch(new graphAlgo::BasicSearch<int>());
    // do BFS
    cout << "BFS: " << endl;
    int start = 0;
    basicSearch->BFS(adjList, start);
    // do DFS
    cout << "DFS: " << endl;
    basicSearch->DFS(vertices, adjList);


    // do BFS obj and queue based BFS
    std::shared_ptr<graphAlgo::BasicSearchObj<int>> basicSearchObj(new graphAlgo::BasicSearchObj<int>());

    // // construct adj list object, represented as a hashtable fron object to list of object
    // cout << "Adjacency list object:" << endl;
    // std::unordered_map<graphAlgo::nodePtr<int>, std::list<graphAlgo::nodePtr<int>>> 
    //         adjListObj = graphRep->construct_adjList_obj(vertices, edges, isUndirected);
    // for (auto l:adjListObj)
    // {
    //     // print key
    //     cout << l.first->nodeIdx << "->";
    //     // print value, which is a list of objects
    //     for (auto it = l.second.begin(); it!=l.second.end(); it++)
    //         cout << (*it)->nodeIdx << ' ';
    //     cout << endl;
    // }

    // // first find the object with index s
    // graphAlgo::nodePtr<int> s_node;
    // for (auto al:adjListObj)
    // {
    //     if (start == al.first->nodeIdx)
    //         s_node = al.first;
    // }

    // do BFS object
    cout << "BFS Object: " << endl;
    basicSearchObj->BFS(graph, start);

    // do queue based BFS
    cout << "BFS Queue: " << endl;
    basicSearchObj->BFS_queue(graph, start);

    return 0;
}
