#include "disjointSet.hpp"
#include "disjointSet_index.hpp"

int main()
{
    std::vector<int> allMembers {1,2,3,4};
    DisjointSet<int>::make_set(allMembers);
    std::cout << "AInitial sets: " << std::endl;
    DisjointSet<int>::print_sets();

    DisjointSet<int>::union_set(2, 3);
    std::cout << "After set union: " << std::endl;
    DisjointSet<int>::print_sets();

    DisjointSet<int>::union_set(3, 4);
    std::cout << "After set union: " << std::endl;
    DisjointSet<int>::print_sets();
    
    // test index based implementation
    DisjointSetIdx::make_set(allMembers);

};
