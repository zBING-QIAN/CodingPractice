#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = INT_MAX;
        map<int, int> cnt;
        for (int i = 0, cur = nums[0]; i < n; i++)
        {
            if (nums[i] >= cur + n)
            {
                if (ans > n - cnt.size())
                    ans = n - cnt.size();
                auto it = cnt.begin();
                cnt.erase(it);
                cur = cnt.begin()->first;
            }
            cnt[nums[i]]++;
        }
        if (ans > n - cnt.size())
            ans = n - cnt.size();
        return ans;
    }
};