#include <iostream>
using namespace std;

const int LEN = 6;

int main()
{ 		

	int A[LEN] = {1, 2, 3, 4, 5, 6};
	int *copyA = A;

	char charA[LEN] = {'a', 'b', 'd', 'c', 'e', 'f'};
	char * copyCharA = charA;

	// print copy A 
	cout << copyA << endl;

	// The first element of A
	cout << *A << endl;

	// print copy A 
	cout << copyCharA << endl;

	// The first element of A
	cout << *charA << endl;

	return 0;
}
