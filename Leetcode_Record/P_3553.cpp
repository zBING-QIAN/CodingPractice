#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<int> res, deep;
    vector<vector<array<int, 2>>> edge, fastlink;
    vector<array<int, 2>> stac;
    void dfs(int cur, int prev, int d)
    {
        deep[cur] = stac.size();
        int tmp = 1, n = stac.size();
        while (tmp <= n)
        {
            fastlink[cur].push_back({stac[n - tmp][0], d - stac[n - tmp][1]});
            // cout<<cur<<" "<<fastlink[cur].back()[0]<<" "<<fastlink[cur].back()[1]<<endl;
            tmp <<= 1;
        }
        stac.push_back({cur, d});
        for (auto &to : edge[cur])
        {
            if (to[0] != prev)
            {
                dfs(to[0], cur, to[1] + d);
            }
        }
        stac.pop_back();
    }
    array<int, 2> askanc(int a, int pos)
    {
        int gap = deep[a] - pos, out = 0;
        for (int i = 0; gap; i++, gap >>= 1)
        {
            if (gap & 1)
            {
                // cout<<"askanc "<<a<<" "<<pos<<" "<<i<<" "<<gap<<" "<<out<<endl;
                out += fastlink[a][i][1];
                a = fastlink[a][i][0];
            }
        }
        return {a, out};
    }

    array<int, 3> com_anc(int a, int b)
    {
        int l = 0, r = min(deep[a], deep[b]) + 1, out = 0, id = 0;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            auto t0 = askanc(a, mid), t1 = askanc(b, mid);
            if (t0[0] == t1[0])
            {
                l = mid + 1;
            }
            else
            {
                a = t0[0], b = t1[0];
                out += t0[1] + t1[1];
                r = mid;
            }
        }
        if (l)
            l--;
        auto t0 = askanc(a, l), t1 = askanc(b, l);
        id = t0[0];
        out += t0[1] + t1[1];
        // cout<<"in com "<<a<<" "<<b<<" "<<id<<" "<<out<<endl;
        return {id, l, out};
    }

    vector<int> minimumWeight(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        n = edges.size() + 1;
        edge.resize(n, vector<array<int, 2>>());
        fastlink.resize(n, vector<array<int, 2>>());
        deep.resize(n, -1);
        deep[0] = 0;
        for (auto &e : edges)
        {
            edge[e[0]].push_back({e[1], e[2]});
            edge[e[1]].push_back({e[0], e[2]});
        }
        dfs(0, -1, 0);
        for (int i = 0; i < queries.size(); i++)
        {
            int maxd = 0, id = 0, p = 0, out = 0;
            for (int j = 0; j < 3; j++)
            {
                auto [idtmp, dtmp, outtmp] = com_anc(queries[i][j], queries[i][(j + 1) % 3]);
                if (dtmp > maxd || j == 0)
                {
                    maxd = dtmp;
                    id = idtmp;
                    p = j;
                    out = outtmp;
                }
            }
            if (id != queries[i][(p + 2) % 3])
            {
                auto [idtmp, dtmp, outtmp] = com_anc(id, queries[i][(p + 2) % 3]);
                out += outtmp;
            }

            res.push_back(out);
        }

        return res;
    }
};