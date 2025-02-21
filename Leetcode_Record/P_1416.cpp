#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        int n = s.size();
        int dig = 0, mod = 1e9 + 7;
        for (int tmp = k; tmp; tmp /= 10, dig++)
            ;
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] - '0' > k)
                return 0;
            long long tmp = 0, p = 1;
            for (int d = 0; d < dig && i - d >= 0 && tmp <= k; d++, p *= 10)
            {
                tmp += p * (s[i - d] - '0');
                if (s[i - d] != '0' && tmp > 0 && tmp <= k)
                {
                    dp[i] += (i - d > 0) ? dp[i - d - 1] : 1;
                    dp[i] %= mod;
                }
            }
        }
        return dp[n - 1];
    }
};