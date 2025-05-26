#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> visit;
    vector<array<int, 26>> dp;
    bool dfs(int cur, vector<vector<int>> &edge, string &colors)
    {
        if (visit[cur] == 2)
            return 0;
        visit[cur] = 1;
        for (auto &to : edge[cur])
        {
            if (visit[to] == 0)
            {
                if (dfs(to, edge, colors))
                    return 1;
            }
            else if (visit[to] == 1)
            {
                return 1;
            }
            for (int i = 0; i < 26; i++)
            {
                dp[cur][i] = max(dp[cur][i], dp[to][i]);
            }
        }
        dp[cur][colors[cur] - 'a']++;
        visit[cur] = 2;
        return 0;
    }
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        visit.resize(n, 0);
        dp.resize(n, array<int, 26>());
        vector<vector<int>> edge(n, vector<int>());
        vector<int> inedge(n, 0);
        for (auto &e : edges)
        {
            edge[e[0]].push_back(e[1]);
            inedge[e[1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            // cout<<i<<" "<<endl;
            // for(int j=0;j<26;j++){cout<<dp[i][j]<<" ";cout<<endl;}
            if (dfs(i, edge, colors))
                return -1;
            // for(int j=0;j<26;j++){cout<<dp[i][j]<<" ";cout<<endl;}
            for (int j = 0; j < 26; j++)
            {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};