#include <iostream>
using namespace std;

const int MAX = 10000;

void merge (int *A, int p, int q, int r)
{
	// length of left and right parts
	int n1 = q-p+1;
	int n2 = r-q;
	
	// left and right parts L and R
	int L[100], R[100];
	for (int i = 1; i <= n1; i++)
		L[i] = A[i + p - 1];
	for (int i = 1; i <= n2; i++)
		R[i] = A[i + q];

	// put a very large value in the end of L and R
	L[n1 + 1] = MAX;
	R[n2 + 1] = MAX;

	//compare L and R and pick the smaller one to put in A
	int i = 1, j = 1;
	for (int k = p; k <= r; k++)
	{
		if ( L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}

// arguments can also be written as (int *A, int p, int r)  
void mergeSort (int *A, int p, int r)  
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergeSort (A, p, q);
		mergeSort (A, q+1, r);
		merge (A, p, q, r);
	}
}

int main()
{
	int arr[100];
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		mergeSort(arr, 1, n);
		for (int i = 1; i <= n; i++)
			cout << arr[i] <<' '; 
		cout << endl;
	}		
	return 0;
}

