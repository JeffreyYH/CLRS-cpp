#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Queue
{
public:
    int *Q;
    int head, tail, length;
    Queue(int maxSize, int initHead);     // constructor
    ~Queue();                            // destructor
    void enqueue(T x);
    T dequeue();
    void printQueue();
};

template <class T>
Queue<T>::Queue(int maxSize, int initHead)
{
    Q = new T[maxSize];
    length = maxSize;
    head = initHead;
    tail = initHead;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] Q;
}

template <class T>
void Queue<T>::enqueue(T x)
{
    Q[tail] = x;
    if (tail == length - 1)
        tail = 0;
    else
        tail ++;
}

template <class T>
T Queue<T>::dequeue()
{
    int x = Q[head];
    if (head == length - 1)
        head = 0;
    else
        head ++;
    return x;
}

template  <class T>
void Queue<T>::printQueue()
{
    cout << "elements: ";
    for (int i=0; i<length; i++)
        cout << Q[i] << ' ';
    cout << endl;
}