#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    vector<long long> merge(vector<long long> &a, vector<long long> &b)
    {
        vector<long long> res(4, 0);

        res[0] = a[0] + max(b[0], b[2]);
        res[0] = max(res[0], a[1] + b[0]);

        res[1] = a[0] + max(b[1], b[3]);
        res[1] = max(res[1], a[1] + b[1]);
        // res[1] = max(res[1],res[0]);

        res[2] = a[2] + max(b[0], b[2]);
        res[2] = max(res[2], a[3] + b[0]);
        // res[2] = max(res[2],res[0]);

        res[3] = a[2] + max(b[1], b[3]);
        res[3] = max(res[3], a[3] + b[1]);
        // res[3] = max(res[3],max(res[2],res[1]));
        return res;
    }
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), ts = 1;
        for (; ts < n; ts <<= 1)
            ;
        vector<vector<long long>> seg(ts << 1, vector<long long>(4, 0));
        for (int i = 0; i < n; i++)
        {
            seg[ts + i][0] = 0;
            seg[ts + i][1] = 0;
            seg[ts + i][2] = 0;
            seg[ts + i][3] = nums[i];
        }
        for (int i = ts - 1; i; i--)
        {
            seg[i] = merge(seg[i << 1], seg[(i << 1) + 1]);
        }
        long long res = 0;
        for (auto &q : queries)
        {
            int cur = ts + q[0];
            seg[cur][3] = q[1];
            cur >>= 1;
            while (cur)
            {
                seg[cur] = merge(seg[cur << 1], seg[(cur << 1) + 1]);
                cur >>= 1;
            }
            res += max(max(seg[1][0], seg[1][1]), max(seg[1][2], seg[1][3]));
            res %= mod;
        }
        return res;
    }
};