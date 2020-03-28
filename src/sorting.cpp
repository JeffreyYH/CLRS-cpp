#include <iostream>
#include <vector>
#include <climits>
#include "sorting.h"

using namespace std;

vector<int> Sorting::bubbleSort(vector<int> A)
{
    // compare current element with the next element,
    // move the larger one right side(ascending order),
    // then the right most one is the biggest in current sub-array
    for (int i=0; i<A.size(); i++)
    {
        // compare two adjacent elements in this sub-array
        for(int j=0; j<A.size()-i-1; j++)
        {
            if(A[j] > A[j+1])
                myUtils.swap(A[j], A[j+1]);
                // you can also use std::swap()
                // std::swap(A[j], A[j+1]);
        }
    }
    return A;
}

// sort a list in ASCENDING order with insertion sort
vector<int> Sorting::insertionSort(vector<int> A)
{
    int key = 0;
    // start with the second element of A
    for(int i=1; i<A.size(); i++)
    {
        key = A[i];
        int j = i - 1;
        /* Insert the key to a ALREADY SORTED list in a proper position.
        if A[j] is larger than key, that means key should put in front of A[j],
        so move A[j] to A[j+1] and choose the next element in A (which is A[j--]) to compare with key.
        if A[j] is smaller than key, then key should be put behind A[j],
        and all the element in front of A[j] is smaller than A[j]. Loop terminated.
        If j reaches the head of the list, loop terminated. */
        while(A[j] > key && j>=0)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    return A;
}


void Sorting::merge (vector<int> &A, int p, int q, int r)
{
    // length of left and right parts
    int Nl = q-p+1;
    int Nr = r-q;
    
    // left and right parts L and R
    vector<int> L, R;
    for (int i = p; i <= q; i++)
        L.push_back(A[i]);
    for (int i = q+1; i <= r; i++)
        R.push_back(A[i]);

    // put a very large value in the end of L and R
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    //compare L and R and pick the smaller one to put in A
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if ( L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

// argument A can also be written as *A or A[] if using array
void Sorting::mergeSort (vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        // deal the first half part and then the second half part
        mergeSort (A, p, q);
        mergeSort (A, q+1, r);
        merge (A, p, q, r);
    }
}

// quick sort
int Sorting::partition(vector<int> &A, int p, int r)
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

void Sorting::quickSort (vector<int> &A, int p, int r)
{
    if(p < r)
    {
        int q;
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}



