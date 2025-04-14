#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> rngl, rngr, rngv, rnglazy;

    vector<vector<array<int, 2>>> edge;
    vector<vector<array<int, 2>>> edge_update;
    vector<vector<int>> edge_query;
    vector<int> f, ans;
    vector<int> lazy;
    int st;
    void update(int t, int v)
    {
        int rt = 1, l = 0, r = st - 1;
        while (l < r)
        {
            lazy[rt << 1] += lazy[rt];
            lazy[(rt << 1) + 1] += lazy[rt];
            lazy[rt] = 0;
            int mid = (l + r) >> 1;
            if (t <= mid)
            {
                lazy[1 + (rt << 1)] += v;
                r = mid;
                rt = rt << 1;
            }
            else
            {
                l = mid + 1;
                rt = 1 + (rt << 1);
            }
        }
        lazy[t + st] += v;
    }
    int query(int t)
    {
        int rt = 1, l = 0, r = st - 1;
        while (l < r)
        {
            lazy[rt << 1] += lazy[rt];
            lazy[(rt << 1) + 1] += lazy[rt];
            lazy[rt] = 0;
            int mid = (l + r) >> 1;
            if (t <= mid)
            {
                r = mid;
                rt = rt << 1;
            }
            else
            {
                l = mid + 1;
                rt = 1 + (rt << 1);
            }
        }
        return lazy[t + st];
    }
    void run(int cur = 1)
    {
        int pre_v = 0;
        for (auto [t, v] : edge_update[cur])
        {
            update(t, v - pre_v);
            pre_v = v;
        }
        for (auto t : edge_query[cur])
        {
            ans[t] = query(t);
        }
        for (auto &e : edge[cur])
        {
            if (f[cur] != e[0])
                run(e[0]);
        }
        pre_v = 0;
        for (auto [t, v] : edge_update[cur])
        {
            update(t, pre_v - v);
            pre_v = v;
        }
    }

public:
    vector<int> treeQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        edge.resize(n + 1, vector<array<int, 2>>());
        edge_query.resize(n + 1, vector<int>());
        edge_update.resize(n + 1, vector<array<int, 2>>());
        f.resize(n + 1, -1);
        f[1] = 0;
        for (auto &e : edges)
        {
            edge[e[0]].push_back({e[1], e[2]});
            edge[e[1]].push_back({e[0], e[2]});
        }

        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            for (auto &to : edge[cur])
            {
                if (f[to[0]] == -1)
                {
                    f[to[0]] = cur;
                    edge_update[to[0]].push_back({0, to[1]});
                    q.push(to[0]);
                }
            }
        }

        ans.resize(queries.size(), -1);
        int qs = queries.size();
        for (st = 1; st < qs; st <<= 1)
            ;
        lazy.resize(st << 1, 0);
        for (int t = 0; t < queries.size(); t++)
        {
            auto &qq = queries[t];
            if (qq[0] == 2)
            {
                int cur = qq[1];
                edge_query[cur].push_back(t);
            }
            else
            {
                int cur = (f[qq[2]] == qq[1]) ? cur = qq[2] : qq[1];
                edge_update[cur].push_back({t, qq[3]});
            }
        }
        run();
        int c = 0;
        for (int i = 0; i < ans.size(); c++, i++)
        {
            while (i < ans.size() && ans[i] == -1)
                i++;
            // if(c>=i)cout<<i<<" "<<c<<" "<<ans[i]<<endl;
            if (i < ans.size())
                ans[c] = ans[i];
            else
                break;
        }
        ans.resize(c);
        return ans;
    }
};