#ifndef BINTREE_HEAP_H
#define BINTREE_HEAP_H

#include <iostream>
using namespace std;

class MaxHeap
{
public:
    maxHeapify();
    buildMaxHeap();
    heapSort();

    // the following implement functions max-priority queue
    heap_maximum();
    heap_extractMax();
    heap_insert();
    heap_increaseKey();
};

#endif //BINTREE_HEAP_H
