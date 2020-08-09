#include <iostream>
using namespace std;

template <typename Dtype>
struct tableNode
{
    int key;
    Dtype val;
    tableNode(int k, Dtype x) {key = k, val = x;};
};

template <class T>
class HashTable
{
public:
    tableNode<T> **htable;
    int length;
    HashTable(int L) { length = L; htable = new tableNode<T> * [length];};
    T direct_address_search(int k);
    void direct_address_insert(int k, T x);
    void direct_address_delete(int k);
    void print_table();
};

template <class T>
T HashTable<T>::direct_address_search(int k)
{
    return htable[k]->val;
}

template <class T>
void HashTable<T>::direct_address_insert(int k, T x)
{
    tableNode<T> * xNode = new tableNode<T> (k, x);
    htable[xNode->key] = xNode;
}


template <class T>
void HashTable<T>::direct_address_delete(int k)
{
    htable[k] = NULL;
}

template <class T>
void HashTable<T>::print_table()
{
    for (int i=0; i<length; i++) {
        if (htable[i] == NULL)
            cout << "NULL" << ' ';
        else
            cout << htable[i]->val << ' ';
    }
    cout << endl;
}


template <class T>
class ChainedHashTable
{
public:
    tableNode<T> **chtable;
    int length;
    ChainedHashTable(int L) { length = L; chtable = new tableNode<T> * [length];};
    T chained_hash_search(int k);
    void chained_hash_insert(int k, T x);
    void chained_hash_delete(int k);
    void print_chained_table();
};

