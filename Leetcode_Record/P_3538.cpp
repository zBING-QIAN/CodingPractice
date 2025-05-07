#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTravelTime(int l, int n, int k, vector<int> &position, vector<int> &time)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(k + 1, 1e9))); // dp[index][k][lastt]
        vector<vector<int>> sum(n, vector<int>(k + 1, 0));                                      // sum[index][lastt]
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum[i][0] = time[i];
            for (int t = 1; t <= k && t <= i; t++)
            {
                sum[i][t] = sum[i][t - 1] + time[i - t];
            }
        }
        for (int t = 1; t < n; t++)
        {
            dp[t][0][0] = dp[t - 1][0][0] + time[t - 1] * (position[t] - position[t - 1]);
            for (int K = 1; K <= k; K++)
            {
                for (int i = 0; i <= K && t - i > 0; i++)
                {
                    for (int j = 0; j <= k - i; j++)
                    {
                        int tmp = sum[t - i - 1][j] * (position[t] - position[t - i - 1]);
                        if (dp[t][K][i] > dp[t - i - 1][K - i][j] + tmp)
                            dp[t][K][i] = dp[t - i - 1][K - i][j] + tmp;
                    }
                }
            }
        }
        int res = 1e9;
        for (int i = 0; i <= k; i++)
        {
            res = min(res, dp[n - 1][k][i]);
        }
        return res;
    }
};