#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> primes = {2, 3, 5, 7};
    int get(int n)
    {
        int out = 0;
        int digit = 0, base = n;
        for (; base; base /= 10, digit++)
            ;
        base = n;
        map<pair<int, long long>, int> dp, dpr, ans; // {sum,product}
        int lead0 = 1;
        dp[{0, 1}] = 1;
        dpr[{0, 1}] = 1;
        for (int d = 0; d < digit; d++, base /= 10)
        {
            map<pair<int, long long>, int> nxt_dp, nxt_dpr;
            int upbnd = base % 10;
            // cout<<"d "<<d<<"  upbnd "<<upbnd<<endl;
            lead0 = 0;
            for (auto &state : dp)
            {
                for (int i = 0; i < 10; i++)
                {
                    if (d + 1 < digit)
                    {
                        nxt_dp[{state.first.first + i, state.first.second * i}] += state.second;
                        if (i > 0)
                            ans[{state.first.first + i, state.first.second * i}] += state.second;
                    }
                    if (i < upbnd)
                    {
                        if (i == 0)
                            lead0 += state.second;
                        nxt_dpr[{state.first.first + i, state.first.second * i}] += state.second;
                    }
                }
            }
            for (auto &state : dpr)
            {
                // cout<<state.first.first<<" "<<state.first.second<<" "<<state.second<<endl;
                nxt_dpr[{state.first.first + upbnd, state.first.second * upbnd}] += state.second;
            }
            dp = nxt_dp;
            dpr = nxt_dpr;
        }
        // cout<<endl;
        for (auto &state : dpr)
        {
            // cout<<state.first.first<<" "<<state.first.second<<" "<<state.second<<endl;
            if (state.first.first > 0 && (state.first.second % state.first.first) == 0)
                out += state.second;
        }
        for (auto &state : ans)
        {
            // cout<<state.first.first<<" "<<state.first.second<<" "<<state.second<<endl;
            if (state.first.first > 0 && (state.first.second % state.first.first) == 0)
                out += state.second;
        }
        // cout<<out<<" "<<lead0<<endl;
        return out - lead0;
    }
    int beautifulNumbers(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};