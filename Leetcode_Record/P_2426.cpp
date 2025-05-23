#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        long long ans = 0;
        int n = nums1.size();
        vector<int> dif(n, 0);
        for (int i = 0; i < n; i++)
        {
            dif[i] = nums2[i] - nums1[i];
        }
        int maxn = 5e4 + 5;
        vector<int> dp(maxn << 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int tmp = min((maxn << 1) - 1, dif[i] + diff + maxn);
            if (tmp < 0)
                tmp = 0;
            for (; tmp; tmp -= (tmp & -tmp))
            {
                ans += dp[tmp];
            }
            for (int tmp1 = dif[i] + maxn; tmp1 < (maxn << 1); tmp1 += (tmp1 & -tmp1))
            {
                dp[tmp1]++;
            }
        }

        return ans;
    }
};