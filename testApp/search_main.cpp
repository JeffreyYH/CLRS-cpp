#include <iostream>
#include <vector>
#include "search.hpp"

using namespace std;

int main ()
{
    Search searchObj;
    // given a SORTED array
    vector<int> testA = {1,8,9,10,18,20,49};
    int element = 18;
    int low = 0, high = testA.size()-1;
    // results of bin search with recursive approach
    cout << searchObj.binSearch_recursive(testA, low, high, element) << endl;
    // results of bin search with iterative approach
    cout << searchObj.binSearch_iterative(testA, element)<< endl;
	return 0;
}


