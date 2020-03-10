#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;

void Sorting::mySwap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

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
                mySwap(A[j], A[j+1]);
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
    int n1 = q-p+1;
    int n2 = r-q;
    
    // left and right parts L and R
    int L[100], R[100];
    for (int i = 1; i <= n1; i++)
        L[i] = A[i + p - 1];
    for (int i = 1; i <= n2; i++)
        R[i] = A[i + q];

    // put a very large value in the end of L and R
    L[n1 + 1] = MAX;
    R[n2 + 1] = MAX;

    //compare L and R and pick the smaller one to put in A
    int i = 1, j = 1;
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

// arguments can also be written as (int *A, int p, int r)  
void Sorting::mergeSort (vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort (A, p, q);
        mergeSort (A, q+1, r);
        merge (A, p, q, r);
    }
}

// quick sort
int Sorting::partition(int A[], int p, int r)
{
    int x, i;
    x = A[r];
    i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i ++;
            mySwap(A[i], A[j]);
        }
    }
    mySwap(A[i+1], A[r]);

    // // print the results of each partition
    // for (int idx = p; idx < r; idx ++)
    // 	cout << A[idx] << ' ';
    // cout << endl;

    // return the pivot
    return (i+1);
}

void Sorting::quickSort (int A[], int p, int r)
{
    if(p < r)
    {
        int q;
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}



