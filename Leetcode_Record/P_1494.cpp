#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void comb(int curstate, vector<int> &cand, int i, int k, set<int> &rec, vector<int> &dp)
    {
        if (dp[curstate] == 1000)
            rec.insert(curstate);
        if (k == 0)
        {
            return;
        }
        for (; i < cand.size(); i++)
        {
            comb(curstate | (1 << cand[i]), cand, i + 1, k - 1, rec, dp);
        }
    }
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k)
    {
        vector<int> deep(n, 0);
        vector<set<int>> prev(n, set<int>());
        vector<vector<int>> edge(n, vector<int>());
        for (auto &r : relations)
        {
            edge[r[1] - 1].push_back(r[0] - 1);
        }
        queue<int> q;
        q.push(0);
        vector<int> dp(1 << n, 1000);
        dp[0] = 0;
        while (q.size())
        {
            int curstate = q.front();
            q.pop();

            vector<int> cand;
            for (int i = 0; i < n; i++)
            {
                if (((1 << i) & curstate) == 0)
                {
                    bool good = 1;
                    for (auto &from : edge[i])
                    {
                        if (((1 << from) & curstate) == 0)
                        {
                            good = 0;
                            break;
                        }
                    }
                    if (good)
                        cand.push_back(i);
                }
            }
            set<int> rec;
            comb(curstate, cand, 0, k, rec, dp);
            for (auto &nxt : rec)
            {
                q.push(nxt);
                dp[nxt] = dp[curstate] + 1;
            }
            if (dp[(1 << n) - 1] != 1000)
                break;
        }
        // for(int i=0;i<dp.size();i++){cout<<dp[i]<<endl;}
        return dp[(1 << n) - 1];
    }
};