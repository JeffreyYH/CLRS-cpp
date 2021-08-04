#include "commonInclude.h"

class DisjointSetIdx  
{
public:
    static std::map<int, int> setRoots;
public:
    static void make_set (std::vector<int> &allMembers);
    static void union_set (int a, int b); 
    static int find_set (int x); 
    static void print_sets();
};

/* ===== Methods implementations ======*/
std::map<int, int> DisjointSetIdx::setRoots;

void DisjointSetIdx::make_set(std::vector<int> &allMembers)
{
    for (auto m:allMembers)
        setRoots[m] = m;
}

// find root of the set which x in
int DisjointSetIdx::find_set (int x)
{  
    if (x == DisjointSetIdx::setRoots[x])
        return x;
    return DisjointSetIdx::find_set(DisjointSetIdx::setRoots[x]);
}

void DisjointSetIdx::union_set (int a, int b)
{
    int a_setIdx = DisjointSetIdx::find_set(a);
    int b_setIdx = DisjointSetIdx::find_set(b);
    DisjointSetIdx::setRoots[b] = a_setIdx;
}

void DisjointSetIdx::print_sets () 
{
    for (auto cur_set : DisjointSetIdx::setRoots)
        std::cout << cur_set.first << " in set " << cur_set.second << std::endl;
}