#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums)
    {
        nums.push_back(0);
        for (int i = nums.size() - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = -1e7;

        map<int, pair<int, long long>> prev_pos_sum;
        int cur_best = nums[0];

        vector<long long> cur_sum(nums.size(), 0);
        cur_sum[0] = nums[0];
        long long ans = nums[1];
        int base = 0;

        prev_pos_sum[nums[0]] = {0, 0};
        for (int i = 1; i < nums.size(); i++)
        {
            cur_sum[i] = cur_sum[i - 1] + nums[i];
            if (cur_sum[i] - cur_sum[base] > ans)
                ans = cur_sum[i] - cur_sum[base];
            if (nums[i] < 0)
            {
                long long value = cur_sum[i - 1] - cur_sum[base];
                if (prev_pos_sum.find(nums[i]) != prev_pos_sum.end())
                {
                    int prev_pos_tmp = prev_pos_sum[nums[i]].first;
                    long long value_tmp = prev_pos_sum[nums[i]].second + cur_sum[i - 1] - cur_sum[prev_pos_tmp];
                    if (value_tmp > value)
                    {
                        value = value_tmp;
                    }
                }
                // cout<<i<<" "<<nums[i]<<" "<<value<<" "<<base<<endl;
                prev_pos_sum[nums[i]] = {i, value};
                int best_pos = prev_pos_sum[cur_best].first;
                long long best_value = prev_pos_sum[cur_best].second + cur_sum[i] - cur_sum[best_pos];

                if (best_value < value)
                {
                    cur_best = nums[i];
                }
                if (cur_sum[i] - cur_sum[base] < 0)
                {
                    base = i;
                }
            }
            else
            {
                auto [pos, value] = prev_pos_sum[cur_best];
                value = cur_sum[i] - cur_sum[pos] + value;
                ans = max(ans, value);
            }
        }
        return ans;
    }
};