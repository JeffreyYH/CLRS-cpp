#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm> 

using std::cout;
using std::endl;

class RodCutting
{
    public:
    float cut_rod(std::vector<float>, int);
};

float RodCutting::cut_rod(std::vector<float> p, int n)
{
    if (n==0)
        return 0;
    float q = -FLT_MAX;
    for (size_t i = 0; i<n; ++i)
    {
        q = std::max(q, p[i] + cut_rod(p, n-1));
    }
     return q;
}


