#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long ans = 0;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            sum += nums[i];
            while (j <= i && sum * (i - j + 1) >= k)
            {
                sum -= nums[j];
                j++;
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};