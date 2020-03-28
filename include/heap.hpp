#include <iostream>
#include <vector>
#include "myUtils.hpp"

template <class T>
class MaxHeap
{
private:
    MyUtils myUtils;
    std::vector<T> A;

public:
    explicit MaxHeap(std::vector<T> &A_) {A = A_;}
    int parent_idx(int i);
    int leftChild_idx(int i);
    int rightChild_idx(int i);
    void maxHeapify(std::vector<T> &A,  int i);
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
int MaxHeap<T>::parent_idx(int i)
{
    return (i/2);
}

template <class T>
int MaxHeap<T>::leftChild_idx(int i)
{
    if ((2*i+1) < A.size())
        return 2*i + 1;
    else
        return -1;
}

template <class T>
int MaxHeap<T>::rightChild_idx(int i)
{
    if ((2*i+2) < A.size())
        return (2*i+2);
    else
        return -1;
}

template <class T>
void MaxHeap<T>::maxHeapify(std::vector<T> &A, int i)
{
    int l = leftChild_idx(i);
    int r = rightChild_idx(i);
    if ( l==-1 || r == -1)
        return;

    // idx of largest element
    int largest = 0;
    if (l < A.size() && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r < A.size() && A[r] > A[i])
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
    for (int i=A.size()/2; i>=0; --i)
    {
        myUtils.swap(A[0], A[i]);
        maxHeapify(A, i);
    }
}

//void MaxHeap::heap_maximum();
//void MaxHeap::heap_extractMax();
//void MaxHeap::heap_insert();
//void MaxHeap::heap_increaseKey();


