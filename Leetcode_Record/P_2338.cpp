#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    long long Cnxm(long long n, int m)
    {
        // cout<<n<<" "<<m<<" ";
        long long upper = 1, lower = 1;
        for (int i = 1; i <= m; i++)
        {
            upper = (upper * (m + n - i)) % mod;
            lower = (lower * i) % mod;
        }
        // cout<<upper<<" " <<lower<<" ";
        upper = (upper * pow(lower, mod - 2)) % mod;

        // cout<<upper<<endl;
        return upper;
    }
    int pow(long long a, int p)
    {
        long long res = 1;
        while (p)
        {
            if (p & 1)
                res *= a;
            a *= a;
            res %= mod;
            a %= mod;
            p >>= 1;
        }
        return res;
    }

    int idealArrays(int n, int maxValue)
    {
        vector<int> factor(maxValue + 1);
        for (int i = 0; i <= maxValue; i++)
            factor[i] = i;
        for (int i = 2; i * i <= maxValue; i++)
        {
            if (factor[i] == i)
            {
                for (int j = i * i; j <= maxValue; j += i)
                {
                    factor[j] = i;
                }
            }
        }
        long long res = 1;
        vector<long long> dp(maxValue + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= maxValue; i++)
        {
            int times = 0, tmp = i;
            while (tmp % factor[i] == 0)
            {
                times++;
                tmp /= factor[i];
            }
            // cout<<i<<" "<<dp[tmp]<<" ";
            long long cnt = (dp[tmp] * Cnxm(n, times)) % mod;
            dp[i] = cnt;
            res = (res + cnt) % mod;
        }
        return res;
    }
};