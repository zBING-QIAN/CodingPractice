#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long cnt(int n)
    {
        n++;
        long long log4n = 1;
        long long out = 0;
        for (long long tmp = 1; tmp < n; tmp <<= 2, log4n++)
        {
            long long upper = (n > tmp << 2) ? tmp << 2 : n;
            out += log4n * (upper - tmp);
        }
        return out;
    }

    long long minOperations(vector<vector<int>> &queries)
    {
        long long ans = 0;
        for (auto &q : queries)
        {
            ans += (cnt(q[1]) - cnt(q[0] - 1) + 1) / 2;
        }
        return ans;
    }
};