#include <iostream>
#include <vector>
using namespace std;

// sort a list in ASCENDING order with insertion sort
vector<int> insertionSort(vector<int> A)
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

int main()
{
    vector<int> A = {9, 2, 3, 1, 7, 5, 0, 19, 2, 10};
    vector<int> sortedA = insertionSort(A);
    for(int i=0; i<sortedA.size(); i++)
        cout<<sortedA[i]<<' ';

    // if you want to input A, uncomment the following code:
    /* vector<int> A;
    int n;  // number of element
    while (cin>>n && n!=0)
    {
        for (int i=0; i<n; i++)
        {
            int inelement;
            cin >> inelement;
            A.push_back(inelement);
        }
        vector<int> sortedA = insertionSort(A);
        for(int i=0; i<sortedA.size(); i++)
            cout<<sortedA[i]<<' ';
    } */
    return 0;
}

