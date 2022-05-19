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
    float memorized_curRod(std::vector<float>, int);
    float memorized_curRod_aux(std::vector<float>, int, std::vector<float>);
    float bottomUp_cutRod(std::vector<float>, int);
    float extended_bottom_up_cutRod(std::vector<float>, int);
    void print_cutRod(std::vector<float>, int);

};

float RodCutting::recursive_cutRod(std::vector<float> p, int n)
{
    if (n==0)
        return 0;
    float q = -FLT_MAX;
    for (size_t i = 1; i<=n; ++i)
    {
        q = std::max(q, p[i] + recursive_cutRod(p, n-i));
    }
    return q;
}

float RodCutting::memorized_curRod(std::vector<float> p, int n)
{
    std::vector<float> r (p.size(), -FLT_MAX);
    return memorized_curRod_aux(p, n, r);
}

float RodCutting::memorized_curRod_aux(std::vector<float> p, int n, std::vector<float> r)
{
    float q = 0;
    if (r[n] >= 0)
        return r[n];
    if (n==0)
        q = 0;
    else   
        q = -FLT_MAX;
        for (int i=1; i<=n; i++)
        {
            q = std::max(q, p[i]+memorized_curRod_aux(p, n-i,r));
        }
    r[n] = q;
    return q;
}


int main()
{
    std::shared_ptr<RodCutting> RC;
    // first element is just a place holder
    std::vector<float> price {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    // test from 1 to 10
    for (int n = 1; n<=10; n++)
    {
        cout << "Recursive method:" << endl;
        cout << RC->recursive_cutRod(price, n) << endl;
        cout << "Memorized DP method:" << endl;
        cout << RC->memorized_curRod(price, n) << endl;
    }
}


