#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    long long fastpow(long long v, int p)
    {
        long long res = 1;
        while (p)
        {
            if (p & 1)
                res = (res * v) % mod;
            v = (v * v) % mod;
            p >>= 1;
        }
        return res;
    }
    long long inv(int v)
    {
        return fastpow(v, mod - 2);
    }
    int countBalancedPermutations(string num)
    {
        vector<int> cnt(10, 0);
        int sum = 0, n = num.size();

        vector<vector<vector<int>>> dp(10, vector<vector<int>>((n >> 1) + 1, vector<int>(1000, 0)));
        for (auto t : num)
        {
            cnt[t - '0']++;
            sum += t - '0';
        }
        if (sum & 1)
            return 0;
        sum >>= 1;
        dp[0][0][0] = 1;
        vector<long long> fac(n + 1, 1), invfac(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            fac[i] = (fac[i - 1] * i) % mod;
            invfac[i] = inv(fac[i]);
        }
        for (int i = 0; i <= cnt[0] && i <= (n / 2); i++)
        {
            dp[0][i][0] = (invfac[i] * invfac[cnt[0] - i]) % mod;
            //    cout<<i<<" "<<cnt[0]-i<<" "<<dp[0][i][0]<<endl;
        }
        for (int i = 1; i < 10; i++)
        {
            for (int m = 0; m <= cnt[i]; m++)
            {
                for (int pm = 0; pm + m <= n / 2; pm++)
                {
                    int upper = (pm + m) * (i - 1);
                    for (int s = 0; s <= upper; s++)
                    {
                        // cout<<i<<" "<<m<<" "<<pm<<" "<<s<<" "<<n<<" "<<upper<<" "<<(((invfac[m]*invfac[cnt[i]-m])%mod)*dp[i-1][pm][s])%mod<<endl;
                        dp[i][m + pm][s + m * i] = (dp[i][m + pm][s + m * i] + ((invfac[m] * invfac[cnt[i] - m]) % mod) * dp[i - 1][pm][s]) % mod;
                    }
                }
            }
        }

        return (((fac[n >> 1] * fac[n - (n >> 1)]) % mod) * dp[9][n / 2][sum]) % mod;
    }
};