#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Search
{
public:
    int binSearch_recursive (vector<int> &A, int low, int high, int element);
    int binSearch_iterative(vector<int> &A, int element);
};

template <class T>
int Search<T>::binSearch_recursive (vector<int> &A, int low, int high, int element)
{
    // int mid = (low + high) / 2;
    int mid = low + (high - low) / 2;  // a better way for mid
    if ( element > A [mid])
        binSearch_recursive(A, mid + 1, high, element);
    else if (element < A [mid])
        binSearch_recursive(A, low, mid - 1, element);
    else
        return mid;
}

template <class T>
int Search<T>::binSearch_iterative(vector<int> &A, int element)
{
    int low = 0, high = A.size() - 1;
    while (low < high)
    {
        int mid = low + (high-low)/2;
        if (element > A[mid])
            low = mid + 1;
        else if (element < A[mid])
            high = mid - 1;
        else
            return mid;
    }
}





