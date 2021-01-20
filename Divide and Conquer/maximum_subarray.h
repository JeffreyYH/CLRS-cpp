#include "../utils/commonInclude.h"

class MaximumSubarray
{
public:
    static void bruteForce(std::vector<float> prices);
    static void maximum_subarray();
};

void MaximumSubarray::bruteForce(std::vector<float> price)
{
    float maxProfit = -__FLT_MAX__;
    for (int i=0; i<price.size(); i++)
    {
        for (int j=i+1; j<price.size(); j++)
        {
            float currProfit = price[j] - price[i];
            maxProfit = std::max(maxProfit, currProfit);
        }
    }
    cout << "Max profit is " << maxProfit << endl;
}