#include "commonInclude.h"

template <class T>
class DisjointSet  
{
public:
    static std::map<T, std::shared_ptr<std::set<T>>> setReps;
public:
    static void make_set (std::vector<T> &allMembers);
    static void union_sets (T a, T b); 
    static std::shared_ptr<std::set<T>> find_set (T x); 
    static void print_sets();
};

/* ===== Methods implementations ======*/

template< class T >
std::map<T, std::shared_ptr<std::set<T>>> DisjointSet<T>::setReps;

template <class T>
void DisjointSet<T>::make_set(std::vector<T> &allMembers)
{
    for (auto m:allMembers)
    {
        std::shared_ptr<std::set<T>> cur_set (new std::set<T>);
        cur_set->insert(m);
        setReps[m] = cur_set;
    }
}

template< class T >
std::shared_ptr<std::set<T>> DisjointSet<T>::find_set (T x)
{  
    return DisjointSet<T>::setReps[x];
}

template <class T>
void DisjointSet<T>::union_sets (T a, T b)
{
    auto a_set = find_set(a);
    auto b_set = find_set(b);
    std::shared_ptr<std::set<T>> new_jointSet (new std::set<T>);
    // put all the elements previously in their old sets in new joint set
    for (auto ele_a:*a_set)
    { 
        new_jointSet->insert(ele_a);
        DisjointSet<T>::setReps[ele_a] = new_jointSet;
    }
    for (auto ele_b:*b_set)
    {
        new_jointSet->insert(ele_b);
        DisjointSet<T>::setReps[ele_b] = new_jointSet;
    }
}

template <class T>
void DisjointSet<T>::print_sets () 
{
    for (auto cur_setRep : DisjointSet<T>::setReps)
    {
        std::cout << cur_setRep.first << " in set " << cur_setRep.second;
        std::cout << " with member: ";
        for (auto s: *(cur_setRep.second))
            std::cout << s << ' ';
        std::cout << std::endl;
    }
}