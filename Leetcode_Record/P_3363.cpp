#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        int ans = 0, n = fruits.size();
        for (int i = 0; i < n; i++)
        {
            ans += fruits[i][i];
        }
        vector<vector<int>> f1 = fruits;
        for (int i = 0; i < n; i++)
        {
            for (int j = max(i, n - i - 2); j >= 0; j--)
            {
                f1[i][j] = 0;
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            int b = max(i + 1, n - i - 1);
            // cout<<f1[0][n-1]<<endl;
            for (int j = n - 1; j >= b; j--)
            {
                int tmp = max(f1[i - 1][j], f1[i - 1][j - 1]);
                // cout<<i<<" "<<j<<" "<<tmp<<endl;
                if (j + 1 < n)
                    tmp = max(tmp, f1[i - 1][j + 1]);
                // cout<<i<<" "<<j<<" "<<tmp<<endl;
                f1[i][j] += tmp;
                // cout<<i<<" "<<j<<" "<<f1[i][j]<<endl;
            }
        }
        ans += f1[n - 2][n - 1];

        vector<vector<int>> f2 = fruits;
        for (int i = 0; i < n; i++)
        {
            for (int j = max(i, n - i - 2); j >= 0; j--)
            {
                f2[j][i] = 0;
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            int b = max(i + 1, n - i - 1);
            for (int j = n - 1; j >= b; j--)
            {
                int tmp = max(f2[j][i - 1], f2[j - 1][i - 1]);
                if (j + 1 < n)
                    tmp = max(tmp, f2[j + 1][i - 1]);
                f2[j][i] += tmp;
            }
        }
        ans += f2[n - 1][n - 2];
        return ans;
    }
};