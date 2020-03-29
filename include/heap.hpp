#include <iostream>
#include <vector>
#include <limits>
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
    T heap_maximum(std::vector<T> &A);
    T heap_extractMax(std::vector<T> &A);
    void heap_increaseKey(std::vector<T> &A, T i, T key);
    void heap_insert(std::vector<T> &A, T key);

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
    // recover the previous heap size after heap sort
    heap_size = A.size();
}

template <class T>
T MaxHeap<T>::heap_maximum(std::vector<T> &A)
{
    return A[0];
}

template <class T>
T MaxHeap<T>::heap_extractMax(std::vector<T> &A)
{
    if (heap_size < 1)
        std::cerr << "heap underflow" << std::endl;
    T max = A[0];
    // change the first element as the last
    A[0] = A[heap_size-1];
    heap_size --;
    maxHeapify(A, 0);
    return max;
}

template <class T>
void MaxHeap<T>::heap_increaseKey(std::vector<T> &A, T i, T key)
{
    if (key < A[i])
        std::cerr << "new key is smaller than current key" << std::endl;
    A[i] = key;
    while (i>0 && A[parent_idx(i) < A[i]])
    {
        myUtils.swap(A[i], A[parent_idx(i)]);
        i = parent_idx(i);
    }
}

template <class T>
void MaxHeap<T>::heap_insert(std::vector<T> &A, T key)
{
    heap_size ++;
    A[heap_size-1] = std::numeric_limits<T>::min();
    heap_increaseKey(A, heap_size, key);
}


