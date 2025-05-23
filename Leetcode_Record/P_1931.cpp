#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int colorTheGrid(int m, int n)
    {
        int mod = 1e9 + 7;
        long long res = 0;
        int pow3m = 1;
        for (int i = 0; i < m; i++)
            pow3m *= 3;
        vector<long long> dp, good(pow3m, 1);
        for (int i = 0; i < pow3m; i++)
            for (int j = 1, state = i; j < m; j++)
            {
                int cur = state % 3;
                state /= 3;
                if ((state % 3) == cur)
                {
                    good[i] = 0;
                    break;
                }
            }
        dp = good;
        for (int i = 1; i < n; i++)
        {
            vector<long long> nxtdp(pow3m, 0);
            for (int j = 0; j < pow3m; j++)
            {
                if (good[j])
                    for (int k = 0; k < pow3m; k++)
                    {
                        if (!good[k])
                            continue;
                        int nxtstate = j;
                        int state = k;
                        int dpk = dp[k];
                        for (int t = 0; t < m; t++)
                        {
                            int cur_color = state % 3;
                            state /= 3;
                            int nxt_color = nxtstate % 3;
                            nxtstate /= 3;
                            if (cur_color == nxt_color)
                            {
                                dpk = 0;
                                break;
                            }
                        }
                        nxtdp[j] += dpk;
                    }
                nxtdp[j] %= mod;
            }
            dp = nxtdp;
        }
        for (int i = 0; i < pow3m; i++)
        {
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};