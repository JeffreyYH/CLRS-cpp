#include <iostream>
#include <memory>
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

    // construct adj matrix
    // use smart pointer
    std::shared_ptr<graphAlgo::GraphRep<int>> graphRep(new graphAlgo::GraphRep<int>());

    cout << "Adjacency matrix:" << endl;
    std::vector<std::vector<int>> adjMat = graphRep->construct_adjMat(vertices, edges);
    for(size_t i=0; i<adjMat.size(); ++i)
    {
        for (size_t j=0; j<adjMat[0].size(); ++j)
            cout << adjMat[i][j] << ' ';
        cout << endl;
    }

    // construct adj list
    cout << "Adjacency list:" << endl;
    std::vector<std::list<int>> adjList = graphRep->construct_adjList(vertices, edges);
    for (size_t i=0; i<adjList.size(); ++i)
    {
        cout << i << "->";
        for (auto it = adjList[i].begin(); it!=adjList[i].end(); it++)
            cout << *it << ' ';
        cout << endl;
    }

    // construct adj list object
    cout << "Adjacency list object:" << endl;
    std::vector<std::list<graphAlgo::nodePtr<int>>> adjListObj = graphRep->construct_adjList_obj(vertices, edges);
    for (size_t i=0; i<adjListObj.size(); ++i)
    {
        cout << i << "->";
        for (auto it = adjListObj[i].begin(); it!=adjListObj[i].end(); it++)
            cout << (*it)->nodeIdx << ' ';
        cout << endl;
    }

    // // do BFS
    // cout << "BFS: " << endl;
    // // graphAlgo::BasicSearch<int> basicSearch;
    // std::shared_ptr<graphAlgo::BasicSearch<int>> basicSearch(new graphAlgo::BasicSearch<int>());
    // int start = 0;
    // basicSearch->BFS(adjList, start);

    // // do DFS
    // cout << "DFS: " << endl;
    // basicSearch->DFS(vertices, adjList);

    return 0;
}