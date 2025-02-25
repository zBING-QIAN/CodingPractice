#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> edge1, edge2;
    vector<int> tag1, tag2;
    void dfs1(int cur, bool even)
    {
        tag1[cur] = even;
        for (auto &to : edge1[cur])
        {
            if (tag1[to] == -1)
                dfs1(to, 1 - even);
        }
    }
    void dfs2(int cur, bool even)
    {
        tag2[cur] = even;
        for (auto &to : edge2[cur])
        {
            if (tag2[to] == -1)
                dfs2(to, 1 - even);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        tag1.resize(n, -1);
        edge1.resize(n, vector<int>());
        for (auto &e : edges1)
        {
            edge1[e[0]].push_back(e[1]);
            edge1[e[1]].push_back(e[0]);
        }
        dfs1(0, 0);
        int m = edges2.size() + 1;
        tag2.resize(m, -1);
        edge2.resize(m, vector<int>());
        for (auto &e : edges2)
        {
            edge2[e[0]].push_back(e[1]);
            edge2[e[1]].push_back(e[0]);
        }
        dfs2(0, 0);
        int cnt0_2 = 0, cnt1_2 = 0;
        for (int i = 0; i < tag2.size(); i++)
        {
            if (tag2[i])
                cnt1_2++;
            else
                cnt0_2++;
        }
        cnt0_2 = max(cnt0_2, cnt1_2);
        int cnt0 = 0, cnt1 = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < tag1.size(); i++)
        {
            if (tag1[i])
                cnt1++;
            else
                cnt0++;
        }
        for (int i = 0; i < tag1.size(); i++)
        {
            if (tag1[i])
                ans[i] = cnt1 + cnt0_2;
            else
                ans[i] = cnt0 + cnt0_2;
        }
        return ans;
    }
};