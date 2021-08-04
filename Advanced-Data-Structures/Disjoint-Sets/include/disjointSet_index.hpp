#include "commonInclude.h"

class DisjointSetIdx  
{
public:
    static std::vector<int> setReps_Idx;
public:
    static void make_set (std::vector<int> &allMembers);
    static void union_set (int a, int b); 
    static int find_set (int x); 
    static void print_sets();
};

/* ===== Methods implementations ======*/
std::vector<int> DisjointSetIdx::setReps_Idx;

void DisjointSetIdx::make_set(std::vector<int> &allMembers)
{
    for (auto m:allMembers)
        setReps_Idx.push_back(m);
}

int DisjointSetIdx::find_set (int x)
{  
    return DisjointSetIdx::setReps_Idx[x];
}

void DisjointSetIdx::union_set (int a, int b)
{
    return;
}

void DisjointSetIdx::print_sets () 
{
    return;
}