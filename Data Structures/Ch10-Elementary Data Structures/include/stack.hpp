#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

template <class T>
class Stack
{
public:
    int *S;
    int top;
    Stack(int L);       // constructor
    ~Stack();              // destructor
    bool stack_empty();
    void push(T x);
    T pop();
    void printStack();
};

template <class T>
Stack<T>::Stack(int maxSize)
{
    S = new T[maxSize];
    top = -1;
    // Note top should NOT be assigned as 0,
    // since if top is 0 that means there is 1 element S[0] in S
}

template <class T>
Stack<T>::~Stack()
{
    delete[] S;
}

template <class T>
bool Stack<T>::stack_empty()
{
    if (top == -1)
        return true;
    else
        return false;
}

template <class T>
void Stack<T>::push(T x)
{
    top ++;
    S[top] = x;
}

template <class T>
T Stack<T>::pop()
{
    if (stack_empty())
        cerr << "stack underflow" << endl;
    else
        top --;
    return S[top+1];
}

template <class T>
void Stack<T>::printStack()
{
    cout << "Stack length " << top+1 << ", ";
    cout << "elements: ";
    for (int i=0; i<=top; i++)
        cout << S[i] << ' ';
    cout << endl;
}