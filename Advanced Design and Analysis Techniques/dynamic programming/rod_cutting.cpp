#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm> 

using std::cout;
using std::endl;

class RodCutting
{
    public:
    float recursive_cutRod(std::vector<float>, int);
    float bottomUp_cutRod(std::vector<float>, int);
    float memorized_curRod(std::vector<float>, int);
    float memorized_curRod_aux(std::vector<float>, int, std::vector<float>);
    float extended_bottom_up_cutRod(std::vector<float>, int);
    void print_cutRod(std::vector<float>, int);

};

float RodCutting::recursive_cutRod(std::vector<float> p, int n)
{
    if (n==0)
        return 0;
    float q = -FLT_MAX;
    for (size_t i = 0; i<n; ++i)
    {
        q = std::max(q, p[i] + recursive_cutRod(p, n-1));
    }
     return q;
}

int main()
{
    std::shared_ptr<RodCutting> RC;
}


