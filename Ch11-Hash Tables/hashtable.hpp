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

// ================== chained hashed table ==================== //
template <typename Dtype>
struct chainedTableNode
{
    int hashvalue;
    Dtype data;
    chainedTableNode *prev, *next;
    chainedTableNode(int hvalue, Dtype d) {
        hashvalue=hvalue; data=d; prev=NULL; next=NULL;
    };
};

template <class T>
class ChainedHashTable
{
public:
    chainedTableNode<T> **chtable;
    int length;
    ChainedHashTable(int L);
    T chained_hash_search(int k);
    void chained_hash_insert(int hvalue, T data);
    void chained_hash_delete(int k);
    void print_chainedTable();
};

template <class T>
ChainedHashTable<T>::ChainedHashTable(int L)
{
    length = L;
    chtable = new chainedTableNode<T> * [length];
}

template <class T>
void ChainedHashTable<T>::chained_hash_insert(int hvalue, T data)
{
    chainedTableNode<T> *xNode = new chainedTableNode<T> (hvalue, data);
    if (chtable[hvalue] == NULL)
        chtable[hvalue] = xNode;
    else
    {
        chainedTableNode<T> *tempNode = chtable[hvalue];
        chtable[hvalue] = xNode;
        xNode->next = tempNode;
        tempNode->prev = xNode;
    }
}

template <class T>
void ChainedHashTable<T>::print_chainedTable()
{
    cout << endl;
    for (int i=0; i<length; i++) {
        if (chtable[i] == NULL)
            cout << i << ": NULL " << endl;
        else
        {
            cout << i << ": ";
            chainedTableNode<T> * curNode = chtable[i];
            while(curNode)
            {
                cout << curNode->data << "->";
                curNode = curNode ->next;
            }
            cout << "NULL" << endl;
        }
    }
    cout << endl;
}

