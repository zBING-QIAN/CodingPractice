#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int n = nums.size(), up = -1, down = -1;
        for (int i = 0, j = -1; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                j = i;
                up = i, down = i;
            }
            else
            {
                if (nums[i] == minK)
                    down = i;
                if (nums[i] == maxK)
                    up = i;
                int tmp = min(i, min(up, down)) - j;
                // cout<<i<<" "<<j<<" "<<up<<" "<<down<<endl;
                ans += tmp;
            }
        }
        return ans;
    }
};