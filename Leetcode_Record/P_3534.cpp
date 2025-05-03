#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<array<int, 2>> id(n);
        vector<int> ans;
        vector<vector<int>> prelink;
        prelink.push_back(vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            id[i] = {nums[i], i};
        }
        sort(id.begin(), id.end());
        for (int i = 0, j = 0; i < n; i++)
        {
            nums[id[i][1]] = i;
            while (id[i][0] - id[j][0] > maxDiff)
            {
                j++;
            }
            prelink[0][i] = j;
        }
        for (int i = 2; i < n; i <<= 1)
        {
            vector<int> pre(n, 0);
            auto &plk = prelink.back();
            for (int j = 0; j < n; j++)
            {
                pre[j] = plk[plk[j]];
                // pre[j] = prelink.back()[prelink.back()[j]]
            }
            prelink.push_back(pre);
        }
        for (auto &q : queries)
        {
            int a = nums[q[0]], b = nums[q[1]], res = 0;
            if (a == b)
            {
                ans.push_back(0);
                continue;
            }
            if (a > b)
                swap(a, b);
            for (int i = prelink.size() - 1; i >= 0; i--)
            {
                if (prelink[i][b] > a)
                {
                    res += (1 << i);
                    b = prelink[i][b];
                }
            }
            if (prelink[0][b] <= a)
                res++;
            else
                res = -1;
            ans.push_back(res);
        }

        return ans;
    }
};