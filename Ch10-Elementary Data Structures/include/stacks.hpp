#include <iostream>
using namespace std;

template <class T>
class Stacks
{
public:
    int *S;
    int top;
    Stacks(int size);       // constructor
    ~Stacks();              // destructor
    bool stack_empty();
    void push(T x);
    T pop();
    void printStack();
};

template <class T>
Stacks<T>::Stacks(int size)
{
    S = new T[size];
    top = -1;
}

template <class T>
Stacks<T>::~Stacks()
{
    delete[] S;
}

template <class T>
bool Stacks<T>::stack_empty()
{
    if (top == 0)
        return true;
    else
        return false;
}

template <class T>
void Stacks<T>::push(T x)
{
    top ++;
    S[top] = x;
}

template <class T>
T Stacks<T>::pop()
{
    if (stack_empty())
        cerr << "stack underflow" << endl;
    else
        (top --);
    return S[top+1];
}

template <class T>
void Stacks<T>::printStack()
{
    for (int i=0; i<=top; i++)
        cout << S[i] << ' ';
    cout << endl;
}