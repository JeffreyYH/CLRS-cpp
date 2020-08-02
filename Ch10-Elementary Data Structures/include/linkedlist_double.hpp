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
}

