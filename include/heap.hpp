// heap.hpp
// if template class is used, then it's NOT possible to separate
// class declaration (in h) and class implementation(in cpp)
// thus we choose to use hpp file here

#include <utility>
#include <iostream>
#include <vector>

template<class T>
class MaxHeap
{
private:
    std::vector<T> A;

public:
    explicit MaxHeap(std::vector<T> A_para)
    {
        A = A_para;
    }

    void maxHeapify();
    void buildMaxHeap();
    void heapSort();

    // the following implement functions max-priority queue
    void heap_maximum();
    void heap_extractMax();
    void heap_insert();
    void heap_increaseKey();

    void printHeap();

};

//================= member function implementation ==================//
template <class T>
void MaxHeap<T>::printHeap()
{
    for (auto a:A)
        std::cout << a << ' ';
    std::cout << std::endl;
}



//template <typename T>
//void MaxHeap::maxHeapify()
//{
//
//}

//void MaxHeap::buildMaxHeap();
//void MaxHeap::heapSort();

//void MaxHeap::heap_maximum();
//void MaxHeap::heap_extractMax();
//void MaxHeap::heap_insert();
//void MaxHeap::heap_increaseKey();


