#include "commonInclude.h"

class DisjointSetIdx  
{
public:
    static std::map<int, int> parent;
public:
    static void make_set (std::vector<int> &allMembers);
    static void union_sets (int a, int b); 
    static int find_set (int x); 
    static void print_sets();
};

/* ===== Methods implementations ======*/
std::map<int, int> DisjointSetIdx::parent;

void DisjointSetIdx::make_set(std::vector<int> &allMembers)
{
    for (auto m:allMembers)
        parent[m] = m;
}

// find the root of the set in which element x belongs
int DisjointSetIdx::find_set (int x)
{  
    if (x == DisjointSetIdx::parent[x])
        return x;
    // recur for the parent until we find the root
    return DisjointSetIdx::find_set(DisjointSetIdx::parent[x]);
}

void DisjointSetIdx::union_sets (int a, int b)
{
    // find the root of the sets in which elements `a` and `b` belongs
    int a_root = DisjointSetIdx::find_set(a);
    int b_root = DisjointSetIdx::find_set(b);
    if (a_root != b_root)
        DisjointSetIdx::parent[b_root] = a_root;
}

void DisjointSetIdx::print_sets () 
{
    for (auto cur_set : DisjointSetIdx::parent)
        std::cout << cur_set.first << " in set with root " << find_set(cur_set.first) << std::endl;
}