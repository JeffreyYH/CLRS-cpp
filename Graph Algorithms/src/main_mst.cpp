#include "mst.hpp"

int main()
{
    std::vector<char> vertices {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    std::vector<std::vector<char>> edges {
                                {'a','b'}, {'a','h'}, 
                                {'b','h'}, {'b','c'},
                                {'c','i'}, {'c','f'}, {'c','d'},
                                {'d','f'}, {'d','e'},
                                {'e','f'}, 
                                {'f','g'}, 
                                {'g','i'}, {'g','h'},
                                {'h','i'},
                            };
    std::vector<float> weights {

                            };
    bool isUDG = true; 

}