#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
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
        std::shared_ptr<GraphNode<T>> pred;  // predecessor
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
        // weighted edge, optional
        // std::vector<std::shared_ptr<graphAlgo::WeightedEdge>> E_w;
        std::map<std::vector<T>, float> E_w;  //std::map can map vector to float/int/etc.
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

    // define a smart pointer for Graph object
    template <class T>
    using graphPtr = std::shared_ptr<graphAlgo::Graph<T>>;

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

} // namespace graphAlgo