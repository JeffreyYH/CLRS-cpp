#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

namespace graphAlgo
{
    class GraphRep
    {
        public:
        std::vector<std::vector<int>> 
        construct_adjMat(std::vector<int> vertices, std::vector<std::vector<int>> edges);

        std::vector<std::list<int>> 
        construct_adjList(std::vector<int> vertices, std::vector<std::vector<int>> edges);

    };

    std::vector<std::vector<int>> 
    GraphRep::construct_adjMat(std::vector<int> vertices, std::vector<std::vector<int>> edges)
    {   
        size_t size = vertices.size();
        std::vector<std::vector<int>> adjMat (size, std::vector<int>(size, 0));
        for(size_t i=0; i<edges.size(); ++i)
        {   
            adjMat[edges[i][0]][edges[i][1]] = 1;      
            adjMat[edges[i][1]][edges[i][0]] = 1;  
        }

        return adjMat;
    }

    std::vector<std::list<int>> 
    GraphRep:: construct_adjList(std::vector<int> vertices, std::vector<std::vector<int>> edges)
    {
        size_t size = vertices.size();
        std::vector<std::list<int>> adjList(size);
        for (size_t i=0; i<edges.size(); i++)
        {
            int v0 = edges[i][0];
            int v1 = edges[i][1];

            // v1 not in adjList[v0]
            if (std::find(adjList[v0].begin(), adjList[v0].end(), v1) == adjList[v0].end())
                adjList[v0].push_back(v1);
            
            // v0 not in adjList[v1]
            if (std::find(adjList[v1].begin(), adjList[v1].end(), v0) == adjList[v1].end())
                adjList[v1].push_back(v0);
        }

        return adjList;
    }

} // namespace graphAlgo