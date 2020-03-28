#include <iostream>
#include <vector>
#include "myUtils.hpp"

template <class T>
class MaxHeap
{
private:
    MyUtils myUtils;

public:
    int parent_idx(int i) {return i/2;}
    int leftChild_idx(int i) {return 2*i;}
    int rightChild_idx(int i) {return 2 * i + 1;}

    void maxHeapify(std::vector<T> &A, int i);
    void buildMaxHeap(std::vector<T> &A);
    void heapSort(std::vector<T> &A);

//    // member functions for max-priority queue
//    void heap_maximum();
//    void heap_extractMax();
//    void heap_insert();
//    void heap_increaseKey();


};

//================= member function implementation ==================//
template <class T>
void MaxHeap<T>::maxHeapify(std::vector<T> &A, int i)
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

template <class T>
void MaxHeap<T>::buildMaxHeap(std::vector<T> &A)
{
    for (int i=A.size()/2; i>=0; --i)
        maxHeapify(A, i);

}

template <class T>
void MaxHeap<T>::heapSort(std::vector<T> &A)
{
    buildMaxHeap(A);
    for (int i=A.size()/2; i>=1; --i)
    {
        myUtils.swap(A[0], A[i]);
        maxHeapify(A, i);
    }
}

//void MaxHeap::heap_maximum();
//void MaxHeap::heap_extractMax();
//void MaxHeap::heap_insert();
//void MaxHeap::heap_increaseKey();


