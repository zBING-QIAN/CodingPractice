#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    vector<vector<array<int, 8>>> dp;
    vector<array<int, 2>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dfs(int i, int j, int dir, int rot, vector<vector<int>> &grid)
    {
        if (dp[i][j][dir * 2 + rot] > 0)
            return dp[i][j][dir * 2 + rot];
        int out = 1;
        if (grid[i][j] == 1)
        {
            for (int h = 0; h < 4; h++)
            {
                auto &d = dirs[h];
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < n && y < m && y >= 0 && grid[x][y] == 2)
                {
                    out = max(out, 1 + dfs(x, y, h, 0, grid));
                }
            }
        }
        else if (grid[i][j] == 0)
        {
            int x = i + dirs[dir][0], y = j + dirs[dir][1];
            if (x >= 0 && x < n && y < m && y >= 0 && grid[x][y] == 2)
            {
                out = 1 + dfs(x, y, dir, rot, grid);
            }
            if (rot == 0)
            {
                int dir_tmp = (dir + 1) % 4;
                x = i + dirs[dir_tmp][0], y = j + dirs[dir_tmp][1];
                if (x >= 0 && x < n && y < m && y >= 0 && grid[x][y] == 2)
                {
                    out = max(out, 1 + dfs(x, y, dir_tmp, 1, grid));
                }
                // dir_tmp = (dir+3)%4;
                // x=i+dirs[dir_tmp][0],y=j+dirs[dir_tmp][1];
                // if(x>=0&&x<n&&y<m&&y>=0&&grid[x][y]==2){
                //     out = max(out,1+dfs(x,y,dir_tmp,1,grid));
                // }
            }
        }
        else if (grid[i][j] == 2)
        {
            int x = i + dirs[dir][0], y = j + dirs[dir][1];
            if (x >= 0 && x < n && y < m && y >= 0 && grid[x][y] == 0)
            {
                out = 1 + dfs(x, y, dir, rot, grid);
            }
            if (rot == 0)
            {
                int dir_tmp = (dir + 1) % 4;
                x = i + dirs[dir_tmp][0], y = j + dirs[dir_tmp][1];
                if (x >= 0 && x < n && y < m && y >= 0 && grid[x][y] == 0)
                {
                    out = max(out, 1 + dfs(x, y, dir_tmp, 1, grid));
                }
                // dir_tmp = (dir+3)%4;
                // x=i+dirs[dir_tmp][0],y=j+dirs[dir_tmp][1];
                // if(x>=0&&x<n&&y<m&&y>=0&&grid[x][y]==0){
                //     out = max(out,1+dfs(x,y,dir_tmp,1,grid));
                // }
            }
        }
        dp[i][j][dir * 2 + rot] = out;
        return out;
    }
    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<array<int, 8>>(m, {0, 0, 0, 0, 0, 0, 0, 0}));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(i, j, 0, 0, grid));
            }
        }
        return ans;
    }
};