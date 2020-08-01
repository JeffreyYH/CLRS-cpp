#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
    int *Q;
    int head, tail;
    Queue(int maxSize);       // constructor
    ~Queue();              // destructor
    void enqueue(T x);
    T dequeue();
    void printQueue();
};

template <class T>
Queue::Queue(int maxSize)
{
    Q = new T[maxSize];
    head = 0;
    tail = 0;
}

template <class T>
Queue::~Queue()
{
    delete[] Q;
}

template <class T>
void Queue::enqueue(T x)
{
    Q[tail] = x;
    if

}