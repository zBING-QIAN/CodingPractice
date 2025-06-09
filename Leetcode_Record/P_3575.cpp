#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long res = 0, mod = 1e9 + 7;
    int encode(int v)
    {
        int res = 0, tmp = 0;
        while (v)
        {
            tmp = (1 << (v % 10));
            if (res & tmp)
                return 0;
            res = res | tmp;
            v /= 10;
        }
        return res;
    }
    map<int, long long> dfs(int cur, vector<vector<int>> &edge, vector<int> &vals)
    {
        map<int, long long> state;
        int ve = encode(vals[cur]);
        state[0] = 0;
        if (ve)
            state[ve] = vals[cur];
        for (auto &to : edge[cur])
        {
            auto out_tmp = dfs(to, edge, vals);
            for (auto &s : out_tmp)
            {
                if (state[s.first] < s.second)
                {
                    for (auto &cur_s : state)
                    {
                        if ((cur_s.first & s.first) == 0)
                        {
                            state[cur_s.first | s.first] = max(state[cur_s.first | s.first], cur_s.second + s.second);
                        }
                    }
                }
            }
        }
        long long tmp = 0;
        for (auto &cur_s : state)
        {
            tmp = max(tmp, cur_s.second);
        }
        res += tmp;
        res %= mod;
        return state;
    }

    int goodSubtreeSum(vector<int> &vals, vector<int> &par)
    {
        int n = vals.size();
        vector<vector<int>> edge(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (par[i] >= 0)
                edge[par[i]].push_back(i);
        }
        dfs(0, edge, vals);
        return res;
    }
};