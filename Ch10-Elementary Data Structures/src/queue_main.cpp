#include <iostream>
#include "queue.hpp"
using namespace std;

int main()
{
    Queue<int> queueObj(12, 6);
    queueObj.enqueue(15);
    queueObj.enqueue(6);
    queueObj.enqueue(9);
    queueObj.enqueue(8);
    queueObj.enqueue(4);
    queueObj.printQueue();

    queueObj.enqueue(17);
    queueObj.enqueue(3);
    queueObj.enqueue(5);
    queueObj.printQueue();

    cout << "element being dequeued " << queueObj.dequeue() << endl;
    queueObj.printQueue();
}