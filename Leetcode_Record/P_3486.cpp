#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<array<int, 2>>> edge;
    vector<int> color;
    vector<array<int, 2>> dp;
    vector<vector<int>> colors;

    vector<int> stac, len;
    void dfs(int cur, int prev, int front = 0, int path = 0, int state = -1)
    {
        stac.push_back(cur);
        len.push_back(path);
        int cur_color = color[cur];
        // cout<<cur<<" "<<prev<<" "<<front<<" "<<path<<" "<<state<<" "<<cur_color<<endl;
        // cout<<cur<<" "<<front<<" "<<colors[cur_color].size()<<" "<<state<<endl;
        if (colors[cur_color].size() && colors[cur_color].back() >= front && state >= 0)
        {
            if (state == cur_color)
            {

                // cout<<cur<<" "<<front<<" "<<path<<" "<<colors[cur_color][colors[cur_color].size()-2]<<endl;
                front = colors[cur_color][colors[cur_color].size() - 2] + 1;
            }
            else
            {
                int tmp0 = colors[cur_color].back() + 1;
                int tmp1 = colors[state][colors[state].size() - 2] + 1;
                if (tmp0 < tmp1)
                {
                    front = tmp0;
                }
                else
                {
                    state = cur_color;
                    front = tmp1;
                }
            }
        }
        if (colors[cur_color].size() > 0 && front <= colors[cur_color].back())
            state = cur_color;
        colors[cur_color].push_back(stac.size() - 1);
        dp[cur] = {path - len[front], (int)stac.size() - front};

        // cout<<cur<<" "<<prev<<" "<<front<<" "<<path<<" "<<state<<" dpcur "<<dp[cur][0]<<" "<<dp[cur][1]<<endl;
        for (auto to : edge[cur])
        {
            if (prev != to[0])
                dfs(to[0], cur, front, to[1] + path, state);
        }
        stac.pop_back();
        len.pop_back();
        colors[cur_color].pop_back();
    }
    vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
    {
        int n = nums.size();
        color = nums;
        dp.resize(n, {0, 0});
        colors.resize(5e4 + 5, vector<int>());
        edge.resize(n, vector<array<int, 2>>());
        for (auto &e : edges)
        {
            edge[e[0]].push_back({e[1], e[2]});
            edge[e[1]].push_back({e[0], e[2]});
        }
        dfs(0, 0, 0, 0, -1);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i][0] > a)
            {
                a = dp[i][0];
                b = dp[i][1];
            }
            if (dp[i][0] == a && b > dp[i][1])
            {
                b = dp[i][1];
            }
        }

        return {a, b};
    }
};