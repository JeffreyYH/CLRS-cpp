#include <iostream>
#include <vector>
#include <climits>
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

 
};


template <class T>
int Sorting<T>::partition(vector<T> &A, int p, int r)
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
void Sorting<T>::quickSort (vector<T> &A, int p, int r)
{
    if(p < r)
    {
        int q;
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}







