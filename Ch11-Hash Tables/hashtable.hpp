#include <iostream>
using namespace std;

template <typename Dtype>
struct tableNode
{
    Dtype value;
    int key;
};

template <class T>
class HashTable
{
public:
    tableNode<T> *htable;
    HashTable(int length) { htable = new tableNode<T> [length];};
    void direct_address_search(int k) { return htable[k];};
//    void direct_address_insert(tableNode<T> *x) { table[k] = x;};
//    void direct_address_delete(tableNode<T> *x) {table};
//    void hash_insert(int k);
//    void hash_search(int k);
};

