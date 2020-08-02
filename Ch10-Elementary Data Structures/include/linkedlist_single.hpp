#include <iostream>
using namespace std;

template <class T>
class SingleLinkedList
{
public:
    struct ListNode
    {
        T data;
        ListNode *next;
        ListNode (int x): data(x), next(NULL) {}
    };

    ListNode *head, *tail;

public:
    // constructor
    SingleLinkedList() { head = NULL; tail = NULL;}

    // create new node and add new node to the tail
    void addTail(T val);

    // create new node and add to the head
    void addHead(T val);

    //insert an element after a certain target element
    void insertAfterElement(T targetElement, T element);

    //insert an element after a certain element
    void insertAfterPosition(int pos, T element);

    // delete one element
    void deleteNode(T element);

    void printList();
};

// create new node and add new node to the tail
template <class T>
void SingleLinkedList<T>::addTail(T val)
{
    ListNode * newNode = new ListNode(val);
    // if the list the empty
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// create new node and add to the head
template <class T>
void SingleLinkedList<T>::addHead(T val)
{
    ListNode *newNode = new ListNode(val);
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

//insert an element after a certain target element
template <class T>
void SingleLinkedList<T>::insertAfterElement(T targetElement, T element)
{
    ListNode *currNode = head;
    ListNode *nodeInsert = new ListNode(element);
    while(currNode)
    {
        if(currNode->data == targetElement)
        {
            ListNode *temp = currNode->next;
            currNode->next = nodeInsert;
            nodeInsert->next = temp;
            return;
        }
        currNode = currNode->next;
    }
}

//insert an element after a certain element
template <class T>
void SingleLinkedList<T>::insertAfterPosition(int pos, T element)
{
    ListNode *currNode = head;
    ListNode *nodeInsert = new ListNode(element);
    int i = 0;
    while(currNode)
    {
        if (i==pos)
        {
            ListNode *temp = currNode->next;
            currNode->next = nodeInsert;
            nodeInsert->next = temp;
            return;
        }
        currNode = currNode->next;
        i++;
    }
}

// delete one element
template <class T>
void SingleLinkedList<T>::deleteNode(T element)
{
    // if the element is head
    if (head->data == element)
    {
        ListNode *tempHead = head;
        head = head->next;
        delete tempHead;
        return;
    }

    // keep in mind that we need to track the previous node too
    ListNode *prevNode = head;
    ListNode *currNode = prevNode->next;
    while(currNode)
    {
        if (currNode->data == element)
        {
            // if the element is tail
            if (currNode->next == NULL)
            {
                tail = prevNode;
                tail->next = NULL;
                delete currNode;
                return;
            }
            else
            {
                prevNode->next = currNode->next;
                delete currNode;
                return;
            }
        }
        prevNode = prevNode->next;
        currNode = prevNode->next;
    }
}

template <class T>
void SingleLinkedList<T>::printList()
{
    // assign head pointer to a temp pointer
    ListNode *currNode = head;
    while(currNode)
    {
        cout << currNode->data << ' ';
        currNode = currNode->next;
    }
    cout << endl;
}






