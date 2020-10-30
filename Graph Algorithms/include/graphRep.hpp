#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

namespace graphAlgo
{   
    template <class T>
    class GraphNode
    {
        public:
        std::string color; // WHITE: not expanded, BLACK: , GRAY:
        GraphNode * pred;
        T nodeIdx;
        
        GraphNode(T idx) {nodeIdx = idx; pred = nullptr;};
    };
    
    // define a smart pointer for GraphNode object
    template <class T>
    using nodePtr = std::shared_ptr<graphAlgo::GraphNode<T>>;

    template <class T>
    class GraphRep
    {
        public:
        std::vector<std::vector<T>> 
        construct_adjMat(std::vector<T> vertices, std::vector<std::vector<T>> edges);

        std::vector<std::list<T>> 
        construct_adjList(std::vector<T> vertices, std::vector<std::vector<T>> edges);

        std::vector<std::list<nodePtr<T>>> 
        construct_adjList_obj(std::vector<T> vertices, std::vector<std::vector<T>> edges);

    };

    template <class T>
    std::vector<std::vector<T>> 
    GraphRep<T>::construct_adjMat(std::vector<T> vertices, std::vector<std::vector<T>> edges)
    {   
        size_t size = vertices.size();
        std::vector<std::vector<T>> adjMat (size, std::vector<T>(size, 0));
        for(size_t i=0; i<edges.size(); ++i)
        {   
            adjMat[edges[i][0]][edges[i][1]] = 1;      
            adjMat[edges[i][1]][edges[i][0]] = 1;  
        }

        return adjMat;
    }

    template <class T>
    std::vector<std::list<T>> 
    GraphRep<T>::construct_adjList(std::vector<T> vertices, std::vector<std::vector<T>> edges)
    {
        size_t size = vertices.size();
        std::vector<std::list<T>> adjList(size);
        for (size_t i=0; i<edges.size(); i++)
        {
            T v0 = edges[i][0];
            T v1 = edges[i][1];

            // v1 not in adjList[v0]
            if (std::find(adjList[v0].begin(), adjList[v0].end(), v1) == adjList[v0].end())
                adjList[v0].push_back(v1);
            
            // v0 not in adjList[v1]
            if (std::find(adjList[v1].begin(), adjList[v1].end(), v0) == adjList[v1].end())
                adjList[v1].push_back(v0);
        }

        return adjList;
    }

     // adj list of graph node object
    template <class T>
    std::vector<std::list<nodePtr<T>>> 
    GraphRep<T>::construct_adjList_obj(std::vector<T> vertices, std::vector<std::vector<T>> edges)
    {
        size_t size = vertices.size();
        std::vector<std::list<nodePtr<T>>> adjListObj(size);
        // first use adjList to get idx
        std::vector<std::list<T>> adjList = construct_adjList(vertices, edges);
        for (size_t i=0; i<adjList.size(); i++)
        {
            for (auto it=adjList[i].begin(); it!=adjList[i].end(); ++it)
            {
                graphAlgo::nodePtr<T> node (new graphAlgo::GraphNode<T>(*it));
                adjListObj[i].push_back(node);
            }
        }

        return adjListObj;
    }

} // namespace graphAlgo