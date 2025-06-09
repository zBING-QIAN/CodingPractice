#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTime(vector<int> &nums1, vector<int> &nums2, int x)
    {
        int sum1 = 0, sum2 = 0, psum = 0, n = nums2.size();
        vector<array<int, 2>> nums(n);
        for (int i = 0; i < n; i++)
        {
            sum1 += nums1[i];
            sum2 += nums2[i];
            nums[i] = {nums2[i], nums1[i]};
        }
        sort(nums.begin(), nums.end());
        if (sum1 <= x)
            return 0;
        vector<bool> used(n, 0);
        for (int t = 1; t <= n; t++)
        {
            int best = 1e9, idx = -1, c = 1, cpsum = psum;
            for (int i = 0; i < n; i++)
            {
                if (used[i] == 0)
                {
                    int tmp = sum2 - cpsum - (nums[i][1] + nums[i][0] * c);
                    if (best > tmp)
                    { //(== ,nums[i][0]<)
                        best = tmp;
                        idx = i;
                    }
                }
                else
                {
                    c++;
                    cpsum -= nums[i][0];
                }
            }
            used[idx] = 1;
            c = 1;
            best = sum1 + sum2 * t;
            for (int i = 0; i < n; i++)
            {
                if (used[i])
                {
                    best -= (nums[i][0] * c + nums[i][1]);
                    c++;
                }
            }
            if (best <= x)
                return t;
            psum += nums[idx][0];
        }
        return -1;
    }
};