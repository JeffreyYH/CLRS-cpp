#ifndef BINTREE_HEAP_H
#define BINTREE_HEAP_H

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> A;
public:
    MaxHeap(vector<int> A_para)
    {
        A = A_para;
    }
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
