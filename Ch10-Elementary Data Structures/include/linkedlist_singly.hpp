#include <iostream>
using namespace std;

template <typename Dtype>
struct ListNode
{
    Dtype data;
    ListNode *next;
    ListNode (Dtype x): data(x), next(NULL) {}
};

template <class T>
class SinglyLinkedList
{
public:
    ListNode<T> *head, *tail;

public:
    // constructor
    SinglyLinkedList() {head = NULL; tail = NULL;}

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
void SinglyLinkedList<T>::addTail(T val)
{
    ListNode<T> *newNode = new ListNode(val);
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
void SinglyLinkedList<T>::addHead(T val)
{
    ListNode<T> *newNode = new ListNode(val);
    ListNode<T> *tempNode = NULL;
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
void SinglyLinkedList<T>::insertAfterElement(T targetElement, T element)
{
    ListNode<T> *currNode = head;
    ListNode<T> *nodeInsert = new ListNode(element);
    while(currNode)
    {
        if(currNode->data == targetElement)
        {
            ListNode<T> *temp = currNode->next;
            currNode->next = nodeInsert;
            nodeInsert->next = temp;
            return;
        }
        currNode = currNode->next;
    }
}

//insert an element after a certain element
template <class T>
void SinglyLinkedList<T>::insertAfterPosition(int pos, T element)
{
    ListNode<T> *currNode = head;
    ListNode<T> *nodeInsert = new ListNode(element);
    int i = 0;
    while(currNode)
    {
        if (i==pos)
        {
            ListNode<T> *temp = currNode->next;
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
void SinglyLinkedList<T>::deleteNode(T element)
{
    // if the element is head
    if (head->data == element)
    {
        ListNode<T> *tempHead = head;
        head = head->next;
        delete tempHead;
        return;
    }

    // keep in mind that we need to track the previous node too
    ListNode<T> *prevNode = head;
    ListNode<T> *currNode = prevNode->next;
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
void SinglyLinkedList<T>::printList()
{
    // assign head pointer to a temp pointer
    ListNode<T> *currNode = head;
    while(currNode)
    {
        cout << currNode->data << " -> ";
        currNode = currNode->next;
    }
    cout << endl;
}