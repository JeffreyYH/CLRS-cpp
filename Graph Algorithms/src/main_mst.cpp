#include "mst.hpp"

int main()
{
    std::vector<char> vertices {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    std::vector<std::vector<char>> edges {
                                {'a','b'}, {'a','h'}, 
                                {'b','h'}, {'b','c'},
                            };
    std::vector<float> weights {3, 5, 
                            2, 6, 
                            1, 4, 6,
                            2,
                            7, 3};
    bool isUDG = true; 

}