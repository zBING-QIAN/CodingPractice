#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> sum_mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int h = 0; h <= i; h++)
            {
                for (int w = 0; w < m; w++)
                {
                    sum_mat[h][w] = 0;
                }
            }
            for (int j = 0; j < m; j++)
            {
                int colsum = 0;
                for (int h = 0; h <= i; h++)
                {
                    colsum += matrix[i - h][j];
                    for (int w = 0; w <= j; w++)
                    {
                        sum_mat[i - h][j - w] += colsum;
                        if (sum_mat[i - h][j - w] == target)
                            ans++;
                    }
                }
            }
        }

        return ans;
    }
};