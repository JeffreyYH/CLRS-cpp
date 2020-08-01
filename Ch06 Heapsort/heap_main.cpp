#include "heap.hpp"
using namespace std;

int main()
{
    vector<int> A = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    cout << "Before heap sort" << endl;
    for (auto a:A)
        cout << a << ' ';
    cout << endl;

    vector<int> A_sorted = A;
    MaxHeap<int> maxHeap;
    cout << "After heap sort" << endl;
    maxHeap.heapSort(A_sorted);
    for (auto a:A_sorted)
        cout << a << ' ';
    cout << endl;

    auto extractedMax = maxHeap.heap_extractMax(A);
    cout << "max element in heap:"<< endl;
    cout << extractedMax << endl;

    return 0;
}