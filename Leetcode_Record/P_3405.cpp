#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int pow(long long v, int n)
    {
        long long res = 1;
        while (n)
        {
            if (n & 1)
            {
                res *= v;
                res %= mod;
            }
            v = (v * v) % mod;
            n >>= 1;
        }
        return res;
    }
    int inv(long long v)
    {
        return pow(v, mod - 2);
    }
    int bar(int v)
    {
        long long res = 1;
        for (int i = 1; i <= v; i++)
        {
            res *= i;
            res %= mod;
        }
        return res;
    }
    int countGoodArrays(int n, int m, int k)
    {
        long long pow_m = m - 1, mm = m;
        n--;
        int ntmp = n - k;
        while (ntmp)
        {
            if (ntmp & 1)
            {
                mm = (mm * pow_m) % mod;
            }
            pow_m = (pow_m * pow_m) % mod;
            ntmp >>= 1;
        }
        long long cnk = ((1ll * bar(n) * inv(bar(k))) % mod * inv(bar(n - k))) % mod;
        return (cnk * mm) % mod;
    }
};