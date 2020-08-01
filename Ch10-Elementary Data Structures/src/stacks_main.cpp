#include <iostream>
#include "stacks.hpp"

int main()
{
    Stacks<int> stackObj(100);
    stackObj.push(10);
    stackObj.push(20);
    stackObj.push(3);
    stackObj.printStack();
    stackObj.pop();
    stackObj.printStack();
    return 0;
}