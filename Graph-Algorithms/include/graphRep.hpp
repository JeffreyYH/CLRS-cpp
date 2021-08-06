#include "commonInclude.h"

namespace ga // graph algorithms
{   
    // edge node in graph
    template <class T>
    class GraphNode
    {
    public:
        T nodeIdx;
        std::string color; // WHITE: not visted, BLACK: visited, GRAY: prepare to visit
        std::shared_ptr<GraphNode<T>> pred;  // predecessor
        float distance;
        int finish_step; //for DFS
        
        GraphNode(T idx) {nodeIdx = idx; color = "WHITE"; pred = nullptr; distance = FLT_MAX; finish_step = 0;};
    }; 
    // define a smart pointer for GraphNode object
    template <class T>
    using nodePtr = std::shared_ptr<ga::GraphNode<T>>;

    // edge in graph, not used yet
    template <class T>
    class Edge
    {
    public:
        std::vector<T> edge;
        float w;
    };
    template <class T>
    using edgePtr = std::shared_ptr<ga::Edge<T>>;

    // graph
    template <class T>
    class Graph
    {
    public:
        bool isUndirected;
        std::vector<nodePtr<T>> V_obj;
        std::vector<T> V;
        std::vector<std::vector<T>> E;
        std::unordered_map<T, std::list<T>> adjList;
        // weighted edge, optional
        std::vector<std::pair<std::vector<T>, float>> E_w;
        std::map<std::vector<T>, float> E_w_map;  //std::map can map vector to float/int/etc.
        // use hashtable to map idx to object
        std::unordered_map<T, nodePtr<T>> idxToNode; 
    
    public:
        std::vector<std::vector<T>> 
        construct_adjMat(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected)
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

        std::unordered_map<T, std::list<T>> 
        construct_adjList(std::vector<T> vertices, std::vector<std::vector<T>> edges, bool isUndirected)
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

        // constructor
        Graph(bool _isUndirected_, 
            std::vector<T> _V_, 
            std::vector<std::vector<T>> _E_) 
        {
            isUndirected = _isUndirected_;
            V = _V_;
            E = _E_;
            adjList = this->construct_adjList(V, E, isUndirected);
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
    using graphPtr = std::shared_ptr<ga::Graph<T>>;

} // namespace ga