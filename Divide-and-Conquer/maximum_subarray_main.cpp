#include "maximum_subarray.hpp"

int main()
{
    std::vector<float> prices {10, 11, 7, 10, 6};
    prices = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    std::shared_ptr<MaximumSubarray> maxSubArr;
    cout << "Max profit by brute force is " << maxSubArr->bruteForce(prices) << endl;

    std::vector<float> A (int(prices.size()), 0.0);
    for (size_t i=1; i<prices.size(); i++)
        A[i] = prices[i] - prices[i-1];
    
    auto results = maxSubArr->find_max_subarray(A, 0, A.size()-1);
    cout << "Max profit by divide and conquer is " << std::get<2>(results) << endl;
}