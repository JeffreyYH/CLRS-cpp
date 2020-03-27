#include "heap.hpp"

int main()
{
    std::vector<int> A = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    MaxHeap<int> maxHeap(A);
    maxHeap.printHeap();
    return 0;
}