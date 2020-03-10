#include <iostream>
#include <vector>
using namespace std;

class Sorting
{
public:
    void mySwap(int &x, int &y);

    vector<int> bubbleSort(vector<int> A);

    // sort a list in ASCENDING order with insertion sort
    vector<int> insertionSort(vector<int> A);

    // merge sort: divide and conquer
    void merge (vector<int> &A, int p, int q, int r);
    void mergeSort (vector<int> &A, int p, int r);

    // quick sort: divide and conquer
    int partition(vector<int> &A, int p, int r);
    void quickSort (vector<int> &A, int p, int r);

    // TODO: heap sort

    // TODO: linear time sorting
};



