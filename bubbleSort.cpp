#include <iostream>
#include <vector>
using namespace std;

void mySwap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

vector<int> bubbleSort(vector<int> A)
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

int main()
{
    vector<int> A = {0, 9, 3, 10, -1, 6 ,4, 2};
    vector<int> sortedA = bubbleSort(A);
    for(int sa:sortedA)
        cout << sa << " ";
    cout << endl;

    return 0;
}


