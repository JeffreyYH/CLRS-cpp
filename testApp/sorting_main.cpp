#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;

int main()
{
    vector<int> A = {0, 9, 3, 10, -1, 6 ,4, 2};
    int n = A.size();

    Sorting sortObj;

    vector<int> sortedA = sortObj.bubbleSort(A);
    for(int sa:sortedA)
        cout << sa << " ";
    cout << endl;

    sortedA = sortObj.insertionSort(A);
    for(int i=0; i<sortedA.size(); i++)
        cout<<sortedA[i]<<' ';

    sortObj.quickSort(A, 1, n);
	cout << "result after quick sort" << endl;
	for (int i = 1; i <= n; i++)
		cout << A[i] <<' '; 
	cout << endl;

    sortObj.mergeSort(A, 1, n);
    for (int i = 1; i <= n; i++)
        cout << A[i] <<' ';

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


