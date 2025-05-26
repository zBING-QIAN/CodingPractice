#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> deep;
    int maxlink = 0;
    vector<vector<int>> anc;
    vector<int> stac;
    int lca(int a, int b)
    {
        if (deep[a] < deep[b])
        {
            swap(a, b);
        }
        for (int i = maxlink - 1; i >= 0 && deep[a] != deep[b]; i--)
        {
            // cout<<anc[a][i]<<" "<<deep[anc[a][i]]<<" "<<i<<" "<<a<<" "<<deep[b]<<endl;
            if (anc[a][i] > 0 && deep[anc[a][i]] >= deep[b])
                a = anc[a][i];
        }
        if (a == b)
            return a;
        for (int i = maxlink - 1; i >= 0; i--)
        {
            if (anc[a][i] > 0 && anc[a][i] != anc[b][i])
            {
                a = anc[a][i];
                b = anc[b][i];
            }
            // cout<<a<<" "<<b<<endl;
        }
        return anc[a][0];
    }

    void dfs(int cur, int pre, int d, vector<vector<int>> &edge)
    {
        deep[cur] = d;
        anc[cur].resize(maxlink, 0);
        for (int i = 1, j = 0; i <= stac.size(); i <<= 1, j++)
            anc[cur][j] = stac[stac.size() - i];
        stac.push_back(cur);
        for (auto &to : edge[cur])
        {
            if (to != pre)
            {
                dfs(to, cur, d + 1, edge);
            }
        }
        stac.pop_back();
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        int n = edges.size() + 2;
        for (int tmp = 1; tmp < n; tmp <<= 1, maxlink++)
            ;
        deep.resize(n, 0);
        anc.resize(n, vector<int>());
        vector<vector<int>> edge(n, vector<int>());
        for (auto &e : edges)
        {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        dfs(1, 1, 0, edge);
        int maxd = 0, mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
            maxd = max(maxd, deep[i]);
        vector<vector<long long>> dp(maxd * 2 + 1, vector<long long>(2, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= maxd * 2; i++)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        }
        vector<int> res;
        for (auto &q : queries)
        {
            int lcatmp = lca(q[0], q[1]);
            // cout<<q[0]<<" "<<deep[q[0]]<<" "<<q[1]<<" "<<deep[q[1]]<<" "<<lcatmp<<" "<<deep[lcatmp]<<endl;
            int tmp = deep[q[0]] + deep[q[1]] - 2 * deep[lcatmp];
            // cout<<tmp<<endl;
            res.push_back(dp[tmp][1]);
        }
        return res;
    }
};