#include <iostream>
#include <vector>
using namespace std;

class BinSearch
{
public:
    int binSearch_recursive (vector<int> &A, int low, int high, int element)
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

    int binSearch_iterative(vector<int> &A, int element)
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
};


int main ()
{
    BinSearch binsearchObj;
    // given a SORTED array
    vector<int> testA = {1,8,9,10,18,20,49};
    int element = 8;
    int low = 0, high = testA.size()-1;
    // results of bin search with recursive approach	
    cout << binsearchObj.binSearch_recursive(testA, low, high, element) << endl;
    // results of bin search with iterative approach
    cout << binsearchObj.binSearch_iterative(testA, element)<< endl;
	return 0;
}


