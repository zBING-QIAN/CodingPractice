#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minimumCost(vector<int> &nums, vector<int> &cost, int k)
    {
        long long ans = 0;
        // long long ctotal=0,ntotal=0;
        int n = nums.size();
        // for(int i=0;i<n;i++){ctotal+=cost[i];ntotal+=nums[i];}
        vector<long long> ndp(n, 0), dp(n + 1, 0);
        // dp.back()=ctotal*(ntotal+k);
        ndp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            ndp[i] = ndp[i - 1] + nums[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            long long csum = 0, best = -1;
            for (int j = i; j < n; j++)
            {
                csum += cost[j];
                if (best == -1 || best > ndp[j] * csum + dp[j + 1])
                    best = ndp[j] * csum + dp[j + 1];
            }
            dp[i] = best + 1ll * csum * k;
        }

        return dp[0];
    }
};