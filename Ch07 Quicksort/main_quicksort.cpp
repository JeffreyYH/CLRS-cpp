#include <iostream>
#include "quicksort.hpp"
using namespace std;

int main()
{
    vector<int> A = {0, 9, 3, 10, -1, 6, 4, 2};
    int N = A.size();
    cout << "Before quick sort: " << endl;
    for(auto a:A)
        cout << a << ' ';
    cout << endl;
    QuickSort<int> quicksortObj;
    vector<int> A_quickSort = A;
    quicksortObj.quickSort(A_quickSort, 0, N-1);
    cout << "After quick sort: " << endl;
    for (auto a:A_quickSort)
        cout << a <<' ';
    cout << endl;
}
