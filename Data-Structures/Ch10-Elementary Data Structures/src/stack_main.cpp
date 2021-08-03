#include <iostream>
#include "stack.hpp"

int main()
{
    Stack<int> stackObj(100);
    cout << "stack empty: " << stackObj.stack_empty() << endl;
    stackObj.push(10);
    stackObj.push(20);
    stackObj.push(3);
    stackObj.printStack();
    cout << "The element which got popped " << stackObj.pop() << endl;
    stackObj.printStack();
    return 0;
}