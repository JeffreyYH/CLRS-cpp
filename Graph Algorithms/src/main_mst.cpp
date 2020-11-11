#include "mst.hpp"

int main()
{
    std::vector<char> vertices {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    std::vector<std::vector<char>> edges {
                                {'a','b'}, {'a','h'}, 
                                {'t','y'}, {'t','x'},
                                {'y','t'}, {'y','x'}, {'y','z'},
                                {'x','z'},
                                {'z','x'}, {'z','s'}
                            };
    std::vector<float> weights {3, 5, 
                            2, 6, 
                            1, 4, 6,
                            2,
                            7, 3};
    bool isUDG = true; 

}