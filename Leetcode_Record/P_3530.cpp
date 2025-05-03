#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans;
    vector<vector<int>> edge;
    vector<int> incnt, incnt_run;
    int endstate, N;
    vector<int> dp;
    int run(int t, int state, vector<int> &score)
    {
        if (state == endstate)
        {
            return 0;
        }
        if (dp[state] >= 0)
            return dp[state];
        int val = 0;
        for (int i = 0; i < N; i++)
        {
            if ((state & (1 << i)) == 0 && incnt_run[i] == incnt[i])
            {
                for (auto &to : edge[i])
                {
                    incnt_run[to]++;
                }
                val = max(val, t * score[i] + run(t + 1, (state | (1 << i)), score));
                for (auto &to : edge[i])
                {
                    incnt_run[to]--;
                }
            }
        }
        dp[state] = val;
        return val;
    }

    int maxProfit(int n, vector<vector<int>> &edges, vector<int> &score)
    {
        edge.resize(n, vector<int>());
        incnt.resize(n, 0);
        incnt_run.resize(n, 0);
        endstate = (1 << n) - 1;
        N = n;
        dp.resize(endstate + 1, -1);
        for (auto &e : edges)
        {
            edge[e[0]].push_back(e[1]);
            incnt[e[1]]++;
        }
        return run(1, 0, score);
    }
};