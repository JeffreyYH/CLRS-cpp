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
        int distance;
        
        GraphNode(T idx) {nodeIdx = idx; color = "WHITE"; pred = nullptr; distance = INT_MAX;};
    };
    
    // define a smart pointer for GraphNode object
    template <class T>
    using nodePtr = std::shared_ptr<graphAlgo::GraphNode<T>>;


    // define weighted edge
    class WeightedEdge
    {
    public:
        std::vector<int> edge;
        float weight;
        WeightedEdge() {edge = {0,0};};
    };

    // graph
    template <class T>
    class Graph
    {
    public:
        std::vector<nodePtr<T>> V_obj;
        std::vector<T> V;
        std::vector<std::vector<T>> E;
        std::unordered_map<T, std::list<T>> adjList;
        std::vector<std::shared_ptr<WeightedEdge>> E_w; // optional
        // use hashtable to map idx to object
        std::unordered_map<T, nodePtr<T>> idxToNode; 

        Graph(std::vector<T> _V_, 
            std::vector<std::vector<T>> _E_,
            std::unordered_map<T, std::list<T>> _adjList_) 
        {
            V = _V_;
            E = _E_;
            adjList = _adjList_;
            for (auto v_i:V)
            {
                nodePtr<T> node (new GraphNode<T>(v_i));
                V_obj.push_back(node);
                idxToNode[v_i] = node;
            }
        };
    };
} // namespace graphAlgo


namespace graphAlgo
{
    // graph representations
    template <class T>
    class GraphRep
    {
        public:
        std::vector<std::vector<T>> 
        construct_adjMat(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected);

        // implement adjList as hashtable
        std::unordered_map<T, std::list<T>> 
        construct_adjList(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected);

        std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> 
        construct_adjList_obj(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected);

    };

    template <class T>
    std::vector<std::vector<T>> 
    GraphRep<T>::construct_adjMat(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected)
    {   
        int size = vertices.size();
        std::vector<std::vector<T>> adjMat (size, std::vector<T>(size, 0));
        for(size_t i=0; i<edges.size(); ++i)
        {   
            adjMat[edges[i][0]][edges[i][1]] = 1; 
            if (isUndirected)     
                adjMat[edges[i][1]][edges[i][0]] = 1;  
        }

        return adjMat;
    }

    template <class T>
    std::unordered_map<T, std::list<T>> 
    GraphRep<T>::construct_adjList(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected)
    {
        std::unordered_map<T, std::list<T>> adjList;
        for (size_t i=0; i<edges.size(); i++)
        {
            T e0 = edges[i][0];
            T e1 = edges[i][1];

            // e1 not in adjList[e0]
            // std::cout << "processing edge (" << e0 << ", " << e1 << ")" << std::endl;
            if (std::find(adjList[e0].begin(), adjList[e0].end(), e1) == adjList[e0].end())
                adjList[e0].push_back(e1);
            
            if (isUndirected)
            { 
                // e0 not in adjList[e1]
                if (std::find(adjList[e1].begin(), adjList[e1].end(), e0) == adjList[e1].end())
                    adjList[e1].push_back(e0);
            }   
        }

        return adjList;
    }

    //  // adj list of graph node object
    // template <class T>
    // std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> 
    // GraphRep<T>::construct_adjList_obj(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected)
    // {
    //     size_t size = vertices.size();
    //     // use hashtable to map idx to object
    //     std::unordered_map<T,graphAlgo::nodePtr<T>> idxToNode; 
    //     for (auto v:vertices)
    //     {
    //         graphAlgo::nodePtr<T> node (new graphAlgo::GraphNode<T>(v));
    //         idxToNode[v] = node;
    //     }

    //     std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> adjListObj;
    //     std::unordered_map<T, std::list<T>> adjList = construct_adjList(vertices, edges, isUndirected);
    //     for (auto al: adjList)
    //     {
    //         for (auto it=al.second.begin(); it!=al.second.end(); ++it)
    //         {
    //             adjListObj[idxToNode[al.first]].push_back(idxToNode[*it]);
    //         }
    //     }

    //     return adjListObj;
    // }

} // namespace graphAlgo