#include "heap.hpp"
using namespace std;

int main()
{
    vector<int> A = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    MaxHeap<int> maxHeap;
    maxHeap.heapSort(A);
    for (auto a:A)
        cout << a << ' ';
    cout << endl;

    return 0;
}




