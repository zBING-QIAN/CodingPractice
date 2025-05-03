#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dig, ans;
    vector<int> numsmod;
    int state, endstate;
    int n, K;
    set<array<int, 2>> dp;
    bool run(vector<int> &nums, int cur, int value)
    {
        if (dp.count({state, value}))
            return 0;
        if (state == endstate)
        {
            return value == 0;
        }
        for (int i = 0; i < n; i++)
        {
            if ((state & (1 << i)) == 0)
            {
                state = state | (1 << i);
                ans[cur] = nums[i];
                if (run(nums, cur + 1, (value * dig[i] + numsmod[i]) % K))
                    return 1;
                state = state ^ (1 << i);
            }
        }
        dp.insert({state, value});
        return 0;
    }
    vector<int> concatenatedDivisibility(vector<int> &nums, int k)
    {
        n = nums.size();
        K = k;
        endstate = (1 << n) - 1;
        sort(nums.begin(), nums.end());
        ans.resize(n, 0);
        dig.resize(n, 1);
        numsmod.resize(n);
        state = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = nums[i];
            while (tmp)
            {
                dig[i] *= 10;
                tmp /= 10;
            }
            numsmod[i] = nums[i] % k;
        }
        if (run(nums, 0, 0))
            return ans;
        else
            return vector<int>();
    }
};