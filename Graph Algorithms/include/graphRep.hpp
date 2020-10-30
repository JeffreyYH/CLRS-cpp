#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>

namespace graphAlgo
{   
    template <class T>
    class GraphNode
    {
        public:
        T nodeIdx;
        std::string color; // WHITE: not visted, BLACK: visited, GRAY: prepare to visit
        std::shared_ptr<graphAlgo::GraphNode<T>> pred;  // predecessor
        int level;
        
        GraphNode(T idx) {nodeIdx = idx; color = "WHITE"; pred = nullptr; level = INT_MAX;};
    };
    
    // define a smart pointer for GraphNode object
    template <class T>
    using nodePtr = std::shared_ptr<graphAlgo::GraphNode<T>>;

    template <class T>
    class GraphRep
    {
        public:
        std::vector<std::vector<T>> 
        construct_adjMat(std::vector<T> vertices, std::vector<std::vector<T>> edges, std::string graph_type);

        std::vector<std::list<T>> 
        construct_adjList(std::vector<T> vertices, std::vector<std::vector<T>> edges, std::string graph_type);

        std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> 
        construct_adjList_obj(std::vector<T> vertices, std::vector<std::vector<T>> edges, std::string graph_type);

    };

    template <class T>
    std::vector<std::vector<T>> 
    GraphRep<T>::construct_adjMat(std::vector<T> vertices, std::vector<std::vector<T>> edges, std::string graph_type)
    {   
        size_t size = vertices.size();
        std::vector<std::vector<T>> adjMat (size, std::vector<T>(size, 0));
        for(size_t i=0; i<edges.size(); ++i)
        {   
            adjMat[edges[i][0]][edges[i][1]] = 1; 
            if (graph_type == "undirected")     
                adjMat[edges[i][1]][edges[i][0]] = 1;  
        }

        return adjMat;
    }

    template <class T>
    std::vector<std::list<T>> 
    GraphRep<T>::construct_adjList(std::vector<T> vertices, std::vector<std::vector<T>> edges, std::string graph_type)
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
            
            if (graph_type == "undirected")
            { 
                // v0 not in adjList[v1]
                if (std::find(adjList[v1].begin(), adjList[v1].end(), v0) == adjList[v1].end())
                    adjList[v1].push_back(v0);
            }   
        }

        return adjList;
    }

     // adj list of graph node object
    template <class T>
    std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> 
    GraphRep<T>::construct_adjList_obj(std::vector<T> vertices, std::vector<std::vector<T>> edges, std::string graph_type)
    {
        size_t size = vertices.size();
        // use hashtable to map idx to object
        std::unordered_map<T,graphAlgo::nodePtr<T>> idxToNode; 
        for (auto v:vertices)
        {
            graphAlgo::nodePtr<T> node (new graphAlgo::GraphNode<T>(v));
            idxToNode[v] = node;
        }

        std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>>  adjListObj;
        std::vector<std::list<T>> adjList = construct_adjList(vertices, edges, graph_type);
        for (size_t i=0; i<adjList.size(); i++)
        {
            for (auto it=adjList[i].begin(); it!=adjList[i].end(); ++it)
            {
                adjListObj[idxToNode[i]].push_back(idxToNode[*it]);
            }
        }

        return adjListObj;
    }

} // namespace graphAlgo