#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
class Solution
{
public:
    vector<int> ans;
    vector<int> val;
    vector<vector<array<int, 2>>> query;

    class Compare
    {
    public:
        bool operator()(ordered_set *a, ordered_set *b)
        {
            return a->size() < b->size();
        }
    };
    ordered_set *dfs(int cur, vector<vector<int>> &edge, int prefix = 0)
    {

        vector<ordered_set *> os;
        for (auto &to : edge[cur])
        {
            os.push_back(dfs(to, edge, prefix ^ val[cur]));
        }
        sort(os.begin(), os.end(), [](auto a, auto b)
             { return a->size() > b->size(); });
        while (os.size() > 1)
        {
            auto a = os[0];
            auto b = os.back();
            os.pop_back();
            for (auto it = b->begin(); it != b->end(); ++it)
                a->insert(*it);
            b->clear();
        }
        if (os.size() == 0)
        {
            os.push_back(new ordered_set());
        }
        os[0]->insert(prefix ^ val[cur]);
        for (auto &ki : query[cur])
        {
            ans[ki[1]] = (os[0]->size() >= ki[0]) ? *(os[0]->find_by_order(ki[0] - 1)) : -1;
        }
        return os[0];
    }
    vector<int> kthSmallest(vector<int> &par, vector<int> &vals, vector<vector<int>> &queries)
    {
        int n = par.size();
        val = vals;
        ans.resize(queries.size(), -2);
        query.resize(n, vector<array<int, 2>>());
        for (int i = 0; i < queries.size(); i++)
        {
            query[queries[i][0]].push_back({queries[i][1], i});
        }
        vector<vector<int>> edge(n, vector<int>());
        for (int i = 1; i < n; i++)
        {
            if (par[i] >= 0)
                edge[par[i]].push_back(i);
        }
        dfs(0, edge);
        return ans;
    }
};