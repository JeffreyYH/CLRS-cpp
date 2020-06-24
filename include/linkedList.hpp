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

// create new node and add new node to the tail
void List::addTail(int val)
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
void List::addHead(int val)
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
void List::insertNodeAfterElement(int targetElement, int element)
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
void List::insertNodeAfterPosition(int pos, int element)
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
void List::deleteNode(int element)
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

void List::printList()
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






