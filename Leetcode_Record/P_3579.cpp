#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dist(string &a, string &b, int l, int r)
    {
        map<array<char, 2>, int> cnt;
        int res = 0;
        for (int i = l; i <= r; i++)
        {
            if (a[i] != b[i])
            {
                if (cnt[{b[i], a[i]}])
                    cnt[{b[i], a[i]}]--;
                else
                {
                    cnt[{a[i], b[i]}]++;
                    res++;
                }
            }
        }
        int res_r = 1;
        cnt.clear();
        for (int i = l, j = r; i <= r; i++, j--)
        {
            if (a[i] != b[j])
            {
                if (cnt[{b[j], a[i]}])
                    cnt[{b[j], a[i]}]--;
                else
                {
                    cnt[{a[i], b[j]}]++;
                    res_r++;
                }
            }
        }
        return min(res_r, res);
    }
    int minOperations(string word1, string word2)
    {
        int n = word1.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1 - (word1[i] == word2[i]);
        for (int t = 1; t < n; t++)
        {
            for (int i = 0; i + t < n; i++)
            {
                dp[i][i + t] = dist(word1, word2, i, i + t);
                // cout<<i<<" "<<i+t<<" "<<dp[i][i+t]<<endl;
                for (int j = 0; j < t; j++)
                {
                    dp[i][i + t] = min(dp[i][i + t], dp[i][i + j] + dp[i + j + 1][i + t]);
                }
            }
        }
        // for(int i=0;i<n;i++)for(int j=i;j<n;j++)cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;

        return dp[0][n - 1];
    }
};