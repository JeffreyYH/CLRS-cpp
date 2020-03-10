#include <iostream>
#include <vector>
using namespace std;

class List
{
public:
    struct ListNode
    {
        int data;
        ListNode *next;
        ListNode (int x): data(x), next(NULL) {}
    };

    ListNode *head, *tail;

public:

    // constructor
    List()
    {
        head = NULL;
        tail = NULL;
    }

    // create new node and add new node to the tail
    void addTail(int val);

    // create new node and add to the head
    void addHead(int val);

    //insert an element after a certain target element
    void insertNodeAfterElement(int targetElement, int element);

    //insert an element after a certain element
    void insertNodeAfterPosition(int pos, int element);

    // delete one element
    void deleteNode(int element);

    void printList();
};


