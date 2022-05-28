#include "../utils/commonInclude.h"

class MaximumSubarray
{
public:
    static float bruteForce(std::vector<float> prices);
    static std::tuple<int, int, float> find_max_crossing_subarray
            (std::vector<float> A, int low, int mid, int high);
    static std::tuple<int, int, float> find_max_subarray
            (std::vector<float> A, int low, int high);
};

float MaximumSubarray::bruteForce(std::vector<float> price)
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
    return maxProfit;
}

std::tuple<int, int, float> 
MaximumSubarray::find_max_crossing_subarray(std::vector<float> A, int low, int mid, int high)
{
    float left_sum = -__FLT_MAX__;
    float sum = 0;
    int max_left = 0;
    for (int i=mid; i>=low; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum  = sum;
            max_left = i;
        }
    }
    float right_sum = -__FLT_MAX__;
    sum = 0;
    int max_right = 0;
    for (int j=mid+1; j<=high; j++)
    {
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right= j;
        }
    }
    auto results = std::make_tuple(max_left, max_right, left_sum+right_sum);
    return results;
}

std::tuple<int, int, float> 
MaximumSubarray::find_max_subarray(std::vector<float> A, int low, int high)
{
    if (high == low)
        return std::make_tuple(low, high, A[low]);
    else
    {
        float mid = (low+high)/2;
        auto left_results = find_max_subarray(A, low, mid);
        int left_low = std::get<0>(left_results); 
        int left_high = std::get<1>(left_results); 
        float left_sum = std::get<2>(left_results); 

        auto right_results = find_max_subarray(A, mid+1, high);
        int right_low = std::get<0>(right_results); 
        int right_high = std::get<1>(right_results); 
        float right_sum = std::get<2>(right_results); 

        auto cross_results = find_max_crossing_subarray(A, low, mid, high);
        int cross_low = std::get<0>(cross_results); 
        int cross_high = std::get<1>(cross_results); 
        float cross_sum = std::get<2>(cross_results); 

        if (left_sum >= right_sum && left_sum >= cross_sum)
            return std::make_tuple(left_low, left_high, left_sum);
        if (right_sum >= left_sum && right_sum >= cross_sum)
            return std::make_tuple(right_low, right_high, right_sum);
        else
            return std::make_tuple(cross_low, cross_high, cross_sum);
    }

}