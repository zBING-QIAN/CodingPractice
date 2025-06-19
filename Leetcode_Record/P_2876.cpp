#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ans, rec;
    int find_loop(int cur, vector<int> &edges)
    {
        if (ans[edges[cur]])
        {
            ans[cur] = ans[edges[cur]] + 1;
            return rec[cur] + 1;
        }
        if (rec[edges[cur]])
        {
            ans[cur] = rec[cur] - rec[edges[cur]] + 1;
            return rec[edges[cur]];
        }
        else
        {
            rec[edges[cur]] = rec[cur] + 1;
            int tmp = find_loop(edges[cur], edges);
            ans[cur] = ans[edges[cur]];
            if (rec[cur] < tmp)
                ans[cur]++;
            return tmp;
        }
    }
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();
        ans.resize(n, 0);
        rec.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == 0)
            {
                rec[i] = 1;
                find_loop(i, edges);
            }
        }
        return ans;
    }
};