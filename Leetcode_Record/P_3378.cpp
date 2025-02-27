#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int head(int cur, vector<int> &id)
    {
        vector<int> stac;
        while (cur != id[cur])
        {
            stac.push_back(cur);
            cur = id[cur];
        }
        while (stac.size())
        {
            id[stac.back()] = cur;
            stac.pop_back();
        }
        return cur;
    }

    int countComponents(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> rec(threshold + 5, -1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= threshold && rec[nums[i]] == -1)
            {
                rec[nums[i]] = nums[i];
                if ((long long)(nums[i]) * nums[i] <= threshold)
                {
                    if (i > 0)
                        rec[nums[i]] = rec[nums[i - 1]];
                    for (int j = nums[i], l = rec[nums[i]]; j <= threshold; j += nums[i])
                    {
                        rec[j] = l;
                    }
                }
            }
        }
        // cout<<"stage 1 done\n";
        for (long long i = threshold; i * i >= threshold; i--)
        {
            int leader = -1;
            for (long long j = 1; j * j < threshold; j++)
            {
                long long v = i / j;
                if ((i % j) == 0 && rec[v] >= 0)
                {
                    int tmp = head(v, rec);
                    if (leader == -1)
                        leader = tmp;
                    else
                        rec[tmp] = leader;
                }
            }
        }
        // cout<<"stage 1 done\n";
        int ans = 0;
        set<int> heads;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > threshold)
                ans++;
            else
                heads.insert(head(nums[i], rec));
        }
        return ans + heads.size();
    }
};