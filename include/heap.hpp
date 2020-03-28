#include <utility>
#include <iostream>
#include <vector>
#include "myUtils.hpp"

class MaxHeap
{
private:
    MyUtils myUtils;

public:
//    explicit MaxHeap(std::vector<T> A_para)
//    {
//        A = A_para;
//    }

    int parent_idx(int i) {return i/2;}

    int leftChild_idx(int i) {return 2*i;}

    int rightChild_idx(int i) {return 2 * i + 1;}

    template <typename T>
    void maxHeapify(std::vector<T> &A, int i);

    template <typename T>
    void buildMaxHeap(std::vector<T> &A);

//    void heapSort();
//
//    // the following implement functions max-priority queue
//    void heap_maximum();
//    void heap_extractMax();
//    void heap_insert();
//    void heap_increaseKey();


};

//================= member function implementation ==================//
template <typename T>
void MaxHeap::maxHeapify(std::vector<T> &A, int i)
{
    int l = leftChild_idx(i);
    int r = rightChild_idx(i);
    // idx of largest element
    int largest = 0;
    if (l <= A.size() && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= A.size() && A[r] > A[i])
        largest = r;

    if (largest != i)
    {
        myUtils.swap(A[i], A[largest]);
        maxHeapify(A, i);
    }
}

template <typename T>
void MaxHeap::buildMaxHeap(std::vector<T> &A)
{
    for (int i=A.size()/2; i>=0; --i)
        maxHeapify(A, i);

}

//void MaxHeap::heapSort();

//void MaxHeap::heap_maximum();
//void MaxHeap::heap_extractMax();
//void MaxHeap::heap_insert();
//void MaxHeap::heap_increaseKey();


