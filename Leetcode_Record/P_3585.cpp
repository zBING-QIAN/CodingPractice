#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pre_link;
    vector<vector<array<int, 2>>> edge;
    vector<int> stac, h;
    vector<long long> deep;
    void build(int cur, int pre, long long d = 0)
    {
        deep[cur] = d;
        h[cur] = stac.size();
        for (int i = 1; i <= stac.size(); i <<= 1)
        {
            pre_link[cur].push_back(stac[stac.size() - i]);
        }
        stac.push_back(cur);
        for (auto &to : edge[cur])
        {
            if (to[0] != pre)
            {
                build(to[0], cur, d + to[1]);
            }
        }
        stac.pop_back();
    }
    int lca(int a, int b)
    {
        if (h[a] < h[b])
        {
            swap(a, b);
        }
        for (int i = pre_link[a].size() - 1; i >= 0; i--)
        {
            if (i < pre_link[a].size() && h[pre_link[a][i]] > h[b])
                a = pre_link[a][i];
        }
        if (h[a] > h[b])
            a = pre_link[a][0];
        for (int i = pre_link[a].size() - 1; i >= 0; i--)
        {
            if (i < pre_link[a].size() && pre_link[a][i] != pre_link[b][i])
            {
                a = pre_link[a][i];
                b = pre_link[b][i];
            }
        }
        if (a != b)
            return pre_link[a][0];
        return a;
    }
    int query(int a, int b)
    {
        int p = lca(a, b);                                     // cout<<a<<" "<<b<<" "<<p<<endl;
        long long dis = deep[a] - deep[p] + deep[b] - deep[p]; // cout<<a<<" "<<b<<" "<<p<<" "<<dis<<endl;
        long long target;
        if (deep[b] >= deep[a])
        {
            target = ((dis + 1) / 2) - (deep[a] - deep[p]) + deep[p];
            for (int i = pre_link[b].size() - 1; i >= 0; i--)
            {
                if (i < pre_link[b].size() && deep[pre_link[b][i]] >= target)
                {
                    b = pre_link[b][i];
                }
            }
            return b;
        }
        else
        {
            target = (dis / 2) - (deep[b] - deep[p]) + deep[p];
            for (int i = pre_link[a].size() - 1; i >= 0; i--)
            {
                if (i < pre_link[a].size() && deep[pre_link[a][i]] > target)
                {
                    a = pre_link[a][i];
                }
            }
            a = pre_link[a][0];
            return a;
        }
    }

    vector<int> findMedian(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        pre_link.resize(n, vector<int>());
        edge.resize(n, vector<array<int, 2>>());
        deep.resize(n, 0);
        h.resize(n, 0);
        for (auto &e : edges)
        {
            edge[e[0]].push_back({e[1], e[2]});
            edge[e[1]].push_back({e[0], e[2]});
        }
        build(0, 0);
        // for(int i=0;i<n;i++){
        //     cout<<i<<" "<<deep[i]<<" "<<h[i]<<endl;
        //     for(auto a:pre_link[i])cout<<a<<" ";cout<<endl;
        // }
        vector<int> ans;
        for (auto &q : queries)
        {
            ans.push_back(query(q[0], q[1]));
        }
        return ans;
    }
};