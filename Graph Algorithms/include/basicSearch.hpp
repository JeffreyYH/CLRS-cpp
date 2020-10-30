#include "graphRep.hpp"
#include <queue>

#define None -100000

namespace graphAlgo
{
    template <class T>
    class BasicSearch
    {
    public:
        // input graph represented as adjacency lists
        void BFS(std::vector<std::list<T>> adjList, T s);
        void BFS_obj(std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> adjListObj, T s);
        void BFS_queue(std::unordered_map<nodePtr<T>, std::list<nodePtr<T>>> adjListObj, T s);

        // DFS constists of DFS_visit and DFS
        void DFS_visit(std::vector<T> vertices, std::vector<std::list<T>> adjList, 
                    T s, std::unordered_map<T, T> &parent);
        void DFS(std::vector<T> vertices, std::vector<std::list<T>> adjList);
    };

    template <class T>
    void BasicSearch<T>::BFS(std::vector<std::list<T>> adjList, T s)
    {
        std::unordered_map<T, int> level;
        std::unordered_map<T, T> parent;
        level[s] = 0;
        parent[s] = None;
        int i = 1;
        std::vector<T> frontier;
        frontier.push_back(s);
        std::vector<T> next;
        while (!frontier.empty())
        {
            next.clear();
            for (auto u:frontier)
            {
                std:: cout << "Expanding vertex " << u << std::endl;
                for (auto v:adjList[u])
                {
                    // only update unvisited vertices
                    if (level.find(v) == level.end())
                    {
                        level[v] = i;
                        parent[v] = u;
                        next.push_back(v);
                    }
                }
            }
            frontier = next;
            i++;
        }
    }

    template <class T>
    void BasicSearch<T>::BFS_obj(std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, T s)
    {
        // first find the object with index s
        graphAlgo::nodePtr<T> s_node;
        for (auto al:adjListObj)
        {
            if (s == al.first->nodeIdx)
                s_node = al.first;
        }

        std::unordered_map<T, int> level;
        level[s] = 0;
        int i = 1;
        std::vector<graphAlgo::nodePtr<T>> frontier;
        frontier.push_back(s_node);
        std::vector<graphAlgo::nodePtr<T>> next;
        while (!frontier.empty())
        {
            next.clear();
            for (auto u:frontier)
            {
                std:: cout << "Expanding vertex " << u->nodeIdx << std::endl;
                for (auto v:adjListObj[u])
                {
                    // only update unvisited vertices
                    if (level.find(v->nodeIdx) == level.end())
                    {
                        level[v->nodeIdx] = i;
                        v->pred = u;
                        next.push_back(v);
                    }
                }
            }
            frontier = next;
            i++;
        }
    }

    // implement CLRS pg.595, BFS, based on queue
    template <class T>
    void BasicSearch<T>::BFS_queue
    (std::unordered_map<graphAlgo::nodePtr<T>, std::list<graphAlgo::nodePtr<T>>> adjListObj, T s)
    {
        // first find the object with index s
        graphAlgo::nodePtr<T> s_node;
        for (auto al:adjListObj)
        {
            if (s == al.first->nodeIdx)
                s_node = al.first;
        }

        s_node->color = "GRAY";
        s_node->level = 0;
        s_node->pred = nullptr;

        std::queue<graphAlgo::nodePtr<T>> Q;
        Q.push(s_node);
        while(!Q.empty())
        {
            // notice Q.front() means elment at the end of queue
            auto u_node = Q.front();
            std::cout << "visiting vertex " << u_node->nodeIdx << std::endl;
            Q.pop();
            for (auto v_node:adjListObj[u_node])
            {   
                // white means unvisited
                if (v_node->color == "WHITE")
                {
                    v_node->color = "GRAY";
                    v_node->level = u_node->level + 1;
                    v_node->pred = u_node;
                    Q.push(v_node);
                }
            }
            // black means visited
            u_node->color = "BLACK";
        }
    }

    // DFS-visit
    template <class T>
    void BasicSearch<T>::DFS_visit(std::vector<T> vertices, std::vector<std::list<T>> adjList, 
                                    T s, std::unordered_map<T, T> &parent)
    {
        for (auto v: adjList[s])
        {
            // is v not in parent, which means no visited
            if (parent.find(v) == parent.end())
            {
                parent[v] = s;
                std:: cout << "Expanding vertex " << v << std::endl;
                DFS_visit(vertices, adjList, v, parent);
            }
        }
    }

    // DFS
    template <class T>
    void BasicSearch<T>::DFS(std::vector<T> vertices, std::vector<std::list<T>> adjList)
    {
        std::unordered_map<T, T> parent;
        for (auto s:vertices)
        {
            if (parent.find(s) == parent.end())
            {
                parent[s] = None;
                std:: cout << "Expanding vertex " << s << std::endl;
                DFS_visit(vertices, adjList, s, parent);
            }
        }
    }

} // namespace graphAlgo
