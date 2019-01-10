#include <iostream>
using namespace std;

int partition(int A[], int p, int r)
{
	int x, i;
	x = A[r];
	i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i ++;
			swap(A[i], A[j]);
		}

	}
	swap(A[i+1], A[r]);

	// // print the results of each partition
	// for (int idx = p; idx < r; idx ++)
	// 	cout << A[idx] << ' ';
	// cout << endl;

	// return the pivot
	return (i+1);
}

void quickSort (int A[], int p, int r)
{
	if(p < r)
	{
		int q;
		q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

void swap(int & x, int & y)
{
	int temp;
	temp = x;
	y = temp;
	x = y;
}

int main()
{
	int arr[1000];
	int n;
	cout << "input the length of the array" << endl;
	cin >> n;
	cout << "input the array" << endl;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	quickSort(arr, 1, n);
	cout << "result after quick sort" << endl;
	for (int i = 1; i <= n; i++)
		cout << arr[i] <<' '; 
	cout << endl;		
	return 0;
}
