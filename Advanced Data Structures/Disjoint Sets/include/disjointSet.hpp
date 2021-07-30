#include "commonInclude.h"

template <class T>
class DisjointSet  
{
public:
    static std::map<T, std::shared_ptr<std::set<T>>> setReps;
public:
    static void make_set (std::vector<T> &allMembers);
    static void union_set (T a, T b); 
    static std::shared_ptr<std::set<T>> find_set (T x); 
    static void print_sets();
};

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
void DisjointSet<T>::union_set (T a, T b)
{
    auto a_set = find_set(a);
    auto b_set = find_set(b);
    DisjointSet<T>::setReps[a] = b_set;
}

template <class T>
void DisjointSet<T>::print_sets () 
{
    for (auto hh : DisjointSet<int>::setReps)
    {
        std::cout << hh.first << " in set ";
        for (auto s: *(hh.second))
            std::cout << s << ' ';
        std::cout << std::endl;
    }
}