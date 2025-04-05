#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        vector<long long> tmp(n - 1, 0);
        for (int i = 1; i < n; i++)
        {
            tmp[i - 1] = weights[i] + weights[i - 1];
        }
        sort(tmp.begin(), tmp.end());
        long long big = 0, small = 0;
        for (int i = 0; i < k - 1; i++)
        {
            big += tmp[n - 2 - i];
            small += tmp[i];
        }
        return big - small;
    }
};