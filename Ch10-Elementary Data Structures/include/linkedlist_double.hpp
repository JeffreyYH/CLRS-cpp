#include <iostream>
using namespace std;

template <class T>
class SingleLinkedList
{
public:
    struct ListNode {
        T key;
        ListNode *prev;
        ListNode *next;
        ListNode(T x) : data(x), next(NULL) {}
    };

    ListNode *head, *tail;

public:
    void list_insert(T x);
}

template <class T>
void list_insert(T val)
{
    ListNode *x = new ListNode(val);
    x->next = head
    ListNode *tempNode = NULL;
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tempNode = head;
        head = newNode;
        head->next = tempNode;
    }
}

