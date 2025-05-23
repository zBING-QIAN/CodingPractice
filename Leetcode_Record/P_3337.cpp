#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    vector<array<long long, 26>> muldp(vector<array<long long, 26>> &a, vector<array<long long, 26>> &b)
    {
        vector<array<long long, 26>> res(26);
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    res[i][k] = (res[i][k] + a[i][j] * b[j][k]) % mod;
                }
            }
        }
        return res;
    }
    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        long long ans = 0;
        int n = s.size();
        vector<array<long long, 26>> dp(26, array<long long, 26>()), pow_dp(26, array<long long, 26>());
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= nums[i]; j++)
                pow_dp[i][(i + j) % 26] = 1;
            dp[i][i] = 1;
        }
        while (t)
        {
            if (t & 1)
            {
                dp = muldp(dp, pow_dp);
            }
            pow_dp = muldp(pow_dp, pow_dp);
            t >>= 1;
        }
        vector<long long> cnt(26, 0);
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
                cnt[i] += dp[i][j];
            cnt[i] %= mod;
        }
        for (int i = 0; i < n; i++)
        {
            ans += (cnt[s[i] - 'a']);
        }
        return ans % mod;
    }
};