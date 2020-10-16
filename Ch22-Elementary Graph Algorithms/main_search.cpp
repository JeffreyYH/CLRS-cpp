#include <iostream>

// #include "graphRep.hpp" 
#include "basicSearch.hpp"
using namespace std;

int main()
{
    const int size = 5;
    vector<vector<int>> edges {
                                {0,1}, {0,4}, 
                                {1,0}, {1,2}, {1,3}, {1,4}, 
                                {2,1}, {2,3}, 
                                {3,1}, {3,2}, {3,4}, 
                                {4,0}, {4,1}, {4,3}
                            };

    // construct adj matrix
    GraphRep<int> g_rep;

    cout << "Adjacency matrix:" << endl;
    vector<vector<int>> adjMat = g_rep.construct_adjMat(size, edges);
    for(size_t i=0; i<adjMat.size(); ++i)
    {
        for (size_t j=0; j<adjMat[0].size(); ++j)
            cout << adjMat[i][j] << ' ';
        cout << endl;
    }

    // construct adj list
    cout << "Adjacency list:" << endl;
    vector<list<int>> adjList = g_rep.construct_adjList(size, edges);
    for (size_t i=0; i<adjList.size(); ++i)
    {
        cout << i << "->";
        for (list<int>::iterator it = adjList[i].begin(); it!=adjList[i].end(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;
    }

    return 0;
}