#include <iostream>
#include <vector>
#include "myUtils.hpp"

template <class T>
class MaxHeap
{
private:
    MyUtils myUtils;
    int heap_size;

public:
    // Uncomment this line if you need a constructor
    // explicit MaxHeap() {}

    int parent_idx(int i);
    int leftChild_idx(int i);
    int rightChild_idx(int i);
    void maxHeapify(std::vector<T> &A,  int i);
    void buildMaxHeap(std::vector<T> &A);
    void heapSort(std::vector<T> &A);

    // member functions for max-priority queue
//    void heap_maximum();
//    void heap_extractMax();
//    void heap_insert();
//    void heap_increaseKey();

};

//================= member function implementation ==================//
template <class T>
int MaxHeap<T>::parent_idx(int i)
{
    return ((i-1)/2);
}

template <class T>
int MaxHeap<T>::leftChild_idx(int i)
{
    if ((2*i+1) < heap_size)
        return 2*i + 1;
    else
        return -1;
}

template <class T>
int MaxHeap<T>::rightChild_idx(int i)
{
    if ((2*i+2) < heap_size)
        return (2*i+2);
    else
        return -1;
}

template <class T>
void MaxHeap<T>::maxHeapify(std::vector<T> &A, int i)
{
    int l = leftChild_idx(i);
    int r = rightChild_idx(i);
    if (l == -1 && r == -1)
        return;

    // idx of largest element
    int largest = 0;
    if (l != -1 && l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r != -1 && r < heap_size && A[r] > A[i])
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
    heap_size = A.size();
    for (int i=(A.size()/2-1); i>=0; --i)
        maxHeapify(A, i);

}

template <class T>
void MaxHeap<T>::heapSort(std::vector<T> &A)
{
    buildMaxHeap(A);
    for (int i=(A.size()-1); i>=1; --i)
    {
        myUtils.swap(A[i], A[0]);
        heap_size --;
        maxHeapify(A, 0);
    }
}

//void MaxHeap::heap_maximum();
//void MaxHeap::heap_extractMax();
//void MaxHeap::heap_insert();
//void MaxHeap::heap_increaseKey();


