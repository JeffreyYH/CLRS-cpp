#include <iostream>
#include <string>
using namespace std;

int low, high;
int n, element;
int A [1000];

int BinSearch (int A[], int low, int high, int element)
{
	if (low <= high)
	{
		// int mid = (low + high) / 2;
		int mid = low + (high - low) / 2;  // a better way for mid
		if ( element > A [mid])
			BinSearch(A, mid + 1, high, element);
		else if (element < A [mid])
			BinSearch(A, low, mid - 1, element);
		else
			return mid;
	}
	else
		return -1;
}

int main ()
{
	cout << "enter array length " << endl;
	cin >> n;
	cout << "input array " << endl;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cout << "enter element to be found " << endl;
	cin >> element;
	low = 0;
	high = n - 1;
	if (BinSearch(A, low, high, element) == -1)
		cout << "error" << endl;
	else
		cout << BinSearch(A, low, high, element) << endl;

	return 0;
}


