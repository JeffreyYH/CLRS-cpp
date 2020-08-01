#include <iostream>
#include <vector>
#include "sorting.hpp"

using namespace std;

int main()
{
    vector<int> A = {0, 9, 3, 10, -1, 6, 4, 2};
    int n = A.size();

    Sorting<int> sortObj;

    vector<int> A_bubbleSort = sortObj.bubbleSort(A);
    cout << "result after bubble sort:" << endl;
    for(int a_bs: A_bubbleSort)
        cout << a_bs << " ";
    cout << endl;

    vector<int> A_insertionSort = sortObj.insertionSort(A);
    cout << "result after insertion sort:" << endl;
    for(int a_is: A_insertionSort)
        cout << a_is << ' ';
    cout << endl;

    vector<int> A_mergeSort = A;
    // from the first element, 0th to the last element, (n-1)th
    sortObj.mergeSort(A_mergeSort, 0, n-1);
    cout << "result after merge sort:" << endl;
    for (int i = 0; i < n; i++)
        cout << A_mergeSort[i] <<' ';
    cout << endl;

    /*// if you want to input A via terminal, uncomment the following code:
    vector<int> A;
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
        cout << endl;
    }*/
    
    return 0;
}


