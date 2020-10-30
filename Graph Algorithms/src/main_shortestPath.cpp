#include "shortestPath.hpp"

using std::cout;
using std::endl;

int main()
{
    std::vector<int> vertices {0,3,5,9,11};
    std::vector<std::vector<int>> edges {
                                {0,3}, {0,5}, 
                                {3,5}, {3,9},
                                {5,3}, {5,9}, {5,11},
                                {9,11},
                                {11,9}, {11,0}
                            };
    std::vector<int> weights {3, 5, 
                            2, 6, 
                            1, 4, 6,
                            2,
                            7, 3};
    std::vector<std::vector<int>> weightedEdges = edges;
    for (size_t i=0;i<edges.size(); ++i)
    {
        weightedEdges[i].push_back(weights[i]);
    }
    bool isUndirected = false;
}