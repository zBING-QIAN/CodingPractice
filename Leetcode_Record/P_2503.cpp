#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<array<int, 2>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = grid.size(), m = grid[0].size();
        map<int, vector<array<int, 2>>> table;
        map<int, int> dp;
        vector<vector<bool>> visit(n, vector<bool>(m, 0));
        table[grid[0][0] + 1].push_back({0, 0});
        visit[0][0] = 1;
        int cnt = 0;
        while (table.size())
        {
            int cur = table.begin()->first;
            auto q = table.begin()->second;
            int i = 0;
            while (i < q.size())
            {
                auto [x, y] = q[i];
                for (auto &d : dirs)
                {
                    if (x + d[0] < n && x + d[0] >= 0 && y + d[1] < m && y + d[1] >= 0 && !visit[x + d[0]][y + d[1]])
                    {
                        if (grid[x + d[0]][y + d[1]] < cur)
                        {
                            q.push_back({x + d[0], y + d[1]});
                        }
                        else
                        {
                            table[grid[x + d[0]][y + d[1]] + 1].push_back({x + d[0], y + d[1]});
                        }
                        visit[x + d[0]][y + d[1]] = 1;
                    }
                }
                i++;
            }
            table.erase(cur);
            cnt += q.size();
            dp[cur] = cnt;
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            auto upb = dp.upper_bound(q);
            if (upb == dp.begin())
                ans.push_back(0);
            else
            {
                upb--;
                ans.push_back(upb->second);
            }
        }
        return ans;
    }
};