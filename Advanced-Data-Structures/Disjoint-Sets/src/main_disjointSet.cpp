#include "disjointSet.hpp"
#include "disjointSet_index.hpp"

int main()
{
    std::vector<int> allMembers {0,1,2,3,4,5};
    bool useIdx = true;
    if (!useIdx) {
        DisjointSet<int>::make_set(allMembers);
        std::cout << "AInitial sets: " << std::endl;
        DisjointSet<int>::print_sets();

        DisjointSet<int>::union_sets(0, 1);
        std::cout << "After set union: " << std::endl;
        DisjointSet<int>::print_sets();

        DisjointSet<int>::union_sets(0, 2);
        std::cout << "After set union: " << std::endl;
        DisjointSet<int>::print_sets();

    }
    // test index based implementation
    else 
    {
        DisjointSetIdx::make_set(allMembers);
        std::cout << "AInitial sets: " << std::endl;
        DisjointSetIdx::print_sets();

        DisjointSetIdx::union_sets(0, 1);
        std::cout << "After set union: " << std::endl;
        DisjointSetIdx::print_sets();

        DisjointSetIdx::union_sets(0, 2);
        std::cout << "After set union: " << std::endl;
        DisjointSetIdx::print_sets();

        DisjointSetIdx::union_sets(3, 4);
        std::cout << "After set union: " << std::endl;
        DisjointSetIdx::print_sets();

        DisjointSetIdx::union_sets(1, 4);
        std::cout << "After set union: " << std::endl;
        DisjointSetIdx::print_sets();

    }
};
