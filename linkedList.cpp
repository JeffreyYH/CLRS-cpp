#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode (int x): data(x), next(NULL) {}
};

class list
{
public:
    ListNode *head, *tail;

    // constructor
    list()
    {
        head = NULL;
        tail = NULL;
    }

    // create new node and add new node to the tail
    void addTail(int val)
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
    void addHead(int val)
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
    void insertNodeAfterElement(int targetElement, int element)
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
    void insertNodeAfterPosition(int pos, int element)
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
    void deleteNode(int element)
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

    void printList()
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
};

int main()
{
    list listObj;
    vector<int> testArr {5, 8, 9, 10, 12};
    for (int i:testArr)
        listObj.addTail(i);
    listObj.printList();

    listObj.addHead(7);
    listObj.printList();

    // insert node with data 18 after 9,
    listObj.insertNodeAfterElement(9, 18);
    listObj.printList();

    // insert node with data 32 after the 6th element (start with 0)
    listObj.insertNodeAfterPosition(6, 32);
    listObj.printList();

    // delete element
    listObj.deleteNode(32);
    listObj.printList();
    cout << listObj.tail->data << endl;

    return 0;
}
