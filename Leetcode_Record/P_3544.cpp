#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> edge;
    vector<int> num;
    int n;
    vector<array<long long, 2>> dfs(int cur, int par, int k)
    {
        vector<array<long long, 2>> res(k, {num[cur], num[cur]}); // {min,max}
        long long invmn = 0, invmx = 0, mn = 0, mx = 0;
        for (auto &to : edge[cur])
        {
            if (to != par)
            {
                auto tmp = dfs(to, cur, k);
                for (int i = 1; i < k; i++)
                {
                    long long tmpmin = tmp[i - 1][0], tmpmax = tmp[i - 1][0];
                    for (int j = 1; j < 2; j++)
                    {
                        tmpmin = min(tmp[i - 1][j], tmpmin);
                        tmpmax = max(tmp[i - 1][j], tmpmax);
                    }
                    res[i][0] += tmpmin;
                    res[i][1] += tmpmax;
                }
                long long tmpmin = tmp[k - 1][0], tmpmax = tmp[k - 1][0];
                for (int j = 1; j < 2; j++)
                {
                    tmpmin = min(tmp[k - 1][j], tmpmin);
                    tmpmax = max(tmp[k - 1][j], tmpmax);
                }
                mn += tmpmin;
                mx += tmpmax;
                invmn -= tmpmax;
                invmx -= tmpmin;
            }
        }
        res[0][0] = min(mn + num[cur], invmn - num[cur]);
        if (k > 1)
            res[0][0] = min(res[1][0], res[0][0]);
        res[0][1] = max(mx + num[cur], invmx - num[cur]);
        if (k > 1)
            res[0][1] = max(res[1][1], res[0][1]);
        // cout<<cur<<endl;
        // for(int i=0;i<k;i++){
        //     for(int j=0;j<2;j++){cout<<res[i][j]<<" ";}
        //     cout<<endl;
        // }
        return res;
    }
    long long subtreeInversionSum(vector<vector<int>> &edges, vector<int> &nums, int k)
    {
        n = nums.size();
        num = nums;
        edge.resize(n, vector<int>());
        for (auto &e : edges)
        {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        auto tmp = dfs(0, 0, k);
        long long ans = -1e12;
        for (auto &t : tmp)
        {
            for (int i = 0; i < 2; i++)
                ans = max(ans, t[i]);
        }
        return ans;
    }
};