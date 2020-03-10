#include <iostream>
#include <vector>
#include "binSearch.h"

using namespace std;


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


