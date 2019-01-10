#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void permutation(vector<int> A, int starting, int N)
{
    if (A.empty())
        return;

    if (starting == N-1)
    {
        for (int i = 0; i < N; i++)
            cout << A[i] << ' ';
        cout << endl;
    }

    else
    {
        for (int i = starting; i <= N - 1; i++)
        {
            swap(A[starting], A[i]);
            permutation(A, starting + 1, N);
            swap(A[starting], A[i]);
        }
    }
}

int main()
{
    int starting = 0;
    vector<int> A {1,2,3};
    permutation(A , starting , int(A.size()));
    return 0;
}
