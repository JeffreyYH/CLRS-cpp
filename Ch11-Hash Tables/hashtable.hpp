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
    void print_table();
//    void direct_address_delete(tableNode<T> *x) {table};
};

template <class T>
T HashTable<T>::direct_address_search(int k)
{
    return htable[k];
}

template <class T>
void HashTable<T>::direct_address_insert(int k, T x)
{
    tableNode<T> * xNode = new tableNode<T> (k, x);
    htable[xNode->key] = xNode;
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


