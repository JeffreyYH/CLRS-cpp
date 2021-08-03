#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include "myUtils.hpp"

using namespace std;

template <class T>
class QuickSort
{
private:
    MyUtils myUtils;

public:

    // quick sort: divide and conquer
    int partition(vector<T> &A, int p, int r);
    void quickSort (vector<T> &A, int p, int r);

    // randomized version of quicksort
    int randomized_partition(vector<T> &A, int p, int r);
    void randomized_quicksort(vector<T> &A, int p, int r);
};


template <class T>
int QuickSort<T>::partition(vector<T> &A, int p, int r)
{
    int x, i;
    x = A[r];
    i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i ++;
            myUtils.swap(A[i], A[j]);
        }
    }
    myUtils.swap(A[i+1], A[r]);

    // // print the results of each partition
    // for (int idx = p; idx < r; idx ++)
    // 	cout << A[idx] << ' ';
    // cout << endl;

    // return the pivot
    return (i+1);
}

template <class T>
void QuickSort<T>::quickSort (vector<T> &A, int p, int r)
{
    if(p < r)
    {
        int q;
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}


//================ 7.3 A randomized version of quicksort ================//
template <class T>
int QuickSort<T>::randomized_partition(vector<T> &A, int p, int r)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(p, r); // define the range
    int i = distr(gen);
    // cout << i << endl;
    myUtils.swap(A[r], A[i]);
    return partition(A, p, r);
}

template <class T>
void QuickSort<T>::randomized_quicksort(vector<T> &A, int p, int r)
{
    if (p < r)
    {
        int q = randomized_partition(A, p, r);
        randomized_quicksort(A, p, q-1);
        randomized_quicksort(A, q+1, r);
    }

}