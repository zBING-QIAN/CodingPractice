#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int res = 1;
    int dfs(vector<vector<int>> &edge, string &s, int cur)
    {
        int best = 0;
        for (auto &to : edge[cur])
        {
            int tmp = dfs(edge, s, to);
            if (s[cur] != s[to])
            {
                if (res < tmp + best + 1)
                    res = tmp + best + 1;
                if (best < tmp)
                    best = tmp;
            }
        }
        return best + 1;
    }
    int longestPath(vector<int> &parent, string s)
    {
        vector<vector<int>> edge(s.size(), vector<int>());
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (parent[i] >= 0)
                edge[parent[i]].push_back(i);
        }
        dfs(edge, s, 0);
        return res;
    }
};