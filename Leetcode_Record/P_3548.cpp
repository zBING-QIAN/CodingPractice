#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        long long sum = 0;
        vector<int> cnt(1e5 + 2, 0), cnttmp(1e5 + 2, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum += grid[i][j];
                cnt[grid[i][j]]++;
            }
        }
        long long tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp += grid[i][j];
                cnttmp[grid[i][j]]++;
            }
            if (tmp == sum - tmp)
                return 1;
            if (tmp > sum - tmp)
            {
                long long dis = tmp - sum + tmp;
                if (dis <= 1e5 && cnttmp[dis] > 0)
                {
                    if (m == 1)
                    {
                        if ((i > 0 && i + 1 < n) && (grid[0][0] == dis || grid[i][0] == dis))
                        {
                            return 1;
                        }
                    }
                    else if ((i > 0 && i + 1 < n) || (grid[i][0] == dis || grid[i][m - 1] == dis))
                    {
                        return 1;
                    }
                }
            }
            else
            {
                long long dis = sum - tmp - tmp;
                if (dis <= 1e5 && cnt[dis] - cnttmp[dis] > 0)
                {
                    if (m == 1)
                    {
                        if ((i > 0 && i + 1 < n) && (grid[n - 1][0] == dis || grid[i + 1][0] == dis))
                        {
                            return 1;
                        }
                    }
                    else if ((i > 0 && i + 1 < n) || (grid[i + 1][0] == dis || grid[i + 1][m - 1] == dis))
                    {
                        return 1;
                    }
                }
            }
        }
        cnttmp.assign(1e5 + 2, 0);
        tmp = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp += grid[j][i];
                cnttmp[grid[j][i]]++;
            }
            if (tmp == sum - tmp)
                return 1;

            if (tmp > sum - tmp)
            {
                long long dis = tmp - sum + tmp;
                if (dis <= 1e5 && cnttmp[dis] > 0)
                {
                    if (n == 1)
                    {
                        if ((i > 0 && i + 1 < m) && (grid[0][0] == dis || grid[0][i] == dis))
                        {
                            return 1;
                        }
                    }
                    else if ((i > 0 && i + 1 < m) || (grid[0][i] == dis || grid[n - 1][i] == dis))
                    {
                        return 1;
                    }
                }
            }
            else
            {
                long long dis = sum - tmp - tmp;
                if (dis <= 1e5 && cnt[dis] - cnttmp[dis] > 0)
                {
                    if (n == 1)
                    {
                        if ((i > 0 && i + 1 < m) && (grid[0][m - 1] == dis || grid[0][i + 1] == dis))
                        {
                            return 1;
                        }
                    }
                    else if ((i > 0 && i + 1 < m) || (grid[0][i + 1] == dis || grid[n - 1][i + 1] == dis))
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};