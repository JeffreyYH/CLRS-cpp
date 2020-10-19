#include <iostream>

// #include "graphRep.hpp" 
#include "basicSearch.hpp"
using namespace std;

int main()
{
    vector<int> vertices {0,1,2,3,4};
    vector<vector<int>> edges {
                                {0,1}, {0,4}, 
                                {1,4}, {1,3}, {1,2},
                                {2,3}, 
                                {3,4}
                            };

    // construct adj matrix
    graphAlgo::GraphRep graphRep;

    cout << "Adjacency matrix:" << endl;
    vector<vector<int>> adjMat = graphRep.construct_adjMat(vertices, edges);
    for(size_t i=0; i<adjMat.size(); ++i)
    {
        for (size_t j=0; j<adjMat[0].size(); ++j)
            cout << adjMat[i][j] << ' ';
        cout << endl;
    }

    // construct adj list
    cout << "Adjacency list:" << endl;
    vector<list<int>> adjList = graphRep.construct_adjList(vertices, edges);
    for (size_t i=0; i<adjList.size(); ++i)
    {
        cout << i << "->";
        for (list<int>::iterator it = adjList[i].begin(); it!=adjList[i].end(); it++)
            cout << *it << ' ';
        cout << endl;
    }

    // do BFS
    graphAlgo::BasicSearch<int> basicSearch;
    int start = 0;
    basicSearch.BFS(adjList, start);

    return 0;
}