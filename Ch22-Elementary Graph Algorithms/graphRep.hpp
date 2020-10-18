#include <iostream>
#include <list>
#include <vector>

namespace graphAlgorithms
{
    template <class T>
    class GraphRep
    {
        public:
        std::vector<std::vector<T>> construct_adjMat(int size, std::vector<std::vector<int>> edges);
        std::vector<std::list<T>> construct_adjList(int size, std::vector<std::vector<int>> edges);

    };

    template <class T>
    std::vector<std::vector<T>> 
    GraphRep<T>::construct_adjMat(int size, std::vector<std::vector<int>> edges)
    {   
        std::vector<std::vector<T>> adjMat (size, std::vector<T>(size));
        for (size_t i=0; i<size; ++i)
        {
            for (size_t j=0; j<size; ++j)
                adjMat[i][j] = 0;
        }
        for(size_t i=0; i<edges.size(); ++i)
        {   
            adjMat[edges[i][0]][edges[i][1]] = 1;       
        }

        return adjMat;
    }

    template <class T>
    std::vector<std::list<T>> 
    GraphRep<T>:: construct_adjList(int size, std::vector<std::vector<int>> edges)
    {
        std::vector<std::list<T>> adjList(size);
        for (size_t i=0; i<edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }

        return adjList;
    }

} // end of namespace