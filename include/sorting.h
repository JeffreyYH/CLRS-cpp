#include <iostream>
#include <vector>
using namespace std;

class Sorting
{
private:
    const int MAX = 10000;

public:
    void mySwap(int &x, int &y);

    vector<int> bubbleSort(vector<int> A);

    // sort a list in ASCENDING order with insertion sort
    vector<int> insertionSort(vector<int> A);

    // merge sort
    void merge (vector<int> &A, int p, int q, int r);

    // arguments can also be written as (int *A, int p, int r)  
    void mergeSort (vector<int> &A, int p, int r);

    // quick sort
    int partition(int A[], int p, int r);

    void quickSort (int A[], int p, int r);
};



