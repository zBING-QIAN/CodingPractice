#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<array<int, 2>> taps(n + 1);
        for (int i = 0; i <= n; i++)
        {
            taps[i] = {max(0, i - ranges[i]), min(n, i + ranges[i])};
        }
        sort(taps.begin(), taps.end());
        int base = 0;
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            int prev = dp[taps[i][0]];
            for (int j = taps[i][0] + 1; j <= taps[i][1]; j++)
            {
                if (prev > dp[j])
                    prev = dp[j];
            }
            dp[taps[i][1]] = min(prev + 1, dp[taps[i][1]]);
        }
        if (dp[n] < 1e9)
            return dp[n];
        return -1;
    }
};